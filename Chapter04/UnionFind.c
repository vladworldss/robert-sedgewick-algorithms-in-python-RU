/* UnionFind.c
 *
 * Реализация взвешенного быстрого объединения из главы 1 в совокупности
 * с интерфейсом упаковывает код в форме, которая обеспечивает удобство его
 * использования в других приложениях. В данной реализации используется локальная
 * функция find.
*/

#include <stdlib.h>

#include "UnionFind.h"

/* Массив id служит для хранения дерева связности. 
 * В каждой ячейке хранится индекс родителя.
 *
 * Массив sz служит для хранения длины ветви. Используется для
 * оптимизации объединения (к большему прибавляется меньшее)
 */
static int *id, *sz;

void UFinit(int N){
	
	id = calloc(N, sizeof(int));
	sz = calloc(N, sizeof(int));
	
	for (int i=0; i < N; i++){
		id[i] = i;
		sz[i] = 1;
	}
}


static int find(int x){
	int i = x;
	while(i != id[i]){
		i = id[i];
	}
	return i;
}

int UFfind(int p, int q){
	return (find(p) == find(q));
}


void UFunion(int p, int q){
	int i = find(p);
	int j = find(q);

	// если указывают на один родитель
	if (i == j){
		return ;
	}

	else if (sz[i] < sz[j]){
		id[i] = id[j];
		sz[j] += sz[i];
	}

	else {
		id[j] = id[i];
		sz[i] += sz[j];
	}
}

