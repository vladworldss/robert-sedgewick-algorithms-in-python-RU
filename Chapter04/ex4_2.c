//
// Created by vladworldss on 03.08.18.
//

#include <stdio.h>
#include <string.h>

#include "Item.h"
#include "Stack.h"


int main(int argc, char** argv){
    printf("ex4_2 starting...\n");

    char* a = argv[1];
    int N = strlen(a);

    stack_init(N);

    for(int i=0; i<N; i++){

        if (a[i] == PLUS){
            stack_push(stack_pop() + stack_pop());
        }

        else if (a[i] == MUL){
            stack_push(stack_pop() * stack_pop());
        }

        // инициализируем стек нулем, чтобы избежать StackPopError
        else if((a[i] >= ZERO) && (a[i] <= NINE)){
            stack_push(0);
        }

        /* переводим число, пока не встретиться НЕ-числовой символ
        * 123 =
        *    1. stack.push(0) --> stack([0])
        *    2. stack.push(10*stack.pop() --> 10*0 + ('1'-'0')) --> stack([1])
        *    3. stack.push(10*stack.pop() --> 10*1 + ('2'-'0')) --> stack([12])
        *    3. stack.push(10*stack.pop() --> 10*12 + ('3'-'0')) --> stack([123])
        *
        * В бесконечном цикле происходит постфикс_инкремент указателя строки
        */
        while((a[i] >= ZERO) && (a[i] <= NINE)){
            stack_push(10*stack_pop() + (a[i++] - ZERO));
        }
    }
    printf("%d \n", stack_pop());
}
