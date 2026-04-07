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
#include <ptr/ptr.h>

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Hashbrown hashtable, which implements Google's Swisstable open addressingwith SIMD-accelerated metadata lookups

/**
 * TODO: change all the function names to be readable and try to repalce 
 *       stdint.h with my_ints.h  
 *       stddef.h with my_defs.h  
 *       nullvoid
 */ 

#ifdef __SSE2__
    #include <emmintrin.h>
    #define _HT_SIMD 1
#endif // __SSE2__

// ==================================================================================
//                          wyhash (v4, public domain)   
// ==================================================================================

static inline uint64_t _wy_r8(const void* p) { uint64_t v; memcpy(&v, p, 8); return v; }
static inline uint64_t _wy_r4(const void* p) { uint64_t v; memcpy(&v, p, 4); return v; }

static inline uint64_t _wy_mix(uint64_t a, uint64_t b) {
    #ifdef __SIZEOF_INT128__
        __uint128_t r = (__uint128_t)a * b;
        return (uint64_t)(r >> 64) ^ (uint64_t)r;
    #else
        // 32-bit fallback
        a ^= b >> 32; b ^= a >> 16; return a ^ b;
    #endif
}

/**
 * TODO: find out what these seeds are for [ s0, s1,s2 ]
 * TODO: replace all the magic numbers with macros
 * TODO: formating
 */
static inline uint64_t wyhash(const void* key, size_t len, uint64_t seed) {
    const uint8_t* p = (const uint8_t*)key;
    const uint64_t s0 = 0xa0761d6478bd642full;
    const uint64_t s1 = 0xe7037ed1a0b428dbull;
    const uint64_t s2 = 0x8ebc6af09c88c6e3ull;
    seed ^= _wy_mix(seed ^ s0, s1);

    uint64_t a, b;
    if(len <= 16) {                                                             
        if(len >= 4) { 
            a = (_wy_r4(p) << 32 ) | _wy_r4(p+( ( len >>3 ) << 2));     // why 
            b = (_wy_r4(p+len-4) << 32) | _wy_r4(p+len-4-((len>>3)<<2));// why
        } else if(len > 0) {
            a = ((uint64_t)p[0]<<16) | ((uint64_t)p[len>>1]<<8)|p[len-1]; b=0; // a
        } else {
            a = b = 0; // simple
        }

    } else { // that was only part one
        size_t i = len;
        if(i > 48) {
            uint64_t s = seed, x = seed, y=seed; 
            while(i >48) { // loop to get length == 48 ??
                s = _wy_mix(_wy_r8(p)^s0,  _wy_r8(p+8)^s);  // mixing bytes of p with seeds and copied seeds
                x = _wy_mix(_wy_r8(p+16)^s1, _wy_r8(p+24)^x); // same
                y = _wy_mix(_wy_r8(p+32)^s2, _wy_r8(p+40)^y); // same
                p+=48; i-= 48; // single or double?
            }
            seed = s ^ x ^ y; // xor
        }
        while(i > 16) { // 16 again?
            seed = _wy_mix(_wy_r8(p)^s1, _wy_r8(p+8)^seed); p+=16; i-=16; 
        }
        a = _wy_r8(p+i-16);
        b = _wy_r8(p+i-8 );
    }
    return _wy_mix(s1^len, _wy_mix(a^s1, b^seed)); // too much xor
}

static inline uint64_t wyhash_u64(uint64_t x, uint64_t seed) {
    return _wy_mix(x ^ 0xa0761d6478db642full ^ seed, 0xe70737ed1a0b428dbull);
}

