//
// Created by Workstation on 10.06.2018.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char** argv){

    // =======================
    printf("\n*********\n");
    printf("Example 3.6:\n");
    printf("*********\n");

    const int SIEVE_SIZE = atoi(argv[1]);
    size_t INT_SIZE = sizeof(int);
    int* array = calloc(SIEVE_SIZE*INT_SIZE, INT_SIZE);
    if (array == NULL){
        perror("Insufficient memory");
        return -1;
    }

    int ar_idx =0;
    for(ar_idx = 2; ar_idx < SIEVE_SIZE; ar_idx++){
        array[ar_idx] = 1;
    }

    for(ar_idx = 2; ar_idx < SIEVE_SIZE; ar_idx++){
        if (array[ar_idx]){
            for (int inner_idx = ar_idx; inner_idx*ar_idx < SIEVE_SIZE; inner_idx++){
                array[inner_idx*ar_idx] = 0;
            }
        }
    }

    printf("FIRST %d SIMPLE VALUES\n\n", SIEVE_SIZE);
    for (int printed = 0, idx = 0; idx < SIEVE_SIZE; idx++){
        if (array[idx] == 1){
            printf("%d ", idx);
            printed++;
        }

        if (printed > 0 & ((printed % 10) == 0)){
            printf("\r\n");
            printed = 0;
        }
    }
    if (array != NULL)
        free(array);
    return 0;
}