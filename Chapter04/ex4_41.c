/* ex4_41.c
 * 
 * Напишите  клиентскую  программу,  которая  проверяет  полученный  АТД  оче¬ 
 * редь  с  двухсторонним  доступом  (см.  упражнение  4.37),  считывая  с  командной 
 * строки  в  качестве  первого  аргумента  строку  команд,  подобную  приведенной  в  уп¬ 
 * ражнении  4.34,  после  чего  выполняет  указанные  операции.  В  интерфейс  и  реализа¬ 
 * цию  добавьте  функцию  DQdump  и  распечатайте  содержимое  очереди  с  двухсторон¬ 
 * ним  доступом  после  каждой  операции,  как  это  сделано  на  рис.  4.6.
 */

#include <stdio.h>
#include <string.h>

#include "Deque.h"

#define UPPER_LETTER(ch) ((ch > 64) && (ch < 91))
#define LOWER_LETTER(ch) ((ch > 96) && (ch < 123))
#define ADD_HEAD '+'
#define ADD_TAIL '*'


int main(int argc, char* argv[]){

	char* str = argv[1];
	deque_init(strlen(str));

	while((*str)!= '\0'){
		if (UPPER_LETTER(*str)){
			deque_put(*str);
		}
		else if(LOWER_LETTER(*str)){
			deque_put_head(*str);
		}
		str++;
	}


	return 0;
}