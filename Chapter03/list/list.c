//
// Created by vladworldss on 06.07.18.
//
#include "list.h"


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

long list_size(Link head){
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
