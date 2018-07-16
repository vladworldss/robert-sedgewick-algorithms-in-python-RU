/* Реализация программы 3.47: напишите программу,
 * которая удаляет все узлы связного списка.
 * */

#include <stdio.h>
#include <stdlib.h>

#include "lish.h"


int main(int argc, char** argv){

    unsigned N = atoi(argv[1]);
    init_nodes(N);

    // create nodes
    Link head = new_node(1);
    Link cur_node = head;
    for (int i = 2; i <= N; i++){
        cur_node = (cur_node->next = new_node(i));
    }

    // delete nodes

    return 0;
}


