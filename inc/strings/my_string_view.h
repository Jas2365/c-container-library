#pragma once 

#include <my_string.h>

typedef struct string_view {

    s64 length;
    string_literal str;

}string_view, *string_vw;
 
[[nodiscard]] string_view  String_View   (str_ptr str);
[[nodiscard]] string_view  nString_View  (str_ptr str, s64 n);

[[nodiscard]] string_view  String_View_literal   (string_literal str);
[[nodiscard]] string_view  nString_View_literal  (string_literal str, s64 n);

null print_string_vw(string_vw sv);

null sv_chop_left (string_vw sv, s64 n);
null sv_chop_right(string_vw sv, s64 n);

null sv_trim_left (string_vw sv);
null sv_trim_right(string_vw sv);
null sv_trim      (string_vw sv);

string_view sv_chop_by_delim(string_vw sv, i8 delim);
