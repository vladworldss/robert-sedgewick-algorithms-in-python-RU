/* Реализация программы 3.57,
 * которая определяет, является ли данная строка палиндромом, если игнорировать пробелы.
 * */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <locale.h>


int is_palindrome(const char* input){
    unsigned size = (int) strlen(input);
    printf("size = %d\n", size);

    unsigned i, j;
    unsigned res = 1;

    for (i=0, j=size-1; i < j; i++, j--){

        while (input[i] == ' ')
            i++;

        while (input[j] == ' ')
            j--;

        printf("%c-%c\n", input[i], input[j]);

        if (input[i] != input[j]) {
            res = 0;
            break;
        }
    }
    return res;
}


int test(){
    const char* str = "if i had a hifi";
    assert(is_palindrome(str) == 1);
    return 0;
}


int main(int argc, char** argv){
    test();
    return 0;
}