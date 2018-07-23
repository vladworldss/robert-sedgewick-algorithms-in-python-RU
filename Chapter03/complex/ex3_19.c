/* Программа 3.19
 * Представление графа в виде списков смежных вершин
 * */

#include <stdio.h>
#include <stdlib.h>

#include "../list/list.h"


Link NEW(int v, Link next){
    Link x = calloc(1, sizeof(*x));
    x->item = v;
    x->next = next;
    return x;
}

int main(int argc, char** argv){
    unsigned N = atoi(argv[1]);
    Link adj[N];



    return 0;
}