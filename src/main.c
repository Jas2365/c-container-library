#include <stdio.h>
#include <my_ints.h>
#include <my_defs.h>
#include <my_string.h>

int main() {


    string name = String("Name");
    string_tag* name2 = String_Tag("Name");

    // printf("length: %zu" endl, &name2->length);
    // printf("data :  %zu" endl, &name2->data);
    
    printf("%zu" endl, name);
    printf("%zu" endl, name);
    printf("%zu" endl, ((string_tag*)(name - 8))->length  );

    printf(fmt_str endl, arg_str(name));
    
    // printf(fmt_str endl,((string_tag*)(name - 8))->length , (name));
        

    return 0;
}