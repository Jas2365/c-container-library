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


//  The concept
//  i32 num     = 123;
//  i32 num2    = 456;
//
//  p64 a = (p64)&num;
//  p64 b = (p64)&num2;
//
//  printf("a:      %p" endl, a);
//  printf("b:      %p" endl, b);
//
//  printf("a^b:    %p" endl, a^b);
//  printf("a^b^b:  %p" endl, a^b^b);
// 
//  p64 xored = a^b;
//
//  printf("a val:  %d" endl, *((i32*)(xored ^ b)));
//  printf("b val:  %d" endl, *((i32*)(xored ^ a)));



//  list of variable names to avoid such as 
//  1. _linked_list_
//  2. _it_
//  3. _it2_
//  4. _node_
//  5. _once_

/**
 * Macro Loops
 * printf("For Loop:"endl);
 * linkedlist_each(ss, it) {
 *     print_node(it.curr);
 * } endline;
 * 
 * printf("While Loop:"endl);
 * linkedlist_foreach(ss, var) {
 *     print_node(var);
 * } endline;
 *
 */

/** 
 *  Normal loops
 *  printf("For Loop:"endl);
 *  for(__typeof__(linkedlist_iter(ss)) it = ss.iter ; Iter(it); Iter_Next(it)) {
 *      print_node(it.curr);
 *  } endline;
 *   
 *  printf("While Loop:"endl);
 *  Iterator(st) it2 = ss.iter;
 *  while(Iter(it2)) {
 *      print_node(Iter(it2));
 *      Iter_Next(it2);
 *  } endline;
 */
