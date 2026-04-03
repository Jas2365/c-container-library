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

#define _arena_size_undefined_ ( 0 )
#define _arena_size__64_kilo_bytes_ ( 1LL << 16 )
#define _arena_size___4_mega_bytes_ ( 1LL << 22 )
#define _arena_size_256_mega_bytes_ ( 1LL << 28 )

#if   defined _Small_Arena_
    #define _Arena_Size_ _arena_size__64_kilo_bytes_
#elif defined _Medium_Arena_
    #define _Arena_Size_ _arena_size___4_mega_bytes_
#elif defined _Large_Arena_
    #define _Arena_Size_ _arena_size_256_mega_bytes_
#else
    #define _Arena_Size_ _arena_size_undefined_
#endif

#define fmt_str "%.*s"

#define arg_stra(sv) (sv).length, (sv).str
#define arg_strp(sv) (sv)->length, (sv)->str