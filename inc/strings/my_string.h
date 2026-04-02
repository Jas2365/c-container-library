#pragma once

#include <my_ints.h>
#include <strings/my_string_defs.h>

typedef struct string {
    
    s64  length;
    i8*  str;

} string, *str_ptr;

typedef i8* string_literal;

[[nodiscard]] string String (const string_literal str);
[[nodiscard]] string nString(const string_literal str, s64 n);

[[nodiscard]] string String_share(str_ptr share_str);
[[nodiscard]] string String_copy (str_ptr copy_str);

// null print_string(string str);
