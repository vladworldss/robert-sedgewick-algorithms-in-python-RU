#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Node* Link;

struct Node{
    Item item;
    Link next;
};


int main(int argc, char** argv){
    int a = 77;
    const size_t INT_SIZE = sizeof(int);
    int* ptr_a = (int*) malloc(3*INT_SIZE);
    int* new_ptr_a = ptr_a;

    ptr_a[0] = a;

    printf("adress from prtf: %d\n", ptr_a);
    printf("adress from new_prtf: %d\n", new_ptr_a);

    printf("a value is: %d\n", a);
    printf("a value from prt: %d\n", *ptr_a);
    printf("a value from new_prt: %d\n", *new_ptr_a);

    printf("\n");
    printf("clear ptr\n");
    free(ptr_a);
    printf("clear from prt: %d\n", *ptr_a);
    printf("clear new_prt: %d\n", *new_ptr_a);
    printf("\n");

    a = 777;
    new_ptr_a[0] = a;
    printf("new a value is: %d\n", a);
    printf("new a value from prt: %d\n", *ptr_a);
    printf("new a value from new_prt: %d\n", *new_ptr_a);

    printf("adress from prtf: %d\n", ptr_a);
    printf("adress from new_prtf: %d\n", new_ptr_a);
    printf("\n");

    printf("overadress: %d\n", ptr_a[10]);
    printf("overadress: %d\n", ptr_a[3]);



//    int* new_ptr_a = ptr_a;
//
//
//
//    printf("a value is: %d\n", a);
//    printf("a value from prt:%d\n", *new_ptr_a);
//
//    printf("clear new_ptf\n");
//    del new_ptr_a;
//    printf("a value is: %d\n", a);
//
//
//    printf("Badass ptr\n");
//    printf("a value from prt: %d\n", *ptr_a);
//    printf("a value from new_prt: %d\n", *new_ptr_a);

    return 0;
}