//
// Created by vladworldss on 06.07.18.
//
#include <stdio.h>
#include <stdlib.h>

#include "list.h"


int insert_list(Link extended_node, Link insert_node){
    // Без проверки на пересечение
    Link ext_next_node = extended_node->next;
    extended_node->next = insert_node;

    // поиск ссылки, указывающей на insert_node
    Link ins_prev_node;
    Link cur_node = insert_node;

    // будет ли работать при вставке 1-го узла?
    do{
        cur_node = cur_node->next;
    }while (cur_node->next != insert_node);

    cur_node->next = ext_next_node;
    return 0;
}


Link range_list(const unsigned list_size, int start_item){

    // Выделяем память под ссылку
    const Link l_first_node = calloc(1, sizeof(*l_first_node));

    l_first_node->item = start_item;
    l_first_node->next = l_first_node;

    // т.к. мы пока создали лишь 1 узел - next смотрит на себя
    Link l_current_node = l_first_node;

    for (unsigned i=(start_item+1), count=0; count < list_size-1; i++){
        l_current_node = (l_current_node->next = calloc(1, sizeof(*l_current_node)));
        l_current_node->item = i;
        l_current_node->next = l_first_node;
        count++;
    }
    return l_first_node;
}


int main(int argc, char** argv){

    Link first_node_head = range_list(10, 1);
    Link second_node_head = range_list(4, 20);

    insert_list(first_node_head,  second_node_head);

    Link cur_node = first_node_head;
    do{
        printf("%d->", cur_node->item);
        cur_node = cur_node->next;
    }while (cur_node->next != first_node_head);
    printf("\n");
    return 0;
}
