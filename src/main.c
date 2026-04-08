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

#include <stdio.h>
#include <my_ints.h>
#include <my_defs.h>
#include <stdlib.h>
#include <string.h>  

// #include <strings/my_string.h>
// #include <strings/my_string_view.h>
// #include <strings/my_string_arena.h>
#include <lists/my_list.h>
#include <arrays/my_array.h>
#include <linked_list/my_linked_list.h>

// typedef struct Rank { string str; i32 val; } Rank;
// typedef struct Suit { string str; i32 val; } Suit;
// typedef struct Card { string suit; string rank; } Card;

// DEFINE_LIST(Rank);
// DEFINE_LIST(Suit);
// DEFINE_LIST(Card);

// DEFINE_ARRAY(string, 12);
// DEFINE_ARRAY(string, 4);
// DEFINE_ARRAY(Card, 52);
// DEFINE_ARRAY(i8, 5);

typedef struct st {
    i32 one;
    i32 two;
} st;

DEFINE_LINKED_LIST(st);


null print_node(Node(st)* n) {
    printf("Node: v0: %-2d, v1: %-2d, xored: %p"endl, 
            n->node_val.one,    
            n->node_val.two,    
            n->zored    
    );
}

i32 main() {
    
    LINKED_LIST(st) ss = linkedlist_init(st);

    for(i32 i = 0; i<5; i++){
        st tt = {
            .one = i,
            .two = i+5,
        };
        linkedlist_append_end(ss, st, tt);
    }
    for(i32 i = 5; i<5+5; i++){
        st tt = {
            .one = i,
            .two = i+5,
        };
        linkedlist_append_begin(ss, st, tt);
    }
    printf("size : %d"endl, ss.size);

    

    for(Iterator(st) it = ss.riter ; it.curr; Iter_Next(it)) {
        print_node(it.curr);
    }

    

    // Iterator(st) it2;
    // it2 = iter_init(st, ss.begin_node);
    
    // while(it2.curr) {
    //     __typeof__(it2.curr) nn = it2.curr;
    //     Iter_Next(it2);
    //     memset(nn, 0xAA, sizeof(*nn));
    //     free(nn);
    // }

    // printf("val : %p" endl, ss.begin_node->zored);
    // printf("val : %p" endl, ss.end_node->zored);
    // printf("val : %d" endl, ss.end_node->node_val.one);
    
    // ss.begin_node = nullptr;
    // ss.end_node = nullptr;
    // ss.size = 0;
    
    // it = iter_init(st, ss.end_node);
    
    // while(it.curr) {
    //     print_node(it.curr);
    //     Iter_Next(it);
    // }
    // destroy

    

    // _Init_Arena_

    // Array(string, 4) st = array_init(string, 4);
    // array_push(st, String("one"));
    // array_push(st, String("two"));
    // printf("size %d, capacity %d" endl, array_size(st), array_capacity(st));
    
    // st = _null_array_(st);
    // printf("size %d, capacity %d" endl, array_size(st), array_capacity(st));
    
    // array_push(st, String("one"));
    // array_push(st, String("two"));
    // printf("size %d, capacity %d" endl, array_size(st), array_capacity(st));
    

    // array_push_assert(st, String("hello"));
    


    // string temp =  array_pop_assert(st);

    // printf(fmt_str endl, arg_str(temp));
    

    // List(i32) temp = list_init;
    
    // list_push(temp, 23);
    // list_pop(temp);
    // list_pop(temp);
    // printf("size     %zu"endl , list_size(temp));
    // printf("capacity %zu"endl , list_capacity(temp));
    
    // i32 kk = list_pop_assert(temp);
    // printf("poped %d"endl , kk);
    // kk = list_pop_assert(temp);
    // printf("poped %d"endl , kk);

    // printf("size %zu"endl , list_size(temp));

    // _Free_Arena_

    return 0;
}

    /*
    _Init_Arena_                                                                          // strings memory

    const string _A_ = String( "A" );
    const string _2_ = String( "2" );
    const string _3_ = String( "3" );
    const string _4_ = String( "4" );
    const string _5_ = String( "5" );
    const string _6_ = String( "6" );
    const string _7_ = String( "7" );
    const string _8_ = String( "8" );
    const string _9_ = String( "9" );
    const string _J_ = String( "J" );
    const string _Q_ = String( "Q" );
    const string _K_ = String( "K" );
    
    Array(string, 12) _Rank_Table_ = array_init(string, 12);
    
    array_push(_Rank_Table_, _A_);
    array_push(_Rank_Table_, _2_);
    array_push(_Rank_Table_, _3_);
    array_push(_Rank_Table_, _4_);
    array_push(_Rank_Table_, _5_);
    array_push(_Rank_Table_, _6_);
    array_push(_Rank_Table_, _7_);
    array_push(_Rank_Table_, _8_);
    array_push(_Rank_Table_, _9_);
    array_push(_Rank_Table_, _J_);
    array_push(_Rank_Table_, _Q_);
    array_push(_Rank_Table_, _K_);
    
    array_each(_Rank_Table_, r) {
        printf(space fmt_str, arg_stra(array_get(_Rank_Table_, r)));
    } endline;

    array_foreach(_Rank_Table_, string, name) {
        printf(space fmt_str, arg_stra(name));
    } endline;

    const string _Spade_   = String("Spade");
    const string _Clover_  = String("Clover");
    const string _Diamond_ = String("Diamond");
    const string _Heart_   = String("Heart");

    Array(string, 4) _Suit_Table_ = array_init(string, 4);

    array_push(_Suit_Table_, _Spade_);
    array_push(_Suit_Table_, _Clover_);
    array_push(_Suit_Table_, _Diamond_);
    array_push(_Suit_Table_, _Heart_);

    array_each(_Suit_Table_, s) {
        printf(space fmt_str, arg_stra(array_get(_Suit_Table_, s)));
    } endline;

    array_foreach(_Suit_Table_, string, name) {
        printf(space fmt_str, arg_stra(name));
    } endline;


    Array(Card, 52)* _Cards_ = array_alloc(Card, 52);

    printf("size of card %d bytes"endl, sizeof(Array(i8, 5)));
    printf("size of card %d bytes"endl, sizeof(Card) * 52);
    printf("size of card %d bytes"endl, sizeof(s64) * 2);
    printf("size of card %d bytes"endl, sizeof(Array(Card, 52)));

    string ss;
    string rr;

    array_each(_Suit_Table_, i) {
        ss = array_get(_Suit_Table_, i);
        array_each(_Rank_Table_, j) {
            rr = array_get(_Rank_Table_, j);
            Card c = {
                .rank = rr,
                .suit = ss,
            };
            array_push_assert(_Cards_, c);
            printf(fmt_str space fmt_str endl, arg_stra(ss), arg_stra(rr));
        }
    }

    printf("size: %d" endl, array_size(_Cards_));


    array_each_step(_Cards_, c, 4) {
        printf(fmt_str space fmt_str space, 
            arg_stra(array_get(_Cards_, c +0).suit), 
            arg_stra(array_get(_Cards_, c +0).rank) 
        );
        printf(fmt_str space fmt_str space, 
            arg_stra(array_get(_Cards_, c +1).suit), 
            arg_stra(array_get(_Cards_, c +1).rank) 
        );
        printf(fmt_str space fmt_str space, 
            arg_stra(array_get(_Cards_, c +2).suit), 
            arg_stra(array_get(_Cards_, c +2).rank) 
        );
        printf(fmt_str space fmt_str, 
            arg_stra(array_get(_Cards_, c +3).suit), 
            arg_stra(array_get(_Cards_, c +3).rank) 
        ); endline;
    }

    // List(Rank) _Ranks_ = list_init;

    // list_push(_Ranks_, _A_);
    // list_push(_Ranks_, _1_);
    // list_push(_Ranks_, _2_);
    // list_push(_Ranks_, _3_);
    // list_push(_Ranks_, _4_);
    // list_push(_Ranks_, _5_);
    // list_push(_Ranks_, _6_);
    // list_push(_Ranks_, _7_);
    // list_push(_Ranks_, _8_);
    // list_push(_Ranks_, _9_);
    // list_push(_Ranks_, _J_);
    // list_push(_Ranks_, _Q_);
    // list_push(_Ranks_, _K_);

    // putchar('[');
    // list_each(_Ranks_, r) {
    //     printf(" %d", list_get(_Ranks_, r));
    //     if(r != list_size(_Ranks_) -1) putchar(',');
    // }
    // printf(" ]" endl);
    
    // list_free(_Ranks_);


    // List(Suit) Spade_Suit = list_init;
    
    // List(Card) deck = list_init;
    

    
    // list_push(Spade_Suit, _A_);


    // list_free(Spade_Suit);
    // list_free(deck);

    _Free_Arena_                                                                      // free not needed for small projects
   
    */


