/* ex5_17.c
 *
 * Напишите рекурсивную программу, которая находит максимальный элемент
 * в связном списке.
 * */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "../Chapter04/Item.h"
#include "../Chapter04/Item.h"


typedef struct Node* Link;

struct Node{
    Item item;
    Link next;
};


/* Поиск максимального элемента в списке*/
Item max_node_item(Link head, Item max_item){
    if (head == NULL)
        return max_item;

    if (head->item > max_item)
        max_item = head->item;
    max_node_item(head->next, max_item);
}


int main(int argc, char** argv){
    printf("ex5_17 starting...\n");

    Link head = calloc(1, sizeof(*head));
    head->item = 0;
    head->next = NULL;

    Link cur_node = head;
    for(int i = 10; i < 20; i++){
        cur_node = (cur_node->next = calloc(1, sizeof(*cur_node)));
        cur_node->item = i%10;
        cur_node->next = NULL;
    }

    assert(max_node_item(head, head->item) == 9);
    printf("exit\n");
    return 0;
}