/* Программа 4.4
 * Реализация стека магазинного типа на базе массива
 *
 * В этой реализации N элементов стека хранятся как элементы массива:
 * s[0], ..., s[N-1], начиная с первого занесенного элемента
 * и завершая последним.
 *
 * Верхушка стека есть позиция s[N].
 * Максимальное количество элементов, которое может
 * вмещать стек, клиентская программа, передает в виде
 * аргумента в функцию stack_init, ращмешающую в памяти массив заданного размера.
 * Код не проверяет какие ошибки, как помещение элемента в переполненный стек
 * (или выталкивание элемента из пустого стека).
 * */

#include <stdlib.h> // for calloc()

#include "Item.h"
#include "Stack.h"

static Item* s;
static int N;

void stack_init(int max_elems){
    s = calloc(max_elems, sizeof(Item));
    N = 0;
}


int stack_empty(){
    return N == 0;
}

void stack_push(Item item){
    s[N++] = item;
}

Item stack_pop(){
    return s[--N];
}