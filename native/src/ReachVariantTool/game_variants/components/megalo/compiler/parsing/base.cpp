#include "base.h"

namespace Megalo {
   namespace Script {
      void ParsedItem::set_start(const cobb::string_scanner::pos& pos) {
         this->line = pos.line;
         this->col  = pos.offset - pos.last_newline;
         this->range.start = pos.offset;
      }
      void ParsedItem::set_end(const cobb::string_scanner::pos& pos) {
         this->range.end = pos.offset;
      }
   }
}