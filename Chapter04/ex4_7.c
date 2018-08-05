/*Программа 4.7 
* 
* Клиентская программа для АТД отношения эквивалентности
* Позволяет отделить алгоритм связности от реализации объединения-поиска,
* делая его более доступным.
*/

#include <stdio.h>

#include "UnionFind.h"

int main(int argc, char** argv){
	int p, q, N = atoi(argv[1]);

	UFinit(N);
	while(scanf("%d %d", &p, &q) == 2){
		if (!UFfind(p, q)){
			UFunion(p, q);
			printf("  %d %d\n", p, q);
		}
	}

	return 0;
}	