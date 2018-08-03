/* Программа 4.5
 * Реализация стека магазинного типа на базе связного типа.
 *
 * В этой программе АТД стека реализуется через связный список.
 * В ней используется вспомогательная функция new_node, в задачу которой входит
 * выделение памяти под узел, присвоение его полям значений аргументов функции
 * и возврат ссылки на узел.
 * */

#include <stdlib.h>

#include "Item.h"

typedef struct StackNode* Link;
struct  StackNode {
    Item item;
    Link next;
};

static Link head;

Link new_node(Item item, Link next){
    Link x = calloc(1, sizeof(*x));
    x->item = item;
    x->next = next;
    return x;
}

void stack_init(int max_elems){
    head = NULL;
}

int stack_empty(){
    return head == NULL;
}

void stack_push(Item item){
    head = new_node(item, head);
}

Item stack_pop(){
    Item item = head->item;
    Link t = head->next;
    free(head);
    head = t;
    return item;
}
