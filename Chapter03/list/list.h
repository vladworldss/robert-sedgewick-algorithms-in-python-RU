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

void init_nodes(int);

Link new_node(int);

void free_node(Link);

void insert_next(Link, Link);

Link delete_next(Link);

Link get_next(Link);

int get_item(Link);

#endif //CHAPTER03_LIST_H