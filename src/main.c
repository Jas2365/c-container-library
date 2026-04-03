#include <stdio.h>
#include <my_ints.h>
#include <my_defs.h>
#include <stdlib.h>

#include <strings/my_string.h>
#include <strings/my_string_view.h>
#include <strings/my_string_arena.h>
#include <lists/my_list.h>

DEFINE_LIST(i32);

null print_list(List(i32) *l) {
    putchar('[');
    for(i32 i = 0; i< l->size; i++){
        printf(" %d", l->buffer[i]);
        if(i < l->size-1) putchar(',');
    }
    printf(" ]"endl);
}

typedef struct student {
    i32 id;
    i32 age;
    i32 class;
} student;

DEFINE_LIST(student);



i32 main() {

    List(i32) k = {0};

    List(student) st = {0};

    student s0 = { .id = 23, .age = 33, .class = 23};

    list_push(&st, s0);

    printf("s0: %d %d %d" endl, st.buffer[0].age, st.buffer[0].class, st.buffer[0].id);


    i32List* m = &k;

    list_push(m, 23);
    list_push(m, 23);
    list_push(m, 23);
    list_push(m, 23);
    list_push(m, 23);
    list_push(m, 23);

    print_list(&k);
    
    int l;
    int* n;

    printf("%d" endl, is_ptr(l));
    printf("%d" endl, is_ptr(n));


    free_list(k);
    
    return 0;
}

/*

null helper(string_vw temp, i32 i) {    
    
    string_view ch = sv_chop_by_delim(temp, ',');
    printf("id: %d" endl, i);
    printf(" |" fmt_str "|" endl, arg_strp(temp));
    printf(" |" fmt_str "|" endl, arg_stra(ch));

}

    __Init_Arena__
    
    string name = String("   Hello,World,one    ");
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

    __Free_Arena__*/