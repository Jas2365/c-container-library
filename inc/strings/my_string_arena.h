#pragma once

#include <my_ints.h>

typedef struct Arena_Info Arena_Info, *Arena_Info_p;
typedef struct Arena Arena, *Arena_p;

null Init_Arena();
null Free_Arena();

i8* Arena_Push(s64 size);

s64 Get_Arena_Index();
null Inc_Arena_Index(s64 inc);
s64 Get_Arena_Capacity();
i8* Get_Arena_Storage();

#ifndef __Init_Arena__
#define __Init_Arena__ Init_Arena();
#endif

#ifndef __Free_Arena__
#define __Free_Arena__ Free_Arena();
#endif




