#pragma once
#include "../opcode_arg.h"
#include "../../../helpers/strings.h"

namespace {
   using coordinate_type = int8_t;
   constexpr int coordinate_bits = cobb::bits_in<coordinate_type>;
}
namespace MegaloEx {
   namespace types {
      //
      // FUNCTOR IMPLEMENTATION NOTES:
      //
      //  - This type does not refer to any reference-tracked objects; therefore, (relObjs) will not 
      //    be modified and the (fragment) argument is not used.
      //
      OpcodeArgTypeinfo vector3 = OpcodeArgTypeinfo(
         QString("Vector3"),
         QString("A 3D vector. X and Y are the lateral axes; Z, the vertical axis."),
         OpcodeArgTypeinfo::flags::none,
         //
         [](arg_functor_state fs, OpcodeArgValue& arg, cobb::uint128_t input_bits) { // loader
            auto& data = arg.data;
            data.consume(input_bits, coordinate_bits);
            data.consume(input_bits, coordinate_bits);
            data.consume(input_bits, coordinate_bits);
            return true;
         },
         OpcodeArgTypeinfo::default_postprocess_functor,
         [](arg_functor_state fs, OpcodeArgValue& arg, std::string& out) { // to english
            auto& data   = arg.data;
            auto  offset = fs.bit_offset;
            coordinate_type x = data.excerpt(offset + coordinate_bits * 0, coordinate_bits);
            coordinate_type y = data.excerpt(offset + coordinate_bits * 1, coordinate_bits);
            coordinate_type z = data.excerpt(offset + coordinate_bits * 2, coordinate_bits);
            cobb::sprintf(out, "(%d, %d, %d)", x, y, z);
            return true;
         },
         [](arg_functor_state fs, OpcodeArgValue& arg, std::string& out) { // to script code
            auto& data   = arg.data;
            auto  offset = fs.bit_offset;
            coordinate_type x = data.excerpt(offset + coordinate_bits * 0, coordinate_bits);
            coordinate_type y = data.excerpt(offset + coordinate_bits * 1, coordinate_bits);
            coordinate_type z = data.excerpt(offset + coordinate_bits * 2, coordinate_bits);
            cobb::sprintf(out, "(%d, %d, %d)", x, y, z);
            return true;
         },
         nullptr // TODO: "compile" functor
      );
   }
}