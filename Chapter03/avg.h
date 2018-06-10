//
// Created by Workstation on 10.06.2018.
//

#ifndef ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_AVG_H
#define ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_AVG_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef float Number;

Number get_rand_num(void);

typedef struct {
    float avg;
    float std_dev;
} AvgResult;

AvgResult getAvg(int);

#endif //ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_AVG_H
