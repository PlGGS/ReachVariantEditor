#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace cobb {
   namespace xml {
      enum class token_code  {
         undefined,
         attribute,
         element_open,
         element_close,
         text_content,
      };
      struct token {
         token(uint32_t line, token_code a) : line(line), code(a) {};
         token(uint32_t line, token_code a, float b, const char* c, const char* d) : line(line), code(a), number(b), name(c), value(d) {};

         uint32_t   line   = 0;
         token_code code   = token_code::undefined;
         float      number = 0.0F;
         std::string name;
         std::string value;
      };
      //
      struct document {
         struct custom_entity {
            std::string entity; // "&name;"
            std::string substitution;
            //
            custom_entity(const char* a, const char* b) : entity(a), substitution(b) {};
         };
         struct error {
            static constexpr int32_t no_line_number = -1;
            static constexpr int32_t no_col_number  = -1;
            //
            int32_t line = -1;
            int32_t col  = -1;
            std::string text;
            //
            error() {}
            error(std::string t, int32_t l = -1, int32_t c = -1) : text(t), line(l), col(c) {}
         };
         //
         std::vector<token>         tokens;
         std::vector<custom_entity> entities;
         bool case_insensitive = false;
         bool is_fragment      = false; // if true, then we don't require there to be only one root node
         bool strip_whitespace = false;
         bool allow_html       = false; // allows an HTML doctype
         std::vector<error> errors;

         void clear(); // for looping over multiple files, it's better to create one XMLDocument outside of the loop and clear it every iteration; that way, you only need to configure it once
         void define_entity(const char* entity, const char* substitution);

         int32_t find_element(const char* tagname) const; // returns index of the element_open token
         void element_content_to_string(uint32_t index, std::string& out);
         const char* root_node_name() const;

         //
         // Used by the parser:
         //
         void add_element_start(uint32_t line, std::string& tagName); // uses std::swap to take ownership of the string
         void add_element_end(uint32_t line, std::string& tagName); // uses std::swap to take ownership of the string
         void add_element_attribute(uint32_t line, std::string& name, std::string& value); // uses std::swap to take ownership of the strings
         void add_text_content(uint32_t line, std::string& textContent); // uses std::swap to take ownership of the string
         void log_error(std::string text, int32_t line = -1, int32_t col = -1);
         void log_formatted_error(std::string text, int32_t line, int32_t col, ...);
      };
      //
      bool parse(document& doc, std::string content);
   }
};