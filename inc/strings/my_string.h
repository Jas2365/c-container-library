#pragma once

#include <my_ints.h>
#include <strings/my_string_defs.h>



typedef struct string_tag {
    
    s64 length;
    i8  str[];

} string_tag, *string;

typedef i8* string_literal;

[[nodiscard]] string String(const string_literal str);
[[nodiscard]] string nString(const string_literal str, s64 len);
// [[nodiscard]] string_tag* String_Tag(const string_literal str);

null free_string(string str);

string_tag* get_str_tag(string str);
s64 get_str_len(string str);

null print_string(string str);

