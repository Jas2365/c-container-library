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

#include <strings/my_string.h>
#include <strings/my_string_view.h>
#include <strings/my_string_arena.h>
#include <lists/my_list.h>

DEFINE_LIST(i32);

i32 main() {

    // stack
    List(i32) l = list_init;

    list_push(l, 10);
    list_push(l, 20);
    list_push(l, 10);
    list_push(l, 20);
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

    list_free(l);

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
    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 23);
    list_push(ll, 55);
    list_grow(ll);

    /**
     * 2 4 8 16 32
     * 8 16 32
     * 10 20 40 80 160
     */

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

    return 0;
}

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

    __Free_Arena__*/