/* Программа 3.64
 * Измените программу 3.17 для индивидуальной обработки вводимых
 * строк (необходимо выделять память под каждую строку после считывания ее из стандартного ввода).
 * Можно предположить, что длина каждой строки превышает 100 символов.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nmax 1000

/*Сравнивает два символа путем разыменования указателей на str*/
int compare(void* i, void* j){
    return strcmp(*(char**)i, *(char**)j);
}


int main(int argc, char** argv){
    unsigned N=0;
    char** a;

    char* s;
    while(scanf("%s", s) == EOF || !strcmp(a[N], "--Q") || N < Nmax){
        a[N] = calloc(strlen(s), sizeof(char));
        strcpy(a[N], s);
        N++;
    }


    fprintf(stdout, "sorted...\n");
    qsort(a, N, sizeof(char*), compare);

    fprintf(stdout, "Sorted strings:\n");
    for (int i = 0; i < N; i++)
        printf("%s\n", a[i]);

    return 0;
}