//
// Created by vladworldss on 03.08.18.
//

#ifndef ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_ITEM_H
#define ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_ITEM_H

#include <string.h>

// Определяем типы элементов
#ifndef USE_CHAR_ITEM

typedef int Item;
#define eq(A, B) (A == B)

#else
typedef char Item;
#define  eq(A, B) (strcmp(A, B) == 0)

#endif


#define PLUS '+'
#define MUL  '*'
#define ZERO '0'
#define NINE '9'
#define OPEN_BR '('
#define CLOSE_BR ')'

#endif //ROBERT_SEDGEWICK_ALGORITHMS_IN_PYTHON_RU_ITEM_H
