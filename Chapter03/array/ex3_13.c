//
// Created by vladworldss on 05.07.18.
//

#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "ex3_5.h"


int count_not_null(const unsigned ar_size, unsigned* input_ar){
    int count = 0;

    for (unsigned i = 0; i < ar_size; i++){
        if (input_ar[i]){
            count++;
        }
    }
    return count;
}

int main(int argc, char** argv){
    unsigned N = atoi(argv[1]);
    unsigned array[N];
    init_array(N, array);

    sieve(N, array);
    printf("Count of non-NULL vals: %d\n", count_not_null(N, array));

}