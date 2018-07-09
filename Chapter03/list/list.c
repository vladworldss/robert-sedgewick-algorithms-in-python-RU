//
// Created by vladworldss on 06.07.18.
//

#include <stdlib.h>

#include "list.h"


Link freelist;

void init_nodes(const int LIST_SIZE){
    freelist = calloc(N+1, sizeof(*freelist));

    // уточнить про head
    for (int i = 0; i < N+1; i++){
        freelist[i]->next = &freelist[i+1];
    }
    freelist[N]->next = NULL;
}


Link new_node(int value){
    Link x = delete_next(freelist);
    x->item = value;
    x->next = x;
    return x;
}


void free_node(Link x){
    insert_next(freelist, x);
}


void insert_next(Link x, Link t){
    t->next = x->next;
    x->next = t;
}


Link delete_next(Link x){
    Link t = x->next;
    x->next = t->next;
    return t;
}


Link get_next(Link x){
    return x->next;
}


int get_item(Link x){
    return x->item;
}