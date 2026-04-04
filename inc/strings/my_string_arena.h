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

#include <my_ints.h>

typedef struct Arena_Info Arena_Info, *Arena_Info_p;
typedef struct Arena Arena, *Arena_p;

null Init_Arena();
null Free_Arena();

i8* Arena_Push(s64 size);

s64 Get_Arena_Index();
i32 Inc_Arena_Index(s64 inc);
s64 Get_Arena_Capacity();
i8* Get_Arena_Storage();

#ifndef __Init_Arena__
#define __Init_Arena__ Init_Arena();
#endif

#ifndef __Free_Arena__
#define __Free_Arena__ Free_Arena();
#endif




