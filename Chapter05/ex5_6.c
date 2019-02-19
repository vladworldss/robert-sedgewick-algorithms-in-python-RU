/* ex5_6.c
 *
 * Программа 5.6 Алгоритм "разрядяй и властвуй" для поиска максимума в массиве.
 * */

#include <stdio.h>
#include <assert.h>

#include "../Chapter04/Item.h"


Item max(Item a[], int l, int r){
    Item u, v;
    int m = (l+r)/2;

    if(l == r){
        return a[l];
    }
    u = max(a, l, m);
    v = max(a, m+1, r);

    return (u < v) ? v : u;
}


int main(int argc, char** argv){
    printf("ex5_6 starting...\n");

    int a[] = {0, 100, 4, 3, 99, 44, 101} ;
    assert(max(a, 0, 6) == 101);
    printf("max = %d\n", max(a, 0, 6));
    printf("exit\n");
    return 0;
}