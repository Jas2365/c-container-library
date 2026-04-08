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

#define DEFINE_NODE(T)          \
    typedef struct T##Node {    \
        T node_val;             \
        p64  zored;             \
    }T##Node

#define Node(T) T##Node

#define DEFINE_LINKED_LIST(T)       \
    typedef struct T##LinkedList {  \
        Node(T)* begin_node;        \
        Node(T)* end_node;          \
        union {                     \
            s64 size;               \
            s64 length;             \
        };                          \
    }T##LinkedList

#define LINKED_LIST(T) T##LinkedList 

#define DEFINE_ITERATOR(T)          \
    typedef struct T##Iterator {    \
        Node(T)*    curr;           \
        p64         prev;           \
    } T##Iterator

#define Iterator(T) T##Iterator

#define iter_init(T, node) ({   \
    Iterator(T) _it_ = {        \
    .curr = node,               \
    .prev = 0};                 \
    _it_;                       \
})

#define linkedlist_init { .begin_node = nullptr, .end_node = nullptr, .size = 0 }
#define linkedlist_init { .begin_node = nullptr, .end_node = nullptr, .size = 0 }


#define node_create(T, val) ({                      \
    auto _val_          = to_ptr(val);              \
    Node(T)* _node_     = malloc(sizeof(Node(T)));  \
    _node_->node_val    = *_val_;                   \
    _node_->zored       = 0;                        \
    _node_;                                         \
})

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
            _linked_list_ -> end_node     = _node_,                                 \
            _linked_list_ -> begin_node   = _linked_list_ -> end_node               \
        )                                                                           \
    :                                                                               \
        (                                                                           \
            _node_        -> zored                = (p64)_linked_list_->end_node,   \
            _linked_list_ -> end_node -> zored   ^= (p64)_node_,                    \
            _linked_list_ -> end_node             = _node_                          \
        )                                                                           \
    ;                                                                               \
    _linked_list_->size++;                                                          \
} while(0)

// #define linkedlist_free(linkedlist) do{ \
//     auto _it_ = iter_init;
// } while(0)

#define Iter_Next(it) do {                                              \
    __typeof__(to_ptr(it)) _it_   = to_ptr(it);                         \
    __typeof__(_it_->curr) _next_ =                                     \
    (__typeof__(_it_->curr)) ((p64)(_it_->curr->zored) ^ (_it_->prev)); \
    _it_->prev  = (p64)_it_->curr;                                      \
    _it_->curr  = _next_;                                               \
} while(0)



