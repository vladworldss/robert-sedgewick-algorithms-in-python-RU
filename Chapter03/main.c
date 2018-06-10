//
// Created by Workstation on 10.06.2018.
//

#include <stdio.h>
#include <math.h>
#include "avg.h"

int main(int argc, char** argv){
    int N = atoi(argv[1]);
    AvgResult res;
    res = getAvg(N);
    printf("Mean value: %f\n", res.avg);
    printf("Std. deviation: %f\n", res.std_dev);
    return 0;
}