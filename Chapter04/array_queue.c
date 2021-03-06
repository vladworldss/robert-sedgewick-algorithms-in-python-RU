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
	N = maxN+1;
    q = calloc(N, sizeof(Item));
    head = 0;
    tail = 0;
}

int queue_empty(){
    return head == tail;
}

void queue_put(Item item){
	if (tail > N){
		errno = EAGAIN;
		QueueError("Queue is full");
	}

    q[tail++] = item;
}

Item queue_get(){
	if ((head == tail) && (head == 0)){
		errno = EAGAIN;
		QueueError("Queue is empty");
	}

	Item res = q[head++];
	int count = N - head;

	/* если очередь в начале разряжена больше, чем наполовину,
	 * то копируем срез. 
	 * */
	if (head > count){
		int i = head, j = 0;

		while (i <= tail){
			q[j++] = q[i++];
		}
		// Обновляем курсоры
		head = 0;
		tail = j;
	}
	else{
		return res;	
	}
    
}

// вернуть методы unsafe для сравнения