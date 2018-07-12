//
// Created by vladworldss on 06.07.18.
//

#include <stdlib.h>

#include "list.h"


Link freelist;

void init_nodes(const int N){
    /* Процедура инициализации списка свободных узлов.
     * По запросу создания ноды узел из freelist удаляется.
     * */

    freelist = calloc(N+1, sizeof(*freelist));

    // уточнить про head
    for (int i = 0; i < N+1; i++){
        freelist[i].next = &freelist[i+1];
    }
    freelist[N].next = NULL;
}


Link new_node(int value){
    /* Функция создания нового узла.*/

    Link x = delete_next(freelist);
    x->item = value;
    x->next = x;
    return x;
}


void free_node(Link x){
    /*Процедура удаления узла. Добавляется в freelist,
     * чтобы по след запросу заново не выделять память, а
     * просто изменить item.
     * */

    insert_next(freelist, x);
}


void insert_next(Link x, Link t){
    /*Вставка узла t за узлом x.*/

    t->next = x->next;
    x->next = t;
}


Link delete_next(Link x){
    /*Удаление след узла за x*/

    Link t = x->next;
    x->next = t->next;
    return t;
}


Link get_next(Link x){
    /*Получение след узла за x*/

    return x->next;
}


int get_item(Link x){
    /*Возврат значение узла*/

    return x->item;
}