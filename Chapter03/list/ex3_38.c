//
// Created by vladworldss on 13.07.18.
//

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


Link copy_list(Link source_head){
    Link dest_head = calloc(1, sizeof(*dest_head));;

    Link source_cur = source_head, dest_cur = dest_head;

    while ((source_cur->next != NULL) || (source_cur->next != source_head)){
        dest_cur->item = source_cur->item;
        source_cur = source_cur->next;
        dest_cur = (dest_cur->next = calloc(1, sizeof(*dest_cur)));
    }
    dest_cur->next = NULL;
    return dest_head;
}


int main(int argc, char** argv){

    // размер списка - число узлов
    int N = atoi(argv[1]);
    if (N < 2 || N > 10000){
        perror("Bad size of list");
        return -1;
    }

    // Выделяем память под ссылку
    const Link l_first_node = calloc(1, sizeof(*l_first_node));
    l_first_node->item = 1;
    l_first_node->next = NULL;

    Link l_current_node = l_first_node;
    for (int i=2; i <= N; i++){
        l_current_node = (l_current_node->next = calloc(1, sizeof(*l_current_node)));
        l_current_node->item = i;
        l_current_node->next = NULL;
    }
    l_current_node->next = l_first_node;

    // Печатаем список
    Link cur_node = l_first_node;
    for (int i=1; i <= N; i++){
        printf("%d->", cur_node->item);
        cur_node = cur_node->next;
    }
    printf("\n");

    Link new_list = copy_list(l_first_node);

    // Печатаем список
    cur_node = new_list;
    for (int i=1; i <= N; i++){
        printf("%d->", cur_node->item);
        cur_node = cur_node->next;
    }
    printf("\n");

    free(l_current_node);

    return 0;
}