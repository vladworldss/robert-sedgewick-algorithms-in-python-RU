/*Программа 3.8 Вычисление ближайшей точки
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../point.h"


float rand_float(){
	return 1.0*rand()/RAND_MAX;
}


int main(int argc, char** argv){
	/*Начальные данные: 
		N - число точек, 
		min_dist - минимальное расстояние
	*/
	int N = atoi(argv[1]);
	int min_dist = atoi(argv[2]);

	// Выделяем память под массив point
	size_t POINT_SIZE = sizeof(Point);
	Point* points = (Point*) calloc(N*POINT_SIZE, POINT_SIZE);

	// Инициализируем массив случайными точками
	for (int i=0; i < N; i++){
		points[i].x = rand_float();
		points[i].y = rand_float();
	}

	int cnt=0;
	for (int i=0; i < N; i++){
		for (int j=i+1; j < N; j++){
			if(distance(points[i], points[j]) < min_dist){
				cnt++;
			}
		}
	}

	printf("%d edges shorter than %d", cnt, min_dist);
	return 0;
}