#ifndef CHAPTER03_LIST_H
#define CHAPTER03_LIST_H

typedef int Item;

typedef struct Node* Link;

struct Node{
    Item item;
    Link next;
};

/* Процедура инициализации списка свободных узлов.
 * По запросу создания ноды узел из freelist удаляется.
 * */
void init_nodes(int);


/* Функция создания нового узла.*/
Link new_node(int);


/* Процедура удаления узла. Добавляется в freelist,
 * чтобы по след запросу заново не выделять память, а
 * просто изменить item.
 * */
void free_node(Link);


/* Вставка узла t за узлом x.*/
void insert_next(Link, Link);

/* Удаление след узла за x*/
Link delete_next(Link);

/* Получение след узла за x*/
Link get_next(Link);

/* Возврат значение узла*/
int get_item(Link);


/* Разворачивает текущий список.
 * Вовзращает ссылку на новый head*/
Link reverse(Link);


/* Размер списка*/
unsigned list_size(Link);


/* Печать значений списка.
 * Принимает симвльный разделитель в качестве 2 аргмента.*/
void print_list(Link, const char*);

#endif //CHAPTER03_LIST_H