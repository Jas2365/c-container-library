#include <stdio.h>
#include <my_ints.h>
#include <my_defs.h>
#include <strings/my_string.h>
#include <strings/my_string_view.h>

null helper(string_vw sv) {
    printf("string : |");
    print_string_vw(sv);
    printf("|" endl);
}

int main() {
    
    string name = String("    Hello,world,one,   ");
    string_vw name_vw = String_vw(name);

    
    printf("string : |" fmt_str "|" endl, arg_strp(name_vw));
        
    sv_trim(name_vw);
    string_view hello = sv_chop_by_delim(name_vw, ',');

    string_vw hp = sv_chop_by_delim_ptr(name_vw, ',');
    string_vw op = sv_chop_by_delim_ptr(name_vw, ',');

    printf("string : |" fmt_str "|" endl, arg_stra(hello));
    printf("string : |" fmt_str "|" endl, arg_strp(hp));
    printf("string : |" fmt_str "|" endl, arg_strp(op));

    free_string_vw(name_vw);
    free_string(name);

    return 0;
}