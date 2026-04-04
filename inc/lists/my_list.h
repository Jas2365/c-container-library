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
#include <my_list_config.h>

// =================================================================
//                          Type Defination
// =================================================================

#define DEFINE_LIST(T)      \
    typedef struct {        \
        T* buffer;          \
        union {             \
            s64 size;       \
            s64 length;     \
        };                  \
        s64 capacity;       \
    } T##List;

#define List(T) T##List 


// =================================================================
//                          Defined Lists
// =================================================================

// no defined list for now 
// would be made for null List or null List*

// =================================================================
//                          Construction
// =================================================================

// Stack: List(i32) l = list_init;
#define list_init { .buffer = nullptr, .size = 0, .capacity = 0 }

// Heap: List(i32)* l = list_alloc(i32);
#define list_alloc(T) ({                                \
    List(T)* __list__ = calloc(1, sizeof(List(T)));     \
    __list__;                                           \
})

// =================================================================
//                          List Access
// =================================================================

#define list_size(list)         (to_ptr(list)->size) 
#define list_capacity(list)     (to_ptr(list)->capacity)
#define list_buffer(list)       (to_ptr(list)->buffer)
#define list_isempty(list)      (to_ptr(list)->size == 0)
#define list_get(list, index)   (to_ptr(list)->buffer[index])
#define list_last(list)         (to_ptr(list)->buffer[to_ptr(list)->size -1])


// =================================================================
//                          Growth Helper
// =================================================================

#define list_grow(list) do {                                                                        \
    auto __list__ = to_ptr(list);                                                                   \
    __list__->capacity  = __list__->capacity == 0                                                   \
                        ? __initial_list_size__                                                     \
                        : __list__->capacity * __list_growth_size__;                                \
    __list__->buffer   = realloc(__list__->buffer, sizeof(*__list__->buffer) * __list__->capacity); \
    if(!__list__->buffer) {                                                                         \
        fprintf(stderr, "[LIST]::[ALLOCATION]::[FAILED] AT: %s:%d" endl, __FILE__, __LINE__);       \
        exit_failure;                                                                               \
}                                                                                                   \
} while(0)

// =================================================================
//                          Mutation
// =================================================================

// Pre-Allocation
#define list_reserve(list, len) do {                                                            \
    auto __list__ = to_ptr(list);                                                               \
    if((len) > __list__->capacity) {                                                            \
        __list__->buffer = realloc(__list__->buffer, sizeof(*__list__->buffer) * (len));        \
        if(!__list__->buffer) {                                                                 \
            fprintf(stderr, "[LIST]::[RESERVE]::[FAILED] AT: %s:%d" endl, __FILE__, __LINE__);  \
            exit_failure;                                                                       \
        }                                                                                       \
        __list__->capacity = (len);                                                             \
    }                                                                                           \
} while(0)

// __Push__
#define list_push(list, item) do {                  \
    auto __list__ = to_ptr(list);                   \
    if(__list__->size == __list__->capacity) {      \
     list_grow(list);                               \
    }                                               \
    __list__->buffer[__list__->size++] = (item);    \
} while(0)

// __Pop__
#define list_pop(list) ({               \
    auto __list__ = to_ptr(list);       \
    __list__->buffer[--__list__->size]; \
})

// __Clear__
#define list_clear(list) do {   \
    to_ptr(list)->size = 0;     \
} while(0)

// =================================================================
//                          Destruction
// =================================================================

// Free buffer, reset fields works on stack or heap List
#define list_free(list) do {        \
    auto __list__ = to_ptr(list);   \
    if(__list__->buffer) {          \
        free(__list__->buffer);     \
        __list__->buffer = nullptr; \
        __list__->size = 0;         \
        __list__->capacity = 0;     \
    }                               \
} while(0)

// Free buffer + the heap allocated List itself
#define list_destroy(list) do {     \
    if(list) {                      \
        list_free(list);            \
        free(list);                 \
        list = nullptr;             \
    }                               \
} while(0)

// =================================================================
//                          Iteration
// =================================================================

// Index Loop: list_each(list, index) { printf("%d" endl, list_get(l, index)); }
#define list_each(list, index)                                                              \
    for( s64 i = 0; i < to_ptr(list)->size; i++)

// Value Loop: list_foreach(list, int, x) { printf("%d" endl, x); }
#define list_foreach(list, T, var)                                                          \
    for (s64 __i__ = 0, __once__ = 1; __i__ < to_ptr(list)->size; __i__++, __once__ = 1)    \
        for( T var = to_ptr(list)->buffer[__i__]; __once__; __once__ = 0)



