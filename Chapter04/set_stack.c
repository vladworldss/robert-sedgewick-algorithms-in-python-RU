/* set_stack.c
 *
 * Стек индексных элементов, не содержащий дубликатов
 * */

#include <stdlib.h>

static int *s, *t;
static int N;

void stack_init(int maxN){
    s = calloc(maxN, sizeof(int));
    t = calloc(max, sizeof(int));

    /* Т.к. используем calloc, массив уже инициирован нулями
    * for (int i = 0; i < maxN; i++){
    *    t[i] = 0;
    * }
    * */
    N = 0;
}

int stack_empty(){
    return !N;
}

void stack_push(int item){
    if (t[item] == 1){
        return;
    }

    s[N++] = item;
    t[item] = 1;
}

int stack_pop(){
    N--;
    t[s[N]] = 0;
    return s[N];
}
