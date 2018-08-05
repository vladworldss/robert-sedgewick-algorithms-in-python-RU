/* Программа 3.20
 * Двумерный массив поиска
 *
 * Программа показывает эффективность применения двумерного массива
 * связных списков  для вычислений программы 3.8
 *
 * Единичный квадрат разбивается на сетку. Создается двумерный массив
 * связных списков, причем каждой ячейке (квадрату) сетки соответсвует
 * один список.
 *
 * Размер ячеек достаточно мал, чтобы все точки в пределах расстояния d
 * от каждой точки попадали либо в одну ячейку с ней, либо в смежную ячейку.
 *
 * Функция malloc2d подобна такой же функции из программы 3.16, но
 * она создана для объектов типа Link, а не int.
 * */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../common/ex3_3.h"


typedef struct Node* Link;

struct Node{
    Point p;
    Link next;
};

Link** grid;
int G;
float d;
int cnt = 0;

gridinsert(float x, float y){
	int i, j;
	Link s;

	int X = x*G + 1;
	int Y = y*G + 1;
	
	Link t = calloc(1, sizeof(*t));
	t->p.x = x;
	t->p.y = y;

	for (i = X-1; i <= X+1; i++)
		for (j = Y-1; j <= Y+1; j++)
			for (s = grid[i][j]; s != NULL; s = s->next)
				if (distance(s->p, t->p) < d){
					cnt++;
				}

	t->next = grid[X][Y];
	grid[X][Y] = t;
}

Link** malloc2d(int r, int c){
    Link** t = calloc(r, sizeof(*t));
    for (int i=0; i < r; i++){
        t[i] = calloc(c, sizeof(Link));
    }
    return t;
}


float randFloat(){
	return (rand(100) % 100) / RAND_MAX;
}


int main(int argc, char** argv){
    int i, j, N = atoi(argv[1]);
    d = atof(argv[2]);
    G = 1/d;

    grid = malloc2d(G+2, G+2);
    for (i = 0; i < G+2; i++)
    	for (j = 0; j < G+2; j++)
    		grid[i][j] = NULL;

    for (i = 0; i < N; i++)
    	gridinsert(randFloat(), randFloat());

   	printf("%d edges shorter than %f\n", cnt, d);

}