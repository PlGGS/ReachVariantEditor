#include "localized_string_table.h"
extern "C" {
   #include "../../zlib/zlib.h" // interproject ref
}

#define MEGALO_STRING_TABLE_TRY_MIMIC_ORIGINAL_COMPRESSION 1

void ReachString::read_offsets(cobb::bitstream& stream, ReachStringTable& table) noexcept {
   for (size_t i = 0; i < this->offsets.size(); i++) {
      bool has = stream.read_bits(1) != 0;
      if (has)
         this->offsets[i] = stream.read_bits(table.offset_bitlength);
      else
         this->offsets[i] = -1;
   }
}
void ReachString::read_strings(void* buffer) noexcept {
   for (size_t i = 0; i < this->offsets.size(); i++) {
      auto off = this->offsets[i];
      if (off == -1)
         continue;
      this->strings[i].assign((const char*)((std::uintptr_t)buffer + off));
   }
}
void ReachString::write_offsets(cobb::bitwriter& stream, const ReachStringTable& table) const noexcept {
   for (auto offset : this->offsets) {
      if (offset == -1) {
         stream.write(0, 1);
         continue;
      }
      stream.write(1, 1);
      stream.write(offset, table.offset_bitlength);
   }
}
void ReachString::write_strings(std::string& out) const noexcept {
   #if MEGALO_STRING_TABLE_TRY_MIMIC_ORIGINAL_COMPRESSION == 1
      bool allEqual = true;
      for (size_t i = 1; i < this->offsets.size(); i++) {
         auto& a = this->strings[i - 1];
         auto& b = this->strings[i];
         if (a != b) {
            allEqual = false;
            break;
         }
      }
      if (allEqual) {
         for (auto& offset : this->offsets)
            offset = 0;
         out += this->strings[0];
         out += '\0';
         return;
      }
   #endif
   for (size_t i = 0; i < this->offsets.size(); i++) {
      auto& s = this->strings[i];
      if (s.empty()) {
         this->offsets[i] = -1;
         continue;
      }
      #if MEGALO_STRING_TABLE_TRY_MIMIC_ORIGINAL_COMPRESSION != 1
         if (i > 0) {
            //
            // If two consecutive strings are identical, have them overlap.
            //
            // TODO: Make all identical strings across the string table overlap
            //
            auto& l = this->strings[i - 1];
            if (s == l) {
               this->offsets[i] = this->offsets[i - 1];
               continue;
            }
         }
      #endif
      this->offsets[i] = out.size();
      out += s;
      out += '\0';
   }
}

void* ReachStringTable::_make_buffer(cobb::bitstream& stream) const noexcept {
   uint32_t uncompressed_size = stream.read_bits(this->buffer_size_bitlength);
   bool     is_compressed     = stream.read_bits(1) != 0;
   uint32_t size = uncompressed_size;
   if (is_compressed)
      size = stream.read_bits(this->buffer_size_bitlength);
   //
   void* buffer = malloc(size);
   for (uint32_t i = 0; i < size; i++)
      *(uint8_t*)((std::uintptr_t)buffer + i) = stream.read_bits<uint8_t>(8);
   if (is_compressed) {
      //
      // The buffer has four bytes indicating the length of the decompressed data, which is 
      // redundant. We'll read those four bytes just as a sanity check, but we need to skip 
      // them -- zlib needs to receive (buffer + 4) as its input.
      //
      uint32_t uncompressed_size_2 = *(uint32_t*)(buffer);
      if (uncompressed_size_2 != uncompressed_size)
         if (_byteswap_ulong(uncompressed_size_2) != uncompressed_size)
            printf("WARNING: String table sizes don't match: Bungie 0x%08X versus zlib 0x%08X.", uncompressed_size, uncompressed_size_2);
      void* final = malloc(uncompressed_size);
      //
      // It's normally pointless to check that an allocation succeeded because if it didn't, 
      // that means you're out of memory and there's basically nothing you can do about that 
      // anyway. However, if we screwed up and misread the size, then we may try to allocate 
      // a stupidly huge amount of memory. In that case, allocation will (hopefully) fail and 
      // (final) will be nullptr, and that's worth handling.
      //
      if (final) {
         Bytef* input = (Bytef*)((std::uintptr_t)buffer + sizeof(uncompressed_size_2));
         int resultCode = uncompress((Bytef*)final, (uLongf*)&uncompressed_size_2, input, size - sizeof(uncompressed_size_2));
         if (Z_OK != resultCode) {
            free(final);
            final = nullptr;
            printf("Failed to decompress zlib stream. Failure code was %d.\n", resultCode);
         }
      }
      free(buffer);
      buffer = final;
   }
   return buffer;
}
void ReachStringTable::read(cobb::bitstream& stream) noexcept {
   size_t count = stream.read_bits(this->count_bitlength);
   this->strings.resize(count);
   for (size_t i = 0; i < count; i++)
      this->strings[i].read_offsets(stream, *this);
   if (count) {
      auto buffer = this->_make_buffer(stream);
      if (buffer) {
         for (size_t i = 0; i < count; i++)
            this->strings[i].read_strings(buffer);
         free(buffer);
      }
   }
}
void ReachStringTable::write(cobb::bitwriter& stream) const noexcept {
   stream.write(this->strings.size(), this->count_bitlength);
   if (this->strings.size()) {
      std::string combined; // UTF-8 buffer holding all string data including null terminators
      for (auto& string : this->strings) {
         string.write_strings(combined);
         string.write_offsets(stream, *this);
      }
      uint32_t uncompressed_size = combined.size();
      if (uncompressed_size > cobb::bitmax(this->buffer_size_bitlength)) {
         printf("WARNING: TOTAL STRING DATA IS TOO LARGE");
         __debugbreak();
         assert(false && "String table cannot hold data this large");
      }
      stream.write(uncompressed_size, this->buffer_size_bitlength);
      //
      bool should_compress = uncompressed_size >= 0x80; // TODO: better logic
      stream.write(should_compress, 1);
      if (should_compress) {
         auto bound = compressBound(uncompressed_size);
         auto buffer = malloc(bound);
         if (!buffer) {
            printf("WARNING: FAILED TO ALLOCATE STORAGE FOR COMPRESSED STRING DATA!");
            __debugbreak();
            assert(false && "Insufficient memory to compress string data.");
         }
         uint32_t compressed_size = bound;
         int result = compress((Bytef*)buffer, (uLongf*)&compressed_size, (const Bytef*)combined.data(), uncompressed_size);
         switch (result) {
            case Z_OK:
               break;
            case Z_MEM_ERROR:
               assert(false && "Memory error occurred when trying to compress string table.\n");
               break;
            case Z_BUF_ERROR:
               assert(false && "Insufficient buffer space when trying to compress string table.\h");
               break;
         }
         stream.write(compressed_size, this->buffer_size_bitlength);
         stream.write(uncompressed_size, this->buffer_size_bitlength);
         for (size_t i = 0; i < compressed_size; i++)
            stream.write(*(uint8_t*)((std::intptr_t)buffer + i));
         free(buffer);
      } else {
         for (size_t i = 0; i < uncompressed_size; i++)
            stream.write((uint8_t)combined[i]);
      }
   }
}