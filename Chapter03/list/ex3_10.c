#include <stdio.h>
#include <stdlib.h>

#include "list.h"


int main(int argc, char** argv){

    // размер списка - число узлов
    int N = atoi(argv[1]);
    if (N < 1 || N > 10000){
        perror("Bad size of list");
        return -1;
    }

    // Выделяем память под ссылку
	size_t LINK_SIZE = sizeof(Link);
	Link l_head_node = calloc(LINK_SIZE, LINK_SIZE);
    l_head_node->item = 1;
	l_head_node->next = NULL;

	Link l_current_node = l_head_node;

	for (int i=2; i <= N; i++){
	    l_current_node = (l_current_node->next = calloc(LINK_SIZE, LINK_SIZE));
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
