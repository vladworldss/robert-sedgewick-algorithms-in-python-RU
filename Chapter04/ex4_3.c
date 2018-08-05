/* Программа 4.3
* Преобразование из инфиксной формы в постфиксную
* 
* Стек содержит содержит символы (в Item.h с помощью макроса это определяем)
* Для преобразования (A+B) в постфиксную форму AB+ левая скобка игнорируется, 
* в выходной поток записывается А, в стеке запоминается знак +,
* в выходной поток записывается B и затем при встрече правой скобки из 
* стека извлекается знак +, и он также записывается в выходной поток.
*/

#include <stdio.h>
#include <string.h>

#include "Item.h"
#include "Stack.h"


int main(int argc, char** argv){
	printf("ex4_3 starting...\n");

	char* a = argv[1];
    int N = strlen(a);

    stack_init(N);
    for (int i=0; i<N; i++){
    	if (a[i] == CLOSE_BR){
    		printf("%c ", stack_pop());
    	}
    	else if ((a[i] == PLUS) || (a[i] == MUL)){
    		stack_push(a[i]);
    	}
    	else if ((a[i] >= ZERO) && (a[i] <= NINE)){
    		printf("%c ", a[i]);
    	}
    }
    printf("\n");
	return 0;
}