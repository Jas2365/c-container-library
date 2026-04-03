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

#include <my_string_arena.h>

#include <stdlib.h>
#include <my_string.h>
#include <my_string_defs.h>

struct Arena_Info {
    
    s64 capacity;
    s64 current_index;

};

struct Arena {
    
    Arena_Info info;
    i8 storage[];

};

struct Arena_Table {
    s64 index;
    // this needs a dynamic array to be more efficient

};

static Arena_p _Global_Arena_;

null Init_Arena() {

    _Global_Arena_ = (Arena_p)malloc(sizeof(Arena) + _Arena_Size_ );
    _Global_Arena_->info.capacity = _Arena_Size_;
    _Global_Arena_->info.current_index = 0;

}

null Free_Arena() {
    free(_Global_Arena_);
}

i8 *Arena_Push(s64 size) {

    if(size + Get_Arena_Index() > Get_Arena_Capacity()) return nullptr; // out of memory
    i8* arena_mem = Get_Arena_Storage() + Get_Arena_Index();            // get current index
    Inc_Arena_Index(size);                                              // increment the index by the length of string
    return arena_mem;                                                   // return the position of the index

}

s64 Get_Arena_Index() {
    return _Global_Arena_->info.current_index;
}

null Inc_Arena_Index(s64 inc) {
    _Global_Arena_->info.current_index += inc;
}

s64 Get_Arena_Capacity() {
    return _Global_Arena_->info.capacity;
}

i8* Get_Arena_Storage() {
    return _Global_Arena_->storage;
}




