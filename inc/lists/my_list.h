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
#include <ptr/ptr.h>
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
    } T##List

#define List(T) T##List 

// =================================================================
//                          Construction
// =================================================================

// Stack: List(i32) l = list_init;
#define list_init { .buffer = nullptr, .size = 0, .capacity = 0 }

// Heap: List(i32)* l = list_alloc(i32);
#define list_alloc(T) ({                            \
    List(T)* _list_ = calloc(1, sizeof(List(T)));   \
    _list_;                                         \
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

#define list_grow(list) do {                                                                    \
    auto _list_ = to_ptr(list);                                                                 \
    _list_->capacity  = _list_->capacity == 0                                                   \
                        ? _initial_list_size_                                                   \
                        : _list_->capacity * _list_growth_size_;                                \
    _list_->buffer   = realloc(_list_->buffer, sizeof(*_list_->buffer) * _list_->capacity);     \
    if(!_list_->buffer) {                                                                       \
        fprintf(stderr, "[LIST]::[ALLOCATION]::[FAILED] AT: %s:%d" endl, __FILE__, __LINE__);   \
        exit_failure;                                                                           \
}                                                                                               \
} while(0)

// =================================================================
//                          Mutation
// =================================================================

// Pre-Allocation
#define list_reserve(list, len) do {                                                            \
    auto _list_ = to_ptr(list);                                                                 \
    if((len) > _list_->capacity) {                                                              \
        _list_->buffer = realloc(_list_->buffer, sizeof(*_list_->buffer) * (len));              \
        if(!_list_->buffer) {                                                                   \
            fprintf(stderr, "[LIST]::[RESERVE]::[FAILED] AT: %s:%d" endl, __FILE__, __LINE__);  \
            exit_failure;                                                                       \
        }                                                                                       \
        _list_->capacity = (len);                                                               \
    }                                                                                           \
} while(0)

// _Push_
#define list_push(list, item) do {              \
    auto _list_ = to_ptr(list);                 \
    if(_list_->size == _list_->capacity) {      \
     list_grow(list);                           \
    }                                           \
    _list_->buffer[_list_->size++] = (item);    \
} while(0)

// _Pop_
#define list_pop(list) ({               \
    auto _list_ = to_ptr(list);         \
    _list_->buffer[--_list_->size];     \
})

// _Clear_
#define list_clear(list) do {   \
    to_ptr(list)->size = 0;     \
} while(0)

// =================================================================
//                          Destruction
// =================================================================

// Free buffer, reset fields works on stack or heap List
#define list_free(list) do {                    \
    auto _list_ = to_ptr(list);                 \
    if(_list_->buffer) {                        \
        free(_list_->buffer);                   \
        *_list_ = _null_container_(_list_);     \
       }                                        \
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
#define list_each(list, index)                          \
    for( s64 i = 0; i < to_ptr(list)->size; i++)

// Value Loop: list_foreach(list, int, x) { printf("%d" endl, x); }
#define list_foreach(list, T, var)                                              \
    for (s64 _i_ = 0, _once_ = 1; _i_ < to_ptr(list)->size; _i_++, _once_ = 1)  \
        for( T var = to_ptr(list)->buffer[_i_]; _once_; _once_ = 0)



