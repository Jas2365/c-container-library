#include <my_string_view.h>

#include <stdlib.h>
#include <stdio.h>

struct string_view {
    
    s64 length;
    string str;
};

string_view String_View(string str){

    return (string_view) {
        .length = get_str_len(str),
        .str    = str
    };

}

string_vw String_vw(string str){

    string_vw str_vw = (string_vw)malloc(sizeof(string_view));
    str_vw->length   = get_str_len(str);
    str_vw->str      = str;
        
    return str_vw;

}


s64 get_sv_len(string_vw sv){

    return sv->length;

}
string get_sv_str(string_vw sv){

    return sv->str;

}

null free_string_vw(string_vw str){

    if(str) free(str);
    str = nullptr;

}

null print_string_vw(string_vw sv) {
    fwrite(sv->str, sizeof(i8), sv->length, stdout);
}