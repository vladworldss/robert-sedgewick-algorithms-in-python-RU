#include <stdio.h>

void test_1(void){
	int seq[] = {0, 1, 2, 3, 4, 5};
	for (int i=0; i < 6; i++)
		printf("%d ", seq[i]);
	printf("\n");


	int i = 0;
	int tail = 5;
	while (i <= tail){
		seq[i++] = seq[i+1];
	}

	printf("Result:\n");
	i = 0;
	while(i < tail){
		printf("%d ", seq[i]);
		i++;
	}

	printf("\n");

}


void test_2(){
	int q[] = {0, 0, 0, 0, 0, 0, 6, 7, 8, 9, 10};
	int N = 10;
	int head = 6;
	int tail = 10;

	int res = q[head++];

	/* если очередь в начале разряжена больше, чем наполовину,
	 * то копируем срез. 
	 * */
	int count = N - head;
	if (head > count){
		int i = head;
		int j = 0;

		while (i <= tail){
			q[j++] = q[i++];
		}
		head = 0;
		tail = j;
		printf("head=%d, tail=%d \n", head, tail);
	}
	
	printf("Result:\n");
	int i = 0;
	while(i < tail){
		printf("i[%d] = %d; ", i, q[i]);
		i++;
	}

	printf("\n");

}


int main(int argc, char argv[]){
	test_2();
	return 0;

}