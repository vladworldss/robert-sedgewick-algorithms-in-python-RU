/* ex4_33.c
 *
 * Модифицируйте приведенную в тексте реализацию очереди FIFO 
 * на базе связного списка (list_queue) так, чтобы она вызывала функцию
 * QueurError(), если программа-клиент пытается выполнить операцию get,
 * когда очередь пуста, или если при выполнении put функция calloc не может
 * предоставить необходимый объем памяти.
 **/

#include <stdio.h>
#include <string.h>

#include "Queue.h"

void test_get(){
	printf("test get\n");
	queue_init(2);
	printf("%c\n", queue_get());
}


void test_put(){
	printf("test put\n");

	int N = 3;
	queue_init(N);
	Item item = 0;


	for (int i=0; i < 3*N; i++){
		item = i;
		printf("putting %d into queue\n", item);
		queue_put(item);
	}
}


void test_normal(){
	printf("test normal\n");
	int N = 10;
	queue_init(N);

	for (int i=0; i < 2; i++){
		printf("putting %d into queue\n", i);
		queue_put(i);
	}
	int res;
	for (int i=0; i < 2; i++){
		res = queue_get();
		printf("getting %d from queue\n", res);
	}

	for (int i=0; i < 2; i++){
		printf("putting %d into queue\n", i);
		queue_put(i);
	}

	for (int i=0; i < 2; i++){
		res = queue_get();
		printf("getting %d from queue\n", res);
	}
}

int main(int argc, char **argv){

	if (!strcmp(argv[1], "g"))
		test_get();
	else if (!strcmp(argv[1], "p"))
		test_put();
	else if (!strcmp(argv[1], "n"))
		test_normal();
	else
		printf("Choise from ['g', 'p', 'n']\n");
	return 0;
}