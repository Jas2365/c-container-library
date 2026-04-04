/*
 * Copyright 2026 Jas2365
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
 * OR CONDITIONS OF ANY KIND, either express or implied.
 */

#include <my_string.h>
#include <my_defs.h>
#include <my_string_arena.h>

#include <string.h>  // memcpy, strlen


string String(const string_literal str) {
    if(!str) return null_string;
    
    string result = {
        .length = strlen(str),
        .str = Arena_Push(result.length),
    };
    if(!result.str) return null_string;
    memcpy(result.str, str, result.length);
    
    return result;
}

string nString(const string_literal str, s64 n) {
    if(!str) return null_string;
    
    string result = {
        .length = n,
        .str = Arena_Push(n),
    };
    if(result.str) return null_string;
    memcpy(result.str, str, result.length); 

    return result;
}

string String_share(str_ptr share_str) {
    if(!share_str->str || share_str->length == 0) return null_string;

    return (string) {
        .length = share_str->length,
        .str    = share_str->str,
    };

}

string String_copy(str_ptr copy_str) {
    if(!copy_str->str || copy_str->length == 0) return null_string;
    
    string result = {
        .length = copy_str->length,
        .str = Arena_Push(copy_str->length),
    };
    if(!result.str) return null_string;
    memcpy(result.str, copy_str->str, result.length);
    
    return result;
}