/*

null helper(string_vw temp, i32 i) {    
    
    string_view ch = sv_chop_by_delim(temp, ',');
    printf("id: %d" endl, i);
    printf(" |" fmt_str "|" endl, arg_strp(temp));
    printf(" |" fmt_str "|" endl, arg_stra(ch));

}

    __Init_Arena__
    
    string name = String("   Hello,World,one    ");
    string name2 = String(" Name 2 ");

    printf("%s" endl , name.str);
    printf(fmt_str endl, arg_stra(name));
    printf(fmt_str endl, arg_stra(name2));

    string hello = String_share(&name);
    
    printf(fmt_str endl, arg_stra(hello));
    

    string_view temp = String_View(&hello);
  
    sv_trim(&temp);
    
    helper(&temp, 1);
    helper(&temp, 2);
    helper(&temp, 3);

    printf(fmt_str endl, arg_stra(hello));

    __Free_Arena__
    ===================================================

    Lists
    // stack
    List(i32) l = list_init;

    list_push(l, 10);
    list_push(l, 20);

    putchar('[');
    list_each(l, i) { 
        printf(" %d", list_get(l, i)); 
        if(i != list_size(l) -1)
        putchar(','); 
    }
    printf(" ]" endl);

    list_foreach(l, i32, x) {
        printf("%d" endl, x);
    }

    printf("Before free: %d %d %d" endl, l.size, l.capacity, l.buffer[0]);

    list_free(l);

    printf("After free: %d %d %d" endl, l.size, l.capacity, l.buffer);

    putchar('[');
    list_each(l, i) { 
        printf(" %d", list_get(l, i)); 
        if(i != list_size(l) -1)
        putchar(','); 
    }
    printf(" ]" endl);


    // Heap
    List(i32)* ll = list_alloc(i32);

    list_reserve(ll, 10);

    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 55);
    list_grow(ll);

    putchar('[');
    list_each(ll, i) { 
        printf(" %d", list_get(ll, i)); 
        if(i != list_size(ll) -1)
        putchar(','); 
    }
    printf(" ]" endl);

    i32 tt = list_pop(ll);

    printf(" poped    : %d" endl, tt);
    printf(" size     : %d" endl, list_size(ll));
    printf(" capacity : %d" endl, list_capacity(ll));
    printf(" last     : %d" endl, list_last(ll));
    list_clear(ll);
    printf(" is_empty : %d" endl, list_isempty(ll));
    if(list_isempty(ll)) {
        printf("empty" endl);
    } else {
        printf("not empty" endl);
    }

    list_destroy(ll);
    
    if(ll) {
        printf("exist" endl);
    } else {
        printf("not exist" endl);
    }

===================================================
    
    
    */