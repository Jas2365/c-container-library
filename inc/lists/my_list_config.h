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

// auto is c23 keyword use __auto_type for older version
// __auto_type is GCC/Clang compiler builtin. 
// not from any header. 
// it predates C23 and works like cpp auto. 
// it infers the type from right-hand side at compiler time 

// should also add a list of variable names to avoid such as 
//  1. _list_
//  2. _i_
//  3. _once_
//  4. _initial_list_size_ 
//  5. _list_growth_size_
//  6. _null_list_

// one more thing for vs code intellisense       
// put the following in .vscode/c_cpp_properties.json 
// "configurations": [{ "intelliSenseMode": "gcc-x64" }]
// for intelllisense warnings that are caused by to_ptr(object)

// all list functions

// DEFINE_LIST(T)
// List(T)

// list_init
// list_alloc(T)

// _null_list_(list)

// list_size(list)
// list_capacity(list)
// list_buffer(list)
// list_isempty(list)
// list_get(list, index)
// list_last(list)

// list_grow(list)

// list_reserve(list, size)

// list_push(list, item)
// list_pop(list)
// list_clear(list)

// list_free(list)       
// list_destroy(list)

// list_each(list, index)
// list_each_step(list, index, step)
// list_foreach(list, T, var)

// use list_reserve if you want to double the capacity at a 
// custom rate such as 
//
// 1. 2  4  8 16 32
// 2. 8 16 32 64 128
// 3. 10 20 40 80 160
//
// selecting the initial capacity value that belongs to the 
// first example has no effect on growth
