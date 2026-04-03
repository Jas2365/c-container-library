#include <my_ints.h>
#include <my_defs.h>


struct array {
    s64 length;
    s64 capacity;
    s64 stride;
    
    i8* buffer;
};