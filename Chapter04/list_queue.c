/* list_queue.c
 *
 * Реализация интерфейса очереди FIFO на базе связного списка.
 *
 * Различие между очередью FIFO и стеком магазинного типа (Stack.h)
 * состоит в том, что новые элементы вставляются в конец типа, а не в его начало.
 *
 * Программа поддерживает указатель tail на последний узел списка, благодаря
 * чему функция QueuePut может добавлять в список новый узел, связывая его с узлом,
 * на который ссылается указатель tail, с последующим обновлением указателя tail,
 * чтобы он указывал уже на новый узел.
 *
 * Функции QueueGet, QueueInit и QueueEmpty идентичны аналогичным функциям в реализации
 * стека магазинного типа на базе связного списка.
 * */


#include <stdlib.h>

#include "Item.h"
#include "Queue.h"

typedef struct QueueNode* Link;

struct QueueNode{
    Item item;
    Link next;
};

static Link head, tail;

Link new_node(Item item, Link next){
    Link x = calloc(1, sizeof(*x));
    x->item = item;
    x->next = next;
    return x;
}

void queue_init(int maxN){
    head = NULL;
}

int queue_empty(){
    return head == NULL;
}

void queue_put(Item item){
    if (head == NULL){
        head = (tail = new_node(item, head));
        return;
    }

    tail->next = new_node(item, tail->next);
    tail = tail->next;
}

Item queue_get(){
    Item item = head->item;
    Link t = head->next;
    free(head);
    head = t;
    return item;
}