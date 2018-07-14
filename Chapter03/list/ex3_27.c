/*
 * Реализация программы 3.27: Для данных указателей x и t узлов циклического
 * списка напишите фрагмент кода, который перемещает узел,
 * следующий за узлом t, в позицию списка непосредственно за узлом x.
 * */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


Link range_list(const unsigned list_size, int start_item){
    /* Функция создает циклический список, заполняя поля item
     * целыми числами в диапазоне start_item...start_item+list_size-1
     * */

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
    Link head, x, t;

    head = range_list(10, 1);

    // third
    x = head->next->next;

    // six
    t = x->next->next->next;

    // Change between
    Link x_ = x->next;
    x->next = t->next;
    t->next = t->next->next;
    x->next->next = x_;

    Link cur_node = head;
    do{
        printf("%d->", cur_node->item);
        cur_node = cur_node->next;
    }while (cur_node->next != head);
    printf("\n");

    return 0;
}

