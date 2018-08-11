/* array_queue.c
 *
 * К содержимому очереди относятся все элементы массива, расположенные
 * между индексами head и tail; при этом учитывается переход с конца
 * массива на элемент с индексом 0 в начале массива.
 * Если индексы head и tail равны, очередь считается пустой, однако если они
 * стали равными в результате выполнения операции put, очередь считается полной.
 *
 * Проверка на такие ошибочные ситуации не выполняется, но размер массива делается
 * на 1 больше максимального числа элементов очереди, ожидаемого программой-клиентом.
 * */

#include <stdlib.h>
#include <errno.h>

#include "Item.h"
#include "Queue.h"

static Item* q;
static int N, head, tail;

void QueueError(char* msg){
    perror(msg);
    exit(1);
}


void queue_init(int maxN){
    q = calloc(maxN+1, sizeof(Item));
    N = maxN+1;
    head = N;
    tail = 0;
}

int queue_empty(){
    return head % N == tail;
}

void queue_put(Item item){
	if (tail > N){
		errno = EAGAIN;
		QueueError("Queue is full");
	}

    q[tail++] = item;
    // tail = tail % N;
}

Item queue_get(){
    head = head % N;
    return q[head++];
}
