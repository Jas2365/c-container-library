#include <stdio.h>
#include <my_ints.h>
#include <my_defs.h>
#include <strings/my_string.h>
#include <strings/my_string_view.h>

int main() {

    string sample_string = "Hello\0 world\0"; 

    printf("%s" endl, sample_string);

    string name = nString("Hello\0 world", 12);
    string_vw name_vw = String_vw(name);
    
    
    
    print_string(name);
    endline;
    
    print_string_vw(name_vw);
    endline;

    free_string_vw(name_vw);
    free_string(name);




    return 0;
}