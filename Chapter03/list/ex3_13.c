//
// Created by vladworldss on 09.07.18.
//

#include <stdio.h>

#include "list.h"


int main(int argc, char** argv){
    int i, N = atoi(argv[1]), M = atoi(argv[2]);
    Link t, x;

    init_nodes(N);
    for (i = 2, x = new_node(1); i <= N; i++){
        t = new_node(i);
        insert_next(x, t);
        x = t;
    }

    while (x != get_next(x)){
        for (i=1; i < M; i++){
            x = get_next(x);
        }
        free_node(delete_next(x));
    }

    printf("The Highlander: %d\n", get_item(x));
    return 0;
}

