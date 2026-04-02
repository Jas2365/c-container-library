#pragma once

#include <my_ints.h>

typedef struct Arena_Info Arena_Info, *Arena_Info_p;
typedef struct Arena Arena, *Arena_p;

extern Arena_p _Global_Arena_;

null Init_Arena();
null Free_Arena();

i8* Arena_Push(s64 size);

s64 Get_Arena_Index();
null Inc_Arena_Index(s64 inc);
s64 Get_Arena_Capacity();
i8* Get_Arena_Storage();




