/* ex4_39.c
 *
 * Для интерфейса очереди с двухсторонним доступом запишите реализацию,
 * в которой в качетсве базовой структуры данных используется двухсвязный список.
 * */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "Deque.h"

typedef struct DequeNode* Link;

struct DequeNode{
    Item item;
    Link next;
};


static Link head, tail;
static unsigned N;
static unsigned USED_NODES;


void DequeError(char* msg){
    perror(msg);
    exit(1);
}


Link new_node(Item item, Link next){
    Link x = calloc(1, sizeof(*x));
    if (x == NULL){
        errno = ENOMEM;
        DequeNode("Memory doesn't allocate");
    }

    x->item = item;
    x->next = next;
    return x;
}


void deque_init(int max_values){
    N = max_values;
    head = tail = NULL;
    USED_NODES = 0;
}


int deque_empty(){
    return ((head == NULL) && (tail == NULL));
}

unsigned deque_size(){
    return USED_NODES;
}

// -------------------------
//-------- PUT
// -------------------------

/*Вставка в дек с конца*/
void deque_put(Item item){
    if (head == NULL){
        head = (tail = new_node(item, head));
    }

    else {
        tail->next = new_node(item, tail->next);
        tail = tail->next;
    }
    USED_NODES++;
}

/*Вставка в дек с головы*/
void deque_put_head(Item item){
    if (head == NULL){
        head = (tail = new_node(item, head));
    }

    else {
        head = new_node(item, head);
    }
    USED_NODES++;
}


// -------------------------
//-------- GET
// -------------------------
Item deque_get(){
    if (deque_empty()){
        errno = EAGAIN;
        DequeNode("Deque is empty");
    }

    Item item = head->item;
    Link t = head->next;
    free(head);
    head = t;
    USED_NODES--;
    return item;
}

Item deque_get_tail(){
    if (deque_empty()){
        errno = EAGAIN;
        DequeNode("Deque is empty");
    }

    Item item = tail->item;
    Link t = tail->next;
    free(tail);
    tail = t;
    USED_NODES--;
    return item;
}


void deque_dump(){
    Link cur_node = head;

    unsigned i = 0;
    while(cur_node != tail){
        printf("[]%d --> ", i, cur_node->item);
        cur_node = cur_node->next;
        i++;

        if (i > 9) {
            printf("\n");
            i = 0;
        }
    }
}