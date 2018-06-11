/*
 * Заголовочные файлы <Программы 3.2 _Типы чисел_>
 */

#ifndef ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_AVG_H
#define ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_AVG_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef float Number;

typedef struct {
    float avg;
    float std_dev;
} AvgResult;

/* Функция возвращает случайное число.*/
Number get_rand_num(void);

/* Функци вычисляет среднее значение и среднеквадратичное значение
 * ряда целых чисел сгенерированных процедурой get_rand_num.
 * Данная реализация осуществляет расчет величин за 1 проход.
 * */
AvgResult getAvg(int);

#endif //ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_AVG_H
