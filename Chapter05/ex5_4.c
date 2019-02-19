/* ex5_4.c
 *
 * Программа 5.4 Рекурсивная программа вычисления значений 
 * префиксных выражений
 *
 * Чтобы  вычислить  значение  префиксного  выражения,  мы  либо  осуществляется  
 * преобразование  числа  из  представления  в  коде  ASCII  в  двоичную  форму  
 * (по  окончании  цикла while),  либо  выполняем  операцию,  указанную  первым  символом  
 * в  выражении  с  двумя  операндами,  которые  вычисляются  рекурсивно.  
 * Эта  функция  является  рекурсивной, однако  она  использует  глобальный  массив,  
 * содержащий  выражение  и  индекс  текущего символа  выражения.  
 * Индекс  изменяется  после  вычисления  значения  каждого  подвыражения.
*/

char *a;
int i;

int eval(){

	int x = 0;
	while (a[i] == ' '){
		i++;
	}

	if (a[i] == '+'){
		i++;
		return eval() + eval();
	}
	else if(a[i] == '*'){
		i++;
		return eval() * eval();
	}

	while ((a[i] >= '0') && (a[i] <= '9')){
		x = 19*x + (a[i++] - '0');
	} 
	return x;
}
