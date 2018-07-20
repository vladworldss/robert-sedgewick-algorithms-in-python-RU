/* Реализация программы 3.58
 * Предположим, для каждой строки выделена память.
 * Напишите версию функций strcpy и strcat, которые выделяют память и
 * возвращают указатель на новую строку с результатом.
 * */
#include <stdlib.h>

#define MAX_SIZE 10000

unsigned len(const char* str){
    unsigned size = 0;

    while((*str != '\0') || (size < MAX_SIZE)){
        str++;
        size++;
    }
    return size;
}


const char* str_cpy(const char* input_str){
    unsigned size = len(input_str);
    char* new_str[size+1];

    while (*new_str++ = *input_str++);
    return new_str;
}


const char* str_cat(const char* input_str){
    unsigned size = len(input_str);
    char* new_str[size+1];

}