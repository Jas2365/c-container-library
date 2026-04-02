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
string nString(const string_literal str, s64 n) {
    if(!str) return nullptr;
    
    string st = (string)malloc((sizeof(string_tag)) + n);
    if(!st) return nullptr;
    st->length = n;

    if(st->str) {
        memcpy(st->str, str, st->length);
    } 

    return st;
}


string String_copy(string str) {
    if(!str) return nullptr;

    string st = (string)malloc((sizeof(string_tag)) + str->length);
    if(!st) return nullptr;
    st->length = str->length;

    if(st->str) {
        memcpy(st->str, str->str, st->length);
    } 

    return st;
}
string nString_copy(string str, s64 n) {
    if(!str) return nullptr;

    string st = (string)malloc((sizeof(string_tag)) + n);
    if(!st) return nullptr;
    st->length = n;

    if(st->str) {
        memcpy(st->str, str->str, st->length);
    }

    return st;
}

null free_string(string str) {
    if(str) {
        free(str);
        str = nullptr;
    }
}

null print_string(string str) {
    if(!str) return;
    fwrite(str->str, sizeof(i8), str->length, stdout);
}
