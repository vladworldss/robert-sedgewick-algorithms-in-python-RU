//
// Реализация Програмы 3.5 Решето Эратосфена
//
#include <stdio.h>

#include "ex3_5.h"


int sieve(unsigned ARRAY_SIZE, unsigned* out_array){
    unsigned array[ARRAY_SIZE];
    unsigned ar_idx = 0;

    /* Вначале проставляем 1 во всех ячейках массива,
     * кроме 0 и 1 - они не являются простыми и не пропускаются.
     * */
    for(ar_idx = 2; ar_idx < ARRAY_SIZE; ar_idx++){
        array[ar_idx] = 1;
    }

    for(ar_idx = 2; ar_idx < ARRAY_SIZE; ar_idx++){
        if (array[ar_idx]){
            /*Присваиваем 0 элементам, индексы которых не являются
             * простыми числами (представляют собой произведения простых чисел).
             * */
            for (unsigned inner_idx = ar_idx; inner_idx*ar_idx < ARRAY_SIZE; inner_idx++){
                array[inner_idx*ar_idx] = 0;
            }
        }
    }

    // Копируем результаты в выходной массив
    for (unsigned out_idx = 0, ar_idx = 2; ar_idx < ARRAY_SIZE; ar_idx++){
        if (array[ar_idx] == 1){
            out_array[out_idx] = ar_idx;
            out_idx++;
        }
    }

    return 0;
}
