#include <my_string_view.h>

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string_view String_View(string str){

    return (string_view) {
        .length = str->length,
        .str    = str->str
    };

}
string_view nString_View(string str, s64 n){

    return (string_view) {
        .length = n,
        .str    = str->str
    };

}

string_vw String_vw(string str){

    string_vw str_vw = (string_vw)malloc(sizeof(string_view));
    str_vw->length   = str->length;
    str_vw->str      = str->str;        
    return str_vw;

}

string_vw nString_vw(string str, s64 n){
    
    string_vw str_vw = (string_vw)malloc(sizeof(string_view));
    str_vw->length   = n;
    str_vw->str      = str->str;        
    return str_vw;

}

string_view String_View_literal(string_literal str){
    return (string_view) {
        .length = strlen(str),
        .str    = str
    };

}
string_view nString_View_literal(string_literal str, s64 n){
    return (string_view) {
        .length = n,
        .str    = str
    };
}
string_vw String_vw_literal(string_literal str){
    string_vw str_vw = (string_vw)malloc(sizeof(string_view));
    str_vw->length   = strlen(str);
    str_vw->str      = str;        
    return str_vw;

}
string_vw nString_vw_literal(string_literal str, s64 n){    
    string_vw str_vw = (string_vw)malloc(sizeof(string_view));
    str_vw->length   = n;
    str_vw->str      = str;        
    return str_vw;
}

s64 get_sv_len(string_vw sv){
    return sv->length;
}
string_literal get_sv_str(string_vw sv){
    return sv->str;
}

null free_string_vw(string_vw str){
    if(str) free(str);
    str = nullptr;
}

null print_string_vw(string_vw sv) {
    fwrite(sv->str, sizeof(i8), sv->length, stdout);
}

null sv_chop_right(string_vw sv, s64 n) {
    if(n > sv->length) n = sv->length;
    sv->length -= n;
}

null sv_chop_left(string_vw sv, s64 n) {
    if(n > sv->length) n = sv->length;
    sv->length -= n;
    sv->str    += n;

}

null sv_trim_left(string_vw sv) {
    s64 len = 0;
    while(sv->length > 0 && isspace(sv->str[len])) {
        len += 1;
    }
    sv_chop_left(sv, len);

}

null sv_trim_right(string_vw sv) {
    s64 len = 0;
    while(sv->length > 0 && isspace(sv->str[sv->length -len -1])) {
        len += 1;
    }
    sv_chop_right(sv, len);
}

null sv_trim(string_vw sv) {
    sv_trim_left(sv);
    sv_trim_right(sv);
}

string_view sv_chop_by_delim(string_vw sv, i8 delim) {
    s64 i = 0; 

    while(i < sv->length && sv->str[i] != delim) {
        i++;
    }
    
    if(i < sv->length) {
        string_view res = nString_View_literal(sv->str, i);
        sv_chop_left(sv, i + 1);
        return res;
    }

    string_view res = *sv;
    sv_chop_left(sv, sv->length);
    return res;
}

string_vw sv_chop_by_delim_ptr(string_vw sv, i8 delim) {
    s64 i = 0; 

    while(i < sv->length && sv->str[i] != delim) {
        i++;
    }
    
    if(i < sv->length) {
        string_vw res = nString_vw_literal(sv->str, i);
        sv_chop_left(sv, i + 1);
        return res;
    }

    string_vw res = sv;
    sv_chop_left(sv, sv->length);
    return res;
}
