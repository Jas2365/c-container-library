#include <my_string.h>

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <my_defs.h>


struct string_tag {
    
    s64 length;
    i8  data[];
};

#define get_string_tag(str) ( (string_tag*) ( (i8*)(str) - offsetof(string_tag, data) ) )

string String(const string str) {
    if(!str) return nullptr;

    s64 len = strlen(str);

    string_tag* st = (string_tag*)malloc((sizeof(string_tag)) + len);
    if(!st) return nullptr;
    st->length = len;

    if(st->data) {
        memcpy(st->data, str, st->length);
    } 

    return st->data;
}
string nString(const string str, s64 len) {
    if(!str) return nullptr;

    // s64 len = strlen(str);           this is the only difference between nString and String

    string_tag* st = (string_tag*)malloc((sizeof(string_tag)) + len);
    if(!st) return nullptr;
    st->length = len;

    if(st->data) {
        memcpy(st->data, str, st->length);
    } 

    return st->data;
}
string_tag* String_Tag(const string str) {

    if(!str) return nullptr;

    s64 len = strlen(str);

    string_tag* s = (string_tag*)malloc((sizeof(string_tag)) + len);
    if(!s) return nullptr;
    s->length = len;

    if(s->data) {
        memcpy(s->data, str, s->length);
    } 

    return s;
}

null free_string(string str) {
    if(str) {
        free(get_str_tag(str));
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
