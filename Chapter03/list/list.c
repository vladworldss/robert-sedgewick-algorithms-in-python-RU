//
// Created by vladworldss on 06.07.18.
//

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


Link freelist;

void init_nodes(const int N){
    freelist = calloc(N+1, sizeof(*freelist));

    for (int i = 0; i < N+1; i++){
        freelist[i].next = &freelist[i+1];
    }
    freelist[N].next = NULL;
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


Link reverse(Link head){
    Link l_current_node = head;
    Link l_next_node;
    Link tail = NULL;

    while(l_current_node != NULL){
        l_next_node = l_current_node->next;
        l_current_node->next = tail;
        tail = l_current_node;
        l_current_node = l_next_node;
    }
    return tail;
}


unsigned list_size(Link head){
    unsigned res = 0;

    if (head != NULL) {
        Link l_cur_node = head;

        do {
            l_cur_node = l_cur_node->next;
            res++;
        } while (l_cur_node != head);
    }
    return res;
}

void print_list(Link head, const char* delimit){
    Link cur_node = head;

    do{
        printf("%d%s", cur_node->item, delimit);
        cur_node = cur_node->next;
    }
    while((cur_node->next != NULL) && (cur_node->next != head));
    printf("\n");

}