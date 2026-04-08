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

// =================================================================
//                          Type Defination
// =================================================================

#define DEFINE_NODE(T)          \
    typedef struct T##Node {    \
        T node_val;             \
        p64  zored;             \
    }T##Node

#define Node(T) T##Node

#define DEFINE_ITERATOR(T)          \
    typedef struct T##Iterator {    \
        Node(T)*    curr;           \
        p64         prev;           \
    } T##Iterator

#define Iterator(T) T##Iterator

#define DEFINE_LINKED_LIST(T)       \
    DEFINE_NODE(T);                 \
    DEFINE_ITERATOR(T);             \
    typedef struct T##LinkedList {  \
        Node(T)* begin_node;        \
        Node(T)* end_node;          \
        union {                     \
            s64 size;               \
            s64 length;             \
        };                          \
        Iterator(T) iter;           \
        Iterator(T) riter;          \
    }T##LinkedList

#define LINKED_LIST(T) T##LinkedList 

// =================================================================
//                          Construction
// =================================================================

// Stack
#define linkedlist_init(T) {                                \
    .begin_node = (Node(T)*)nullptr,                        \
    .end_node   = (Node(T)*)nullptr,                        \
    .size       = 0,                                        \
    .iter       = {.curr = (Node(T)*)nullptr, .prev = 0},   \
    .riter      = {.curr = (Node(T)*)nullptr, .prev = 0},   \
}

// Heap
#define linkedlist_alloc(T) ({                                          \
    LINKED_LIST(T) _linked_list_ = calloc(1, sizeof(LINKED_LIST(T)));   \
    _linked_list_;                                                      \
})

#define node_create(T, val) ({                      \
    auto _val_          = to_ptr(val);              \
    Node(T)* _node_     = malloc(sizeof(Node(T)));  \
    _node_->node_val    = *_val_;                   \
    _node_->zored       = 0;                        \
    _node_;                                         \
})


// =================================================================
//                          Mutation
// =================================================================

// _Append_Begin_
#define linkedlist_append_begin(linked_list, T, val) do {                           \
    auto _linked_list_ = to_ptr(linked_list);                                       \
    auto _node_ = node_create(T, val);                                              \
    (                                                                               \
        _linked_list_->begin_node == nullptr                                        \
    )                                                                               \
    ?                                                                               \
        (                                                                           \
            _linked_list_ -> end_node   = _node_,                                   \
            _linked_list_ -> iter.curr  = _node_,                                   \
            _linked_list_ -> riter.curr = _node_,                                   \
            _linked_list_ -> begin_node = _node_                                    \
        )                                                                           \
    :                                                                               \
        (                                                                           \
            _node_->zored                     = (p64)_linked_list_->begin_node,     \
            _linked_list_->begin_node->zored ^= (p64)_node_,                        \
            _linked_list_->begin_node         = _node_,                             \
            _linked_list_->iter.curr          = _node_                              \
        )                                                                           \
    ;                                                                               \
    _linked_list_->size++;                                                          \
} while(0)
    
// _Append_End_
#define linkedlist_append_end(linked_list, T, val) do {                             \
    auto _linked_list_ = to_ptr(linked_list);                                       \
    auto _node_ = node_create(T, val);                                              \
    (                                                                               \
        (_linked_list_->end_node   == nullptr)                                      \
                        &&                                                          \
        (_linked_list_->begin_node == nullptr)                                      \
    )                                                                               \
    ?                                                                               \
        (                                                                           \
            _linked_list_ -> end_node   = _node_,                                   \
            _linked_list_ -> iter.curr  = _node_,                                   \
            _linked_list_ -> riter.curr = _node_,                                   \
            _linked_list_ -> begin_node = _linked_list_ -> end_node                 \
        )                                                                           \
    :                                                                               \
        (                                                                           \
            _node_        -> zored                = (p64)_linked_list_->end_node,   \
            _linked_list_ -> end_node -> zored   ^= (p64)_node_,                    \
            _linked_list_ -> end_node             = _node_,                         \
            _linked_list_ -> riter.curr           = _node_                          \
        )                                                                           \
    ;                                                                               \
    _linked_list_->size++;                                                          \
} while(0)

// =================================================================
//                          Destruction
// =================================================================

// _Stack_Linked_List_
#define linkedlist_free(linkedlist)

// _Heap_Linked_List_

// =================================================================
//                          Iteration
// =================================================================

// it++
// for(Iterator(st) it = ss.iter ; it.curr; Iter_Next(it)) {}
#define Iter_Next(it) ({                                                \
   auto _it_   = to_ptr(it);                                            \
   auto _next_ =                                                        \
    (__typeof__(_it_->curr)) ((p64)(_it_->curr->zored) ^ (_it_->prev)); \
    _it_->prev  = (p64)_it_->curr;                                      \
    _it_->curr  = _next_;                                               \
})



