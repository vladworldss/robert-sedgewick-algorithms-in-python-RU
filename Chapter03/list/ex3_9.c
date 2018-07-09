/*
 * Реализация Программы 3.9 Пример циклического списка
 * (задача Иосифа)
*/
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

	// интервал удаления узла
	int M = atoi(argv[2]);
	if (M < 1){
        perror("Bad remove period");
        return -1;
    }

    // Выделяем память под ссылку
	const Link l_first_node = calloc(1, sizeof(*l_first_node));
	l_first_node->item = 1;
	l_first_node->next = l_first_node;

	// т.к. мы пока создали лишь 1 узел - next смотрит на себя
	Link l_current_node = l_first_node;

	for (int i=2; i <= N; i++){
	    l_current_node = (l_current_node->next = calloc(1, sizeof(*l_current_node)));
	    l_current_node->item = i;
	    l_current_node->next = l_first_node;
	}

    // Печатаем список
    Link cur_node = l_first_node;
    for (int i=1; i <= N; i++){
        printf("%d->", cur_node->item);
        cur_node = cur_node->next;
    }
    printf("\n");

    /*  Запускаем рулетку.
    *   Замечание! Начинаем мы с последнего элемента,
    *   чтобы исключить "слепую" зону для 1-го элемента.
    */
    printf("Started from: %d\n", l_current_node->item);
    while (l_current_node != l_current_node->next){
        /* т.к. мы должны удалить M-й узел,
         * то останавливаемся в 1-м шаге и по
         * ссылке получаем необходимый узел
        */

        for (int i=1; i < M; i++){
            l_current_node = l_current_node->next;
        }

        printf("deleted item: %d\n", l_current_node->next->item);
        l_current_node->next = l_current_node->next->next;
    }

    printf("The Highlander: %d\n", l_current_node->item);
    free(l_current_node);
    free(l_first_node);
    return 0;
}