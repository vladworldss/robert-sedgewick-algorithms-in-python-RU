//
// Created by Workstation on 10.06.2018.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "ex3_2.h"
#include "ex3_3.h"


int main(int argc, char** argv){

    printf("\n*********\n");
    printf("Example 3.2:\n");
    printf("*********\n");

    int N = atoi(argv[1]);
    AvgResult res;
    res = getAvg(N);
    printf("Mean value: %f\n", res.avg);
    printf("Std. deviation: %f\n", res.std_dev);


    // ------------------------
    printf("\n*********\n");
    printf("Example 3.3:\n");
    printf("*********\n");

    Point p1 = {2.333333333, 5.7777777777777777};
    Point p2 = {7.0, 8.0};

    // Print first point
    char first_output[POINT_STR_SIZE] = {0};
    point_to_sting(p1, first_output);
    printf("First point: %s\n", first_output);

    // Print second point
    char second_output[POINT_STR_SIZE] = {0};
    point_to_sting(p2, second_output);
    printf("Second point: %s\n", second_output);

    // Calc distance
    float d = distance(p1, p2);
    printf("Distance between: %f\n", d);

    return 0;
}