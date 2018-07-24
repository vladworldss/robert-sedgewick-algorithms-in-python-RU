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


void print_matrix(Link* m, unsigned size){
    for (int i = 0; i < size; i++){
        Link cur = m[i];

        while (cur != NULL){
            printf("%d->", cur->item);
            cur = cur->next;
        }
        printf("\n");
    }

}


int main(int argc, char** argv){
    unsigned N = atoi(argv[1]);
    Link adj[N];

    int i, j;
    for (i = 0; i < N; i++){
        adj[i] = NULL;
    }

    while(scanf("%d %d", &i, &j) == 2){
        adj[j] = NEW(i, adj[j]);
        adj[i] = NEW(j, adj[i]);
    }
    print_matrix(adj, N);
    return 0;
}
