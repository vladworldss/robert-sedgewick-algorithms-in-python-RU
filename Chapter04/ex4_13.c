/* ex4_13.c
 * Драйвер комплексных чисел (корня из единицы)
 * 
 * Эта клиентская программа выполняет вычисления над комплексными
 * числами с использованием АТД, который позволяет проводить вычисления
 * непосредственно с интересующей нас абстракцией путем объявления
 * переменных типа Complex, которые используются как аргументы и возвращаемые
 * значения функций.
 * Данная программа проверяет реализацию АТД, вычисляя корни из единицы в
 * различных степенях.
 * Программа выводит на печать таблицу.
 * */

#include <stdio.h>
#include <math.h>

#include "Complex.h"

#define PI 3.141592625

int main(int argc, char *argv[]){
	int i, j, N = atoi(argv[1]);
	Complex t, x;
	printf("%dth complex roots of unity\n", N);
	for (i = 0; i < N; i++){
		float r = 2.0*PI*i/N;
		t = complex_init(cos(r), sin(r));
		
		printf("%2d  %6.3f  %6.3f", i, Re(t), Im(t));

		for (x = t, j = 0; j < N-1; j++){
			x = complex_mult(t, x);
		}

		printf("%6.3f  %6.3f\n", Re(x), Im(x));
	}
	return 0;
}