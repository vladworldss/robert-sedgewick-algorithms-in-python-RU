//
// Created by vladworldss on 05.07.18.
//
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"

static const TRUE = 1;


long get_count_nodes(Link l_input_node){

    if (l_input_node == NULL){
        return -1;

    } else if (l_input_node->next == l_input_node){
        return 1;

    } else {
        unsigned res = 0;
        Link l_cur_node = l_input_node;

        do{
            l_cur_node = l_cur_node->next;
            res++;
        }
        while(l_cur_node != l_input_node);
        return res;
    }
}

Link rand_node(Link head, unsigned LIST_SIZE){
    int rand_node_idx = rand() % LIST_SIZE;
    Link l_cur_node = head;
    for(int i = 0; i < rand_node_idx; i++){
        l_cur_node = l_cur_node->next;
    }
    return l_cur_node;
}


int main(int argc, char** argv){

    // размер списка - число узлов
    int N = atoi(argv[1]);
    if (N < 1){
        perror("Bad size of list");
        return -1;
    }

    // выбираем, с какого узла начнем
    int M = atoi(argv[2]);
    if (M < 1){
        perror("Bad remove period");
        return -1;
    }

    // Выделяем память под ссылку
    size_t LINK_SIZE = sizeof(Link);
    const Link l_first_node = calloc(LINK_SIZE, LINK_SIZE);
    l_first_node->item = 1;
    l_first_node->next = l_first_node;

    // т.к. мы пока создали лишь 1 узел - next смотрит на себя
    Link l_current_node = l_first_node;

    for (int i=2; i <= N; i++){
        l_current_node = (l_current_node->next = calloc(LINK_SIZE, LINK_SIZE));
        l_current_node->item = i;
        l_current_node->next = l_first_node;
    }

    l_current_node = rand_node(l_current_node, N);
    assert((int) get_count_nodes(l_current_node) == N);
    return 0;
}