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

// __auto_type is GCC/Clang compiler builtin. 
// not from any header. 
// it predates C23 and works like cpp auto. 
// it infers the type from right-hand side at compiler time 

// here i can replace the initial size and growth size, note: should make a configuration header file that oversees this.

#define _initial_list_size_   ( 8 )
#define _list_growth_size_    ( 2 )

// should also add a list of variable names to avoid such as 
//  1. _list_
//  2. _i_
//  3. _once_
//  4. _initial_list_size_ 
//  5. _list_growth_size_ 

// one more thing for vs code intellisense       
// put the following in .vscode/c_cpp_properties.json 
// "configurations": [{ "intelliSenseMode": "gcc-x64" }]
// for intelllisense warnings that are caused by to_ptr(object)

// All the functions have passed the test

// list_grow   // can be used to mannually grow 

// list_init
// list_alloc

// list_each
// list_foreach
// list_free       // no dangling buffer pointer
// list_destroy   // no dangling pointers

// list_size
// list_capacity
// list_buffer
// list_isempty
// list_get
// list_last

// list_push
// list_pop
// list_clear

// list_reserve   

// use list_reserve if you want to double the capacity at a 
// custom rate such as 
//
// 1. 2  4  8 16 32
// 2. 8 16 32 64 128
// 3. 10 20 40 80 160
//
// selecting the initial capacity value that belongs to the 
// first example has no effect on growth
