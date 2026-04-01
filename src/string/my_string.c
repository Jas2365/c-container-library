#include <my_string.h>

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <my_defs.h>

#define get_string_tag(str) ( (string_tag*) ( (i8*)(str) - offsetof(string_tag, str) ) )

string String(const string_literal str) {
    if(!str) return nullptr;

    s64 len = strlen(str);

    string st = (string)malloc((sizeof(string_tag)) + len);
    if(!st) return nullptr;
    
    st->length = len;

    if(st->str) {
        memcpy(st->str, str, st->length);
    } 

    return st;
}
string nString(const string_literal str, s64 len) {
    if(!str) return nullptr;

    // s64 len = strlen(str);           this is the only difference between nString and String

    string st = (string)malloc((sizeof(string_tag)) + len);
    if(!st) return nullptr;
    st->length = len;

    if(st->str) {
        memcpy(st->str, str, st->length);
    } 

    return st;
}

// string_tag* String_Tag(const string_literal str) {

//     if(!str) return nullptr;

//     s64 len = strlen(str);

//     string_tag* s = (string_tag*)malloc((sizeof(string_tag)) + len);
//     if(!s) return nullptr;
//     s->length = len;

//     if(s->str) {
//         memcpy(s->str, str, s->length);
//     } 

//     return s;
// }

null free_string(string str) {
    if(str) {
        free(str);
        str = nullptr;
    }
}

string_tag *get_str_tag(string str) {
    if(!str) return nullptr;
    return get_string_tag(str);
}

s64 get_str_len(string str) {
    if(!str) return VOID;
    return get_string_tag(str)->length;
}

null print_string(string str) {
    if(!str) return;    
    fwrite(str, sizeof(i8), get_str_len(str), stdout);
}
