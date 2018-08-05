/* Union.h
 * Заголовочный файл интерфеса АТД отношения эквивалентности.
 * Предоставляет интерфейс из Chapter01 определение задачи связности.
*/


#ifndef ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_UNIONFIND_H
#define ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_UNIONFIND_H

void UFinit(int);
int UFfinf(int, int);
void UFunion(int, int);

#endif