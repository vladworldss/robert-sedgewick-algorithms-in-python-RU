/* Conplex.h
 *
 * Программа 4.14 Интерфейс АТД первого класса для комплексного числа
 *
 * Этот интерфейс для комплексного числа включает описание typedef, которое
 * позволяет реализациям объявлять переменные типа Complex и использовать
 * эти переменные в качестве аргументов и возвращаемых значений функций.
 *
 * Однако этот тип данных не является абстрактным, поскольку данная реализация
 * не сокрыта от клиентских программ.
 * */

#ifndef CHAPTER04_COMPLEX_H
#define CHAPTER04_COMPLEX_H


typedef struct {
    float Re;
    float Im;
} Complex;


Complex complex_init(float, float);

// Получение действительной части
float Re(Complex);

// Получение мнимой части
float Im(Complext);

// Перемножение комплексного числа
Complex complex_mult(Complex, Complex);
#endif //CHAPTER04_COMPLEX_H
