//
// Created by Workstation on 12.06.2018.
//
#include <stdio.h>

#include "eratosthenes_sieve.h"


int sieve(int ARRAY_SIZE, int* out_array){
    int array[ARRAY_SIZE];
    int ar_idx = 0;

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
            for (int inner_idx = ar_idx; inner_idx*ar_idx < ARRAY_SIZE; inner_idx++){
                array[inner_idx*ar_idx] = 0;
            }
        }
    }

    // Копируем результаты в выходной массив
    for (int out_idx = 0, ar_idx = 2; ar_idx < ARRAY_SIZE; ar_idx++){
        if (array[ar_idx] == 1){
            out_array[out_idx] = ar_idx;
            out_idx++;
        }
    }

    return 0;
}