/* AbsComplex.h
 *
 * Программа 4.16 АТД первого класса для комплекного числа
 *
 * Этот интерфейс предоставляет клиентским программам дескрипторы
 * на объекты комлексных чисел, но не дает никакой информации о представлении -
 * это struct, которая никак не описана, за исключением имени дескриптора.
 * */

#ifndef CHAPTER04_ABSCOMPLEX_H
#define CHAPTER04_ABSCOMPLEX_H

typedef struct complex* Complex;

Complex complex_init(float, float);

// Получение действительной части
float Re(Complex);

// Получение мнимой части
float Im(Complext);

// Перемножение комплексного числа
Complex complex_mult(Complex, Complex);

#endif //CHAPTER04_ABSCOMPLEX_H
