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
#include <strings/my_string_defs.h>

typedef struct string {
    
    s64  length;
    i8*  str;

} string, *str_ptr;

typedef i8* string_literal;

static string null_string = {0};

[[nodiscard]] string String (const string_literal str);
[[nodiscard]] string nString(const string_literal str, s64 n);

[[nodiscard]] string String_share(str_ptr share_str);
[[nodiscard]] string String_copy (str_ptr copy_str);

