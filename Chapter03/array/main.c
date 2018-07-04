#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "ex3_5.h"
#include "ex3_6.h"

int main(int argc, char** argv){
    // =======================
    printf("\n*********\n");
    printf("Example 3.5:\n");
    printf("*********\n");

    const int SIEVE_SIZE = 1000;

    /*Массив, где будут храниться простые числа.
     * Чтобы исключить попадание "мусора" в результаты -
     * инициализируем -1.
     * */
    const int OUT_SIZE = SIEVE_SIZE/2;
    int out_array[OUT_SIZE];
    for(int i=0; i< OUT_SIZE; i++){
        out_array[i] = -1;
    }

    // Вычисляем первые SIEVE_SIZE простых чисел
    sieve(SIEVE_SIZE, out_array);

    // Выводим на печать результаты. Число элементов в строке <= 10.
    printf("FIRST %d SIMPLE VALUES\n\n", SIEVE_SIZE);
    for (int printed = 0, idx = 0; idx < OUT_SIZE; idx++){
        if (out_array[idx] > 0){
            printf("%d ", out_array[idx]);
            printed++;
        }

        if (printed > 0 & ((printed % 10) == 0)){
            printf("\r\n");
        }
    }
    return 0;
}