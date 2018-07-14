#ifndef CHAPTER03_LIST_H
#define CHAPTER03_LIST_H

typedef int Item;

typedef struct Node* Link;

struct Node{
    Item item;
    Link next;
};

Link reverse(Link);

unsigned list_size(Link);

#endif //CHAPTER03_LIST_H