/*
 * Реализация Программ 3.3 и 3.4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "point.h"


float distance(Point a, Point b){

    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

void polar(float x, float y, float *r, float *thetha){
    *r = sqrt(x*x + y*y);
    *thetha = atan2(y, x);
}

int int_to_str(float num, char *str) {
    if(str == NULL){
        perror("str pointer is NULL");
        exit(EXIT_FAILURE);
    }
    sprintf(str, "%.3f", num);
    return 0;
}

int point_to_sting(Point p, char* output){
    char x_str[POINT_COORD_SIZE+1] = {0};
    int_to_str(p.x, x_str);

    char y_str[POINT_COORD_SIZE+1] = {0};
    int_to_str(p.y, y_str);

    char* buff = calloc(POINT_STR_SIZE, 1);
    snprintf(buff, POINT_STR_SIZE, "x=%s; y=%s", x_str, y_str);
    strncpy(output, buff, POINT_STR_SIZE);
    return 0;
}
