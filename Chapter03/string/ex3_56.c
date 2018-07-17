/* Реализация программы 3.56.
 * Напишите программу, которая принимает строку в качестве
 * аргумента и распечатывает таблицу, отображающую встречаемые в строке
 * символы с частотой появления каждого из них.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256


int main(int argc, char** argv){
     char* input_str = argv[1];
     printf("*input_str = %s\n", input_str);

     unsigned* res = calloc(SIZE, sizeof(unsigned));

     int idx;

     char* a = input_str;
     unsigned size = 0;

     while ((*a) != '\0'){
         printf("ch=%c\n", *a);

         idx = (int) *a;
         printf("idx=%d\n", idx);
         res[idx]++;
         a++;
         size++;
     }

     double freq;
     printf("print array\n");
     printf("len array = %d\n", size);
     for (int i=0; i<SIZE; i++){
         if (res[i]){
             freq = (float) res[i] / size;
             printf("%c=%d. freq=%0.3f\n", i, res[i], freq);
         }
     }
     printf("\n");
     return 0;
 }