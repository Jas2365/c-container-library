#pragma once

#define __pointer_value__ ((null*)0)
#define __pointer_type__ (__builtin_classify_type(__pointer_value__))

#define is_ptr(object) (__builtin_classify_type(object) == __pointer_type__ )
#define to_ptr(object) __builtin_choose_expr(is_ptr(object), (object), &(object))

#define universal_access(object, member) (to_ptr(object)->member)
