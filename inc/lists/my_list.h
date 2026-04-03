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

#pragma once
#include <universal_macros/uni_macros.h>

// for defining
#define DEFINE_LIST(T)          \
    typedef struct {            \
        T* buffer;              \
        union {                 \
            size_t size;        \
            size_t length;      \
        };                      \
        size_t capacity;        \
    } T##List;

// when using
#define List(T) T##List 

#define list_get_size(list)       universal_access(list, size) 
#define list_get_length(list)     universal_access(list, length)
#define list_get_capacity(list)   universal_access(list, capacity)
#define list_get_buffer(list)     universal_access(list, buffer)
#define list_ptr(list)            to_ptr(list)

// universal push
#define list_push(l, item)                                      \
if((l)->size == (l)->capacity) {                                \
    (l)->capacity = (l)->capacity == 0 ? 1 : (l)->capacity * 2; \
    (l)->buffer = realloc(                                      \
                    (l)->buffer,                                \
                    sizeof(*(l)->buffer) * (l)->capacity        \
                  );                                            \
    if(!(l)->buffer) {                                          \
        fprintf(stderr, "Memory Allocation failed!" endl);      \
        exit_failure;                                           \
    }                                                           \
}                                                               \
(l)->buffer[(l)->size++] = (item);
// =================== list_push ===================


#define free_list(list)         \
    auto temp = to_ptr(list);   \
    free(temp->buffer);         \
    temp->buffer   = nullptr;   \
    temp->size     = 0;         \
    temp->capacity = 0;
    


