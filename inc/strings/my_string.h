#pragma once

#include <my_ints.h>
#include <strings/my_string_defs.h>

typedef struct string_tag {
    
    s64  length;
    i8*  str;

} string_tag, *string;

typedef i8* string_literal;

[[nodiscard]] string String(const string_literal str);
[[nodiscard]] string nString(const string_literal str, s64 n);

[[nodiscard]] string String_copy(string str);
[[nodiscard]] string nString_copy(string str, s64 n);


null free_string(string str);
null print_string(string str);

