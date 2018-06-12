/*
 * Реализация <Программа 3.2>
*/
#include <stdlib.h>

#include "avg.h"


Number get_rand_num(){
    return rand();
}

AvgResult getAvg(int N){
    float mu = 0.0;
    float mu_square = 0.0;
    Number x;

    for (int i =0; i < N; i++){
        x = get_rand_num();
        mu += ((float) x) / N;
        mu_square += ((float) x*x) / N;
    }
    float std_dev = sqrt(mu_square - mu*mu);
    AvgResult res = {mu, std_dev};
    return res;
}
