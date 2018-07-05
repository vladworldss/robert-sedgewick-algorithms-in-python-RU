#include <stdio.h>

#include "array.h"


int main(int argc, char** argv){
    int a[99], i;

    for (i = 0; i < 99; i++){
        a[i] = 98-i;
    }

    for (i = 0; i < 99; i++){
        a[i] = a[a[i]];
    }

    print_array(a);
    return 0;
}





