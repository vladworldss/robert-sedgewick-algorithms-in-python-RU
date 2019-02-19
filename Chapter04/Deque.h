/* Deque.h
 *
 * Created by vladworldss on 20.08.18.
 * Интерфейс очереди с двухсторонним доступом.
 * */

#ifndef CHAPTER04_DEQUE_H
#define CHAPTER04_DEQUE_H

#include "Item.h"

void DequeError(char*);
void deque_init(int);
int deque_empty();
unsigned deque_size();
void deque_put(Item);
void deque_put_head(Item);

Item deque_get();
Item deque_get_tail();

#endif //CHAPTER04_DEQUE_H
