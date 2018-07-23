/* Программа 3.17 Сортировка массива строк */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Nmax 1000
#define Mmax 10000

char buf[Mmax];
int M = 0;

/*Сравнивает два символа путем разыменования указателей на str*/
int compare(void* i, void* j){
    return strcmp(*(char**)i, *(char**)j);
}

//TODO: сделать трассировку

int main(int argc, char** argv){
    int i, N;
    char* a[Nmax];

    for (N=0; N < Nmax; N++){
        a[N] = &buf[M];
        if (scanf("%s", a[N]) == EOF || !strcmp(a[N], "--Q")){
            break;
        }

        M += strlen(a[N])+1;
    }

    fprintf(stdout, "sorted...\n");
    qsort(a, N, sizeof(char*), compare);

    fprintf(stdout, "Sorted strings:\n");
    for (i = 0; i < N; i++)
        printf("%s\n", a[i]);

    return 0;
}