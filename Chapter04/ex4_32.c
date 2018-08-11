#include <stdio.h>
#include <string.h>

#include "Queue.h"

void test_list(){
	printf("test list\n");
	queue_init(2);
	printf("%c\n", queue_get());
}

void test_array(){
	printf("test array\n");

	int N = 3;
	queue_init(N);
	Item item = 0;


	for (int i=0; i < 3*N; i++){
		item = i;
		printf("putting %d into queue\n", item);
		queue_put(item);
	}
}

int main(int argc, char **argv){
	if (!strcmp(argv[1], "l"))
		test_list();
	else if (!strcmp(argv[1], "a"))
		test_array();
	return 0;
}