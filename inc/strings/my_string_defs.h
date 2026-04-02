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