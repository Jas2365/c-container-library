#pragma once

#include <my_ints.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_tag {
    u64 length;
    i8  data[];
} string_tag;

typedef i8* string;

typedef struct string_view {
    u64 length;
    ci8* ptr;
}string_view;

[[nodiscard]] string String(ci8* str) {
    if(!str) return NULL;

    u32 len = strlen(str);

    string_tag* s = (string_tag*)malloc((sizeof(string_tag)) + len);
    if(!s) return NULL;
    s->length = len;

    if(s->data) {
        memcpy(s->data, str, s->length);
    } 

    return s->data;
}
[[nodiscard]] string_tag* String_Tag(ci8* str) {
    if(!str) return NULL;

    u32 len = strlen(str);

    string_tag* s = (string_tag*)malloc((sizeof(string_tag)) + len);
    if(!s) return NULL;
    s->length = len;

    if(s->data) {
        memcpy(s->data, str, s->length);
    } 

    return s;
}

#define get_string_tag(str) ( (string_tag*) ( (i8* ) str - offsetof(string_tag, data) ) )
#define fmt_str "%.*s"

#define arg_str(s) (get_string_tag((s))->length), (s)

void free_string(string s) {
    if(s) {
        free(get_string_tag(s));
    }
}

s64 get_len(string s) {
    return get_string_tag(s)->length;
}
