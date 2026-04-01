#pragma once

#include <my_ints.h>
#include <strings/my_string_defs.h>

typedef struct string_tag string_tag;
typedef i8* string;

[[nodiscard]] string String(const string str);
[[nodiscard]] string nString(const string str, s64 len);
[[nodiscard]] string_tag* String_Tag(const string str);

null free_string(string str);

string_tag* get_str_tag(string str);
s64 get_str_len(string str);

null print_string(string str);

