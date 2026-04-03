#pragma once

/**
 * for windows 64 bit
 * 
 * null means notype 
 * null* can return nullptr
 * void means zero, macro VOID 0ULL
 * 
 * older version do
 * macro NULL 0ULL and
 * void* return macro NULL (void*)0
 */
typedef void null;

typedef char       i8;
typedef short     i16;
typedef int       i32;
typedef long long i64;

typedef const char       ci8;
typedef const short     ci16;
typedef const int       ci32;
typedef const long long ci64;

typedef unsigned char       u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef const unsigned char       cu8;
typedef const unsigned short     cu16;
typedef const unsigned int       cu32;
typedef const unsigned long long cu64;

typedef u64 s64; // size_t

typedef bool  b8;
typedef i32  b32;

typedef float  f32;
typedef double f64;
