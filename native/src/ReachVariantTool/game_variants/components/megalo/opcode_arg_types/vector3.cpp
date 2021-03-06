#include "vector3.h"
#include "../compiler/compiler.h"
#include "../../../helpers/numeric.h"

namespace Megalo {
   OpcodeArgTypeinfo OpcodeArgValueVector3::typeinfo = OpcodeArgTypeinfo(
      "_vector3",
      "Vector3",
      "A 3D vector indicating a position or position offset.", // TODO: for create-object, is it relative to the basis-object's axes?
      //
      OpcodeArgTypeinfo::flags::none,
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
      cobb::sprintf(temp, "%d, %d, %d", this->value.x, this->value.y, this->value.z);
      out.write(temp);
   }
   arg_compile_result OpcodeArgValueVector3::compile(Compiler& compiler, cobb::string_scanner& arg, uint8_t part) noexcept {
      if (part > 2)
         return arg_compile_result::failure();
      //
      int32_t coordinate = 0;
      if (!compiler.try_get_integer(arg, coordinate)) {
         return arg_compile_result::failure().set_needs_more(part < 2);
      }
      if (!cobb::integral_type_can_hold<int8_t>(coordinate)) {
         compiler.raise_warning(QString("Value %1 cannot be held in a signed 8-bit integer; value %2 has been stored instead.").arg(coordinate).arg((int8_t)coordinate));
      }
      switch (part) {
         case 0: this->value.x = coordinate; break;
         case 1: this->value.y = coordinate; break;
         case 2: this->value.z = coordinate; break;
      }
      //
      return arg_compile_result::success().set_needs_more(part < 2);
   }
   void OpcodeArgValueVector3::copy(const OpcodeArgValue* other) noexcept {
      auto cast = dynamic_cast<const OpcodeArgValueVector3*>(other);
      assert(cast);
      this->value = cast->value;
   }
}