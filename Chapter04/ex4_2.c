//
// Created by vladworldss on 03.08.18.
//

#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "Stack.h"

#define PLUS '+'
#define MUL  '*'
#define ZERO '0'
#define NINE '9'


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

        else if((a[i] >= ZERO) && (a[i] <= NINE)){
            stack_push(0);
        }

        while((a[i] >= ZERO) && (a[i] <= NINE)){
            stack_push(10*stack_pop() + (a[i++] - ZERO));
        }
    }
    printf("%d \n", stack_pop());
}
