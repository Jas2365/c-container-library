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

#define _initial_stack_size_   ( 8 )
#define _stack_growth_size_    ( 2 )

// =================================================================
//                          Type Defination
// =================================================================

#define DEFINE_STACK(T)  \
    typedef struct {     \
        T* buffer;       \
        union {          \
            s64 size;    \
            s64 length;  \
        };               \
        s64 capacity;    \
    } T##Stack

#define Stack(T) T##Stack

// =================================================================
//                          Construction
// =================================================================

// Stack: Stack(i32) s = stack_init;
#define stack_init {.buffer = nullptr, .index = 0, .capacity = 0}

// Heap: Stack(i32)* s = stack_alloc(i32);
#define stack_alloc(T) ({                               \
    Stack(T)* _stack_ = calloc(1, sizeof(Stack(T)));    \
    _stack_;                                            \
})

// =================================================================
//                          Defined Stacks
// =================================================================

// _Null_Stack_
#define _null_stack_(stack) ( (__typeof__(*(to_ptr(stack)))) stack_init )

#include <my_ints.h>
// _Signed_Integer_Stack_
DEFINE_STACK(i8);
DEFINE_STACK(i16);
DEFINE_STACK(i32);
DEFINE_STACK(i64);

// _Unsigned_Integer_Stack_
DEFINE_STACK(u8);
DEFINE_STACK(u16);
DEFINE_STACK(u32);
DEFINE_STACK(u64);

// _Floating_Stack_
DEFINE_STACK(f32);
DEFINE_STACK(f64);

// =================================================================
//                          Stack Access
// =================================================================

#define stack_size(stack)           (to_ptr(stack)->size)
#define stack_capacity(stack)       (to_ptr(stack)->capacity)
#define stack_buffer(stack)         (to_ptr(stack)->buffer)
#define stack_isempty(stack)        (to_ptr(stack)->size == 0)

// =================================================================
//                          Growth Helper
// =================================================================

//_Grow_
#define stack_grow(stack) do {                                                                   \
    auto _stack_ = to_ptr(stack);                                                                \
    _stack_->capacity  = _stack_->capacity == 0                                                  \
                        ? _initial_stack_size_                                                   \
                        : _stack_->capacity * _stack_growth_size_;                               \
    _stack_->buffer   = realloc(_stack_->buffer, sizeof(*_stack_->buffer) * _stack_->capacity);  \
    if(!_stack_->buffer) {                                                                       \
        fprintf(stderr, "[STACK]::[ALLOCATION]::[FAILED] AT: %s:%d" endl, __FILE__, __LINE__);   \
        exit_failure;                                                                            \
    }                                                                                            \
} while(0)

// =================================================================
//                          Mutation
// =================================================================

// _Push_
#define stack_push(stack, item) do {                \
    auto _stack_ = to_ptr(stack);                   \
    if(_stack_->size == _stack_->capacity) {        \
        stack_grow(stack);                          \
    }                                               \
    _stack_->buffer[_stack_->size++] = (item);      \
} while(0)

// _Pop_
#define stack_pop(stack) ({             \
    auto _stack_ = to_ptr(stack);       \
    _stack_->buffer[--_stack_->size];   \
})

// _Pop_And_Abort_ on null
#define stack_pop_assert(stack) ({                  \
    auto _stack_ = to_ptr(stack);                   \
    if(_stack_->size <= 0) {                        \
        fprintf(                                    \
            stderr,                                 \
            "[STACK]::[UNDERFLOW] AT: %s:%d"endl,   \
            __FILE__,                               \
            __LINE__                                \
        );                                          \
        exit_failure;                               \
    }                                               \
    _stack_->buffer[--_stack_->size];               \
})

// _Clear_
#define stack_clear(stack) do { \
    to_ptr(stack)->size = 0;    \
} while(0)

// =================================================================
//                          Destruction
// =================================================================

// _Stack_Stack_
#define stack_free(stack) do {          \
    auto _stack_ = to_ptr(stack);       \
    if(_stack_->buffer) [               \
        free(_stack_->buffer);          \
        stack = _null_stack_(_stack_);  \
    ]                                   \
} while(0)

// _Heap_Stack_
#define stack_destroy(stack) do {       \
    auto _stack_ = to_ptr(stack);       \
    if(_stack_) {                       \
        if(_stack_->buffer) {           \
            free(_stack_->buffer);      \
        }                               \
        free(_stack_);                  \
        stack = nullptr;                \
    }                                   \
} while(0)


