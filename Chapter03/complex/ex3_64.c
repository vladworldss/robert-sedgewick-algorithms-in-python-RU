/* Программа 3.64
 * Измените программу 3.17 для индивидуальной обработки вводимых
 * строк (необходимо выделять память под каждую строку после считывания ее из стандартного ввода).
 * Можно предположить, что длина каждой строки превышает 100 символов.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_NUM 10
#define MAX_STR_SIZE 1024

/*Сравнивает два символа путем разыменования указателей на str*/
int compare(void* i, void* j){
    return strcmp(*(char**)i, *(char**)j);
}


int main(int argc, char** argv){

    char** a = calloc(MAX_STR_NUM, sizeof(char*));
    char* input_str = calloc(MAX_STR_SIZE, sizeof(char));

    unsigned N=0;

    while(scanf("%s", input_str) && strcmp(input_str, "--Q") && N < MAX_STR_NUM){
        a[N] = calloc(strlen(input_str), sizeof(char));
        strcpy(a[N], input_str);
        N++;
    }

    // Сортируем строки в порядке возрастания
    qsort(a, N, sizeof(char*), compare);

    fprintf(stdout, "Sorted strings:\n");
    for (int i = 0; i < N; i++)
        printf("%s\n", a[i]);
    fprintf(stdout, "\n");

    fprintf(stdout, "Free memory...\n");
    free(input_str);
    for (int i =0; i < N; i++){
        free(a[i]);
    }
    free(a);
    return 0;
}