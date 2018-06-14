/*
 * Реализация <Программа 3.7 Имитация подбрасывания монеты>
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "bernoulli.h"

const float RAND_MAX_F = RAND_MAX;

int heads(){
    float r_val = (float) rand() / RAND_MAX_F;
    return r_val >= 0.5;
}


int main(int argc, char** argv){

    // =======================
    printf("\n*********\n");
    printf("Example 3.7:\n");
    printf("*********\n");

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    /*Выделяем память под результы частот количества выпадений решек.*/
    size_t INT_SIZE = sizeof(int);
    int* result = (int*) calloc((N+1)*INT_SIZE, INT_SIZE);
    if (result == NULL){
        perror("Doesn't allocate memory.Exit...\n");
        return -1;
    }

    /*Инициализация массива*/
    printf("Initializing...\n");
    for(int i=0; i <= N; i++){
        result[i] = 0;
    }

    /*Идея:
     * мы имеем M-эпох, в которых N экспериментов (N-подбрасываний монеты).
     * По окончанию эпохи мы имеем число выпавших Решек.
     * Данное число является индексом ячейки, которую нужно увеличить
     * на 1 за одну эпоху (аналог с defauldict(int)).
     *
     * По окончанию всех эпох в массиве result каждая ячейка (частота)
     * содержит число соответствий по всем эпохам,
     * т.е. число эпох, в которых частота выпадения Решки равнялась данному индексу.
     * */

    printf("Calculate props...\n");
    int freq, event_c;
    for(int epochs = 0; epochs < M;  epochs++, result[freq]++){
        for (freq = 0, event_c = 0; event_c <= N; event_c++){
            if (heads()){
                freq++;
            }
        }
    }

    for(int i = 0; i <= N; i++){
        printf("%2d ", i);
        for(int j = 0; j < result[i]; j+=10){
            printf("*");
        }
        printf("\n");
    }

    printf("Exit...\n");
    free(result);
    return 0;
}
