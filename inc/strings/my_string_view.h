#pragma once 

#include <my_string.h>

typedef struct string_view string_view;

typedef string_view* string_vw;

[[nodiscard]] string_vw String_vw(string str);

s64 get_sv_len(string_vw sv);
string get_sv_str(string_vw sv);

null free_string_vw(string_vw str);

null print_string_vw(string_vw sv);
