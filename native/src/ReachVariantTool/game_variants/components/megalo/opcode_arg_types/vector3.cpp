#include "vector3.h"

namespace Megalo {
   OpcodeArgTypeinfo OpcodeArgValueVector3::typeinfo = OpcodeArgTypeinfo(
      OpcodeArgTypeinfo::typeinfo_type::default,
      0,
      OpcodeArgTypeinfo::default_factory<OpcodeArgValueVector3>
   );
   //
   bool OpcodeArgValueVector3::read(cobb::ibitreader & stream, GameVariantDataMultiplayer& mp) noexcept {
      stream.read(this->value.x);
      stream.read(this->value.y);
      stream.read(this->value.z);
      return true;
   }
   void OpcodeArgValueVector3::write(cobb::bitwriter & stream) const noexcept {
      stream.write(this->value.x);
      stream.write(this->value.y);
      stream.write(this->value.z);
   }
   void OpcodeArgValueVector3::to_string(std::string & out) const noexcept {
      cobb::sprintf(out, "(%d, %d, %d)", this->value.x, this->value.y, this->value.z);
   }
   void OpcodeArgValueVector3::decompile(Decompiler& out, Decompiler::flags_t flags) noexcept {
      std::string temp;
      cobb::sprintf(temp, "(%d, %d, %d)", this->value.x, this->value.y, this->value.z);
      out.write(temp);
   }
}