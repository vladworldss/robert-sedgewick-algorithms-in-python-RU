/* ex4_38.c
 *
 * Для интерфейса очереди с двухсторонним доступом напишите реализацию,
 * в которой в качестве базовой структуры данных используется массив.
 * */

#include <stdlib.h>
#include <errno.h>

#include "Deque.h"

// Глобальные переменные
static int head, tail;
static Item* deque;
static int Nmax;


void DequeError(char* msg){
    perror(msg);
    exit(1);
}


void deque_init(int max_elems){
    deque = calloc(max_elems, sizeof(Item));
    head = tail = 0;
    Nmax = max_elems;
}

int deque_empty(){
    return (tail == 0);
}

unsigned deque_size(){
    return tail;
}

int deque_full(){
    return ((tail >= Nmax) || (head <= 0));
}


void deque_put(Item node){
    if (deque_is_full()){
        DequeError("Deque is full");
    }
    deque[tail++] = node;
}

void deque_put_head(Item node){
    if (deque_full()){
        DequeError("Deque is full");
    }

    // если есть место в начале
    else if(head > 0){
        deque[head--] = node;
    }

    // если нет - проверяем, если ли еще место в конце и копируем
    else{
        for (int i=tail; i >= head; i--){
            deque[i+1] = deque[i];
        }
        tail++;
    }
}

Item deque_get(){
    if (deque_empty()){
        DequeError("Deque is empty");
    }
    return deque[head++];
}


Item deque_get_tail(){
    if (deque_empty()){
        DequeError("Deque is empty");
    }
    return deque[tail--];
}
