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

	Node head_a;
	Link l_a_node = &head_a;

	Link l_cur_node = l_a_node;
	for (int i = 0; i < N; i++){
		l_cur_node->next = malloc(sizeof(*l_cur_node));
		l_cur_node = l_cur_node->next;
		l_cur_node->next = NULL;
		l_cur_node->item = rand() % 100;
	}

	Node head_b;
	Link l_b_node = &head_b;
	l_b_node->next = NULL;

	Link l_a_cur_node, l_b_cur_node;
	for (
		l_a_cur_node = l_a_node->next, l_next_node; 
		l_a_cur_node != NULL; 
		l_a_cur_node = l_next_node
		){

			l_next_node = l_a_cur_node->next;
			for (
				l_b_cur_node = l_b_node; 
				l_b_cur_node->next != NULL;
				l_b_cur_node = l_b_cur_node->next
				){
					if (l_b_cur_node->next->item > l_a_cur_node->item){
						break;
					}
				}

			l_a_cur_node->next = l_b_cur_node->next;
			l_b_cur_node->next = l_a_cur_node;
		}
}