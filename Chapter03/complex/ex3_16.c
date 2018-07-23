/* Программа 3.16 Распределение памяти под двумерный массив*/
#include <stdlib.h>


int malloc2d(int r, int c){
    int** t = calloc(r, sizeof(*t));
    for (int i=0; i < r; i++){
        t[i] = calloc(c, sizeof(int));
    }
    return t;
}
