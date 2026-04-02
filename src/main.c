#include <stdio.h>
#include <my_ints.h>
#include <my_defs.h>
#include <stdlib.h>

#include <strings/my_string.h>
#include <strings/my_string_view.h>
#include <strings/my_string_arena.h>

null helper(string_vw temp, i32 i) {    
    
    string_view ch = sv_chop_by_delim(temp, ',');
    printf("id: %d" endl, i);
    printf(" |" fmt_str "|" endl, arg_strp(temp));
    printf(" |" fmt_str "|" endl, arg_stra(ch));

}

i32 main() {
    Init_Arena();
    
    string name = String("   Hello,World one    ");
    string name2 = String(" Name 2 ");

    printf("%s" endl , name.str);
    printf(fmt_str endl, arg_stra(name));
    printf(fmt_str endl, arg_stra(name2));

    string hello = String_share(&name);
    
    printf(fmt_str endl, arg_stra(hello));
    

    string_view temp = String_View(&hello);
  
    sv_trim(&temp);
    
    helper(&temp, 1);
    helper(&temp, 2);
    helper(&temp, 3);

    printf(fmt_str endl, arg_stra(hello));

    Free_Arena();
    return 0;
}