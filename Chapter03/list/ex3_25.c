//
// Created by vladworldss on 06.07.18.
//

#include <stdlib.h>
#include <assert.h>

#include "list.h"


/*
 * Метод определяет число узлов между узлами,
 * на которые ссылаются l_source_node и l_dest_node.
 * Подразумеватеся, что ссылки l_source_node и l_dest_node
 * принадлежат одному списку, иначе - зацикливание.
 * */
int list_distance(Link l_source_node, Link l_dest_node){
    Link cur_node = l_source_node;
    int count;
    for(count=0; cur_node->next != l_dest_node; cur_node = cur_node->next){
        count++;
    }
    return count;
}


Link range_list(const unsigned list_size, int start_item){

    // Выделяем память под ссылку
    const Link l_first_node = calloc(1, sizeof(*l_first_node));

    l_first_node->item = start_item;
    l_first_node->next = l_first_node;

    // т.к. мы пока создали лишь 1 узел - next смотрит на себя
    Link l_current_node = l_first_node;

    for (unsigned i=start_item+1; i <= list_size; i++){
        l_current_node = (l_current_node->next = calloc(1, sizeof(*l_current_node)));
        l_current_node->item = i;
        l_current_node->next = l_first_node;
    }
    return l_first_node;
}


int main(int argc, char** argv){

    Link head = range_list(10, 1);
    Link sec_node = head->next;

    Link cur_node = head;
    for(int i=0; i<8; i++){
        cur_node=cur_node->next;
    }

    int distance = (cur_node->item - sec_node->item) - 1;
    assert(list_distance(sec_node, cur_node) ==  distance);
    return 0;
}