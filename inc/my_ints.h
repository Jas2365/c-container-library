#pragma once

// for windows 64 bit

typedef void null;

/**
 * null means notype 
 * null* can return nullptr
 * void means zero, macro VOID 0ULL
 * 
 * older version do
 * macro NULL 0ULL
 * void* can return (void*)0
 */

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

// #ifdef _WIN64 && (!_WIN32)
typedef i64  ss64; // ssize_t
typedef u64   s64; // size_t
typedef i32  ss32; // ssize_t
typedef u32   s32; // size_t
// #elif _WIN32 && (_WIN64)
// #endif

typedef bool  b8;
typedef i32  b32;

typedef float  f32;
typedef double f64;
