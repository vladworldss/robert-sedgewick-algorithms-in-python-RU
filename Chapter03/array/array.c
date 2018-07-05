//
// Created by vladworldss on 05.07.18.
//

#include <stdio.h>
#include <stdlib.h>

#include "array.h"


int init_array(const unsigned ar_size, unsigned* input_ar){
    for (unsigned i = 0; i < ar_size; i++){
        input_ar[i] = 0;
    }
}


int print_array(const unsigned size, unsigned* array){

    for (unsigned i = 0; i < size; i++){
        printf("%d ", array[i]);
        if ((i % 10 == 0) && i > 0)
            printf("\n");
    }

    return 0;
}
