/* Queue.h
 *
 * Интерфейс очереди FIFO.
 * Интерфейс идентичен интерфейсу стека магазинного типа из Stack.h,
 * за исключением имен структуры.
 * Эти два АТД отличаются только спецификациями, что совершенно не
 * отражается на коде интерфейса.
 * */

#ifndef CHAPTER04_QUEUE_H
#define CHAPTER04_QUEUE_H

#include "Item.h"

void queue_init(int);
int queue_empty();
void queue_put(Item);
Item queue_get();

#endif //CHAPTER04_QUEUE_H
