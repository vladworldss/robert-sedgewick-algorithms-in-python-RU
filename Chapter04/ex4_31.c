/* ex4_31.c
 * В последовательности 
 * E A S * Y * Q U E * * * S T * * * I O * N * * *
 * буква означает операцию PUT, звездочка - операцию GET.
 * Найдите последовательность значений, возвращаемых операциями get, когда 
 * эта последовательность операций выполняется над первоначально пустой очередью FIFO.
 **/

#include <stdio.h>
#include <string.h>

#include "Queue.h"
#define STAR '*'
const char SEQ[] = "EAS*Y*QUE***ST***IO*N***";
const char* SEQ_PRT = "EAS*Y*QUE***ST***IO*N***S*";


int main(int argc, char **argv){
	const int seq_size = strlen(SEQ);
	queue_init(seq_size);

	for (int i=0; i < seq_size; i++){
		if (SEQ[i] == STAR){
			printf("%c\n", queue_get());
		}
		else {
			queue_put(SEQ[i]);
		}
	}

	printf("\n");

	while (*SEQ_PRT != '\n'){
		if (*SEQ_PRT == STAR){
			printf("%c\n", queue_get());
		}
		else {
			queue_put(*SEQ_PRT);
		}
		SEQ_PRT++;
	}

	return 0;
}