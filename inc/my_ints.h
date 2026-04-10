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

#include <stdint.h>

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

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef const int8_t  ci8;
typedef const int16_t ci16;
typedef const int32_t ci32;
typedef const int64_t ci64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef const uint8_t  cu8;
typedef const uint16_t cu16;
typedef const uint32_t cu32;
typedef const uint64_t cu64;

typedef int8_t  *ip8;
typedef int16_t *ip16;
typedef int32_t *ip32;
typedef int64_t *ip64;

typedef const int8_t  *cip8;
typedef const int16_t *cip16;
typedef const int32_t *cip32;
typedef const int64_t *cip64;

typedef uint8_t  *up8;
typedef uint16_t *up16;
typedef uint32_t *up32;
typedef uint64_t *up64;

typedef const uint8_t  *cup8;
typedef const uint16_t *cup16;
typedef const uint32_t *cup32;
typedef const uint64_t *cup64;

typedef size_t  s64;    // size_t
typedef size_t  *sp64;  // size_t

typedef bool  b8;
typedef i32  b32;

typedef bool  *bp8;
typedef i32  *bp32;

typedef float  f32;
typedef double f64;
typedef float  *fp32;
typedef double *fp64;

typedef uintptr_t p64;