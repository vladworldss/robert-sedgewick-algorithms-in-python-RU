#include <stdio.h>
#include <stdlib.h>

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


int main(int argc, char** argv){

    // размер списка - число узлов
    int N = atoi(argv[1]);
    if (N < 1 || N > 10000){
        perror("Bad size of list");
        return -1;
    }

    // Выделяем память под ссылку
	Link l_head_node = calloc(1, sizeof(*l_head_node));
    l_head_node->item = 1;
	l_head_node->next = NULL;

	Link l_current_node = l_head_node;

	for (int i=2; i <= N; i++){
	    l_current_node = (l_current_node->next = calloc(1, sizeof(*l_current_node)));
	    l_current_node->item = i;
	    l_current_node->next = NULL;
	}

    // Печатаем список
    Link cur_node = l_head_node;
    for (int i=1; i <= N; i++){
        printf("%d->", cur_node->item);
        cur_node = cur_node->next;
    }
    printf("\n");

    Link l_rev_node = reverse(l_head_node);

    // Печатаем список
    cur_node = l_rev_node;
    for (int i=1; i <= N; i++){
        printf("%d->", cur_node->item);
        cur_node = cur_node->next;
    }
    printf("\n");
    return 0;
}