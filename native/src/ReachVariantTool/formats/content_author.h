#pragma once
#include <cstdint>
#include "../helpers/bitnumber.h"
#include "../helpers/bytereader.h"

class ReachContentAuthor {
   public:
      cobb::bytenumber<uint64_t> timestamp; // seconds since Jan 1 1970 midnight GMT
      cobb::bytenumber<uint64_t> xuid;
      char author[16]; // includes null terminator
      cobb::bitbool isOnlineID;
      //
      bool read(cobb::bitreader&) noexcept;
      bool read(cobb::bytereader&) noexcept;
      void write(cobb::bitwriter& stream) const noexcept;
      void write(cobb::bytewriter& stream) const noexcept;
      //
      void set_author_name(const char* s) noexcept;
      bool has_xuid() const noexcept;
      void erase_xuid() noexcept;
      void set_datetime(uint64_t seconds_since_jan_1_1970) noexcept;
};