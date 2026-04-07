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

/**
 * TODO: Should decide to make an Arena Allocator for Arrays 
*/

// =================================================================
//                          Type Defination
// =================================================================

#define DEFINE_ARRAY(T, N)      \
    typedef struct {            \
        T buffer[N];            \
        union {                 \
            s64 size;           \
            s64 length;         \
        };                      \
        s64 capacity;           \
    } T##Array##N               

#define Array(T, N) T##Array##N

// =================================================================
//                          Construction
// =================================================================

// Stack: Array(i32, 64) a = array_init(T, N);
#define array_init(T, N) ((Array(T, N)) { .buffer = { 0 }, .size = 0, .capacity = N })

// Heap: Array(i32, 64)* l = array_alloc(i32, 64);
#define array_alloc(T, N) ({                                \
    Array(T, N)* _array_ = calloc(1, sizeof(Array(T, N) )); \
    _array_->capacity = N;                                  \
    _array_;                                                \
})
// =================================================================
//                          Defined Arrays
// =================================================================

#define _type_array_deref_(array) (__typeof__(*(to_ptr(array))))

// _Null_Array_
#define _null_array_(array) (_type_array_deref_(array)  {                                                                                       \
    .capacity   = (s64) ( sizeof(( (__typeof__(*(to_ptr(array))) *) 0)->buffer) / sizeof(( ( __typeof__(*(to_ptr(array))) *) 0)->buffer[0]))    \
})

// =================================================================
//                          List Access
// =================================================================

#define array_size(array)         (to_ptr(array)->size) 
#define array_capacity(array)     (to_ptr(array)->capacity)
#define array_buffer(array)       (to_ptr(array)->buffer)
#define array_isempty(array)      (to_ptr(array)->size == 0)
#define array_isfull(array)       (to_ptr(array)->size == to_ptr(array)->capacity)
#define array_remaining(array)    (to_ptr(array)->capacity - to_ptr(array)->size)

// unchecked for out of bounds  
// in a for loop when index is valid
#define array_get(array, index)   (to_ptr(array)->buffer[index])
#define array_first(array)        (to_ptr(array)->buffer[0])
#define array_last(array)         (to_ptr(array)->buffer[to_ptr(array)->size -1])

// checked for out of bounds
#define array_get_safe(array, index)  ({    \
    auto _array_ = to_ptr(array);           \
    s64 _i_ = (i);                          \
    _i_ < _array_->size                     \
        ? & _array_->buffer[_i_]            \
        : nullptr ;                         \
})

#define array_first_safe(array) ({          \
    auto _array_ to_ptr(array);             \
    _array_->size ? _array_->buffer[0]      \
                  :  nullptr;               \
})

#define array_last_safe(array) ({           \
    auto _array_ to_ptr(array);             \
    _array_->size                           \
    ? _array_->buffer[_array_->size -1]     \
    :  nullptr;                             \
})

// =================================================================
//                          Mutation
// =================================================================

// _Push_
#define array_push(array, item) ({                  \
    auto _array_ = to_ptr(array);                   \
    i32 _ok_ = _array_->size < _array_->capacity;   \
    if(_ok_) {                                      \
        _array_->buffer[_array_->size] = (item);    \
        _array_->size++;                            \
    }                                               \
    _ok_;                                           \
})

// _Push_And_Abort_ on full
#define array_push_assert(array, item) do {                 \
    auto _array_ = to_ptr(array);                           \
    if(_array_->size >= _array_->capacity) {                \
        fprintf(                                            \
            stderr,                                         \
            "[ARRAY]::[OVERFLOW] AT: %s:%d (cap=%zu)"endl,  \
            __FILE__,                                       \
            __LINE__,                                       \
            _array_->capacity                               \
        );                                                  \
        exit_failure;                                       \
    }                                                       \
    _array_->buffer[_array_->size++] = (item);              \
} while(0)

// _Pop_
#define array_pop(array) ({\
    auto _array = to_ptr(array);        \
    _array_->buffer[--_array_->size];   \
})

// unchecked 
// _Set_At_
#define array_set(array, index, item) do{   \
    to_ptr(array)->buffer[index] = (item);  \
} while(0)

// _Insert_
#define array_insert(array, index, item) ({                                 \
    auto _array_ = to_ptr(array);                                           \
    s64 _i_ = (index);                                                      \
    i32 _ok_ = _array_->size < _array_->capacity && _i_ <= _array_->size;   \
    if(_ok_) {                                                              \
        memmove(&_array_->buffer[_i_+1], &_array_->buffer[_i_],             \
            sizeof(*_array_->buffer) * (_array_->size - _i_)                \
        );                                                                  \
        _array_->buffer[_i_] = (item);                                      \
        _array_->size++;                                                    \
    }                                                                       \
    _ok_;                                                                   \
})

// _Remove_
#define array_remove(array, index) ({                                       \
    auto _array_ = to_ptr(array);                                           \
    s64 _i_ = (index);                                                      \
    i32 _ok_ = _array_->size < _array_->capacity && _i_ <= _array_->size;   \
    if(_ok_) {                                                              \
        memmove(&_array_->buffer[_i_], &_array_->buffer[_i_ + 1],           \
         sizeof(*_array_->buffer) * (_array_->size -_i_ -1)                 \
        );                                                                  \
        _array_->size--;                                                    \
    }                                                                       \
    _ok_;                                                                   \
})


// _Swap_Remove_ O(1)
#define array_swap_remove(array, index) ({                          \
    auto _array_ = to_ptr(array);                                   \
    s64 _i_ = (index);                                              \
    i32 _ok_ = _i_ < _array_->size;                                 \
    if(_ok_) {                                                      \
        _array_->buffer[_i_] = _array_->buffer[--_array_->size];    \
    }                                                               \
    _ok_;                                                           \
})

// _Clear_
#define array_clear(array) do {     \
    to_ptr(array)->size = 0;        \
} while(0)

// _Zero_
#define array_zero(array) do {                                                  \
    auto _array_ = to_ptr(array);                                               \
    memset(_array_->buffer, 0, sizeof(*_array_->buffer) * _array_->capacity);   \
    _array_->size = 0;                                                          \
} while(0)


// =================================================================
//                          Destruction
// =================================================================

// _Stack_Array_
#define arrya_reset(array) do {   \
    array = _null_array_(array);  \
} while(0)

// _Heap_Array_
#define array_destroy(array) do {   \
    auto _array_ = to_ptr(array);   \
    if(_array_) {                   \
        free(_array_);              \
        array = nullptr;            \
    }                               \
} while(0)

// =================================================================
//                          Iteration
// =================================================================

// _Index_Loop_
#define array_each(array, index)                                                \
    for( s64 index = 0; index < to_ptr(array)->size; index++)

// _Index_Step_Loop_
#define array_each_step(array, index, step)                                     \
    for( s64 index = 0; index < to_ptr(array)->size; index += step)

// _Value_Loop_
#define array_foreach(array, T, var)                                            \
    for( s64 _i_ = 0, _once_ = 1; _i_ < to_ptr(array)->size; _i_++, _once_ =1)  \
        for(T var = to_ptr(array)->buffer[_i_]; _once_; _once_ = 0 )


