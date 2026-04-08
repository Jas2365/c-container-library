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


