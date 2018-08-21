/* ex4_15.c
 *
 * Программа 4.15 Реализация типа данных комплексного числа.
 *
 * Эти реализации функций для типа данных комплексного числа достаточно просты.
 * Тем не менее, мы предпочитаем не отделять его от определения типа Complex,
 * который определен в интерфейсе для удобства клиентских программ.
 * */

#include "Complex.h"

Complex complex_init(float Re, float Im){
    Complex t;
    t.Re = Re;
    t.Im = Im;
    return t;
}

float Re(Complex z){
    return z.Re;
}

float Im(Complex z){
    return z.Im;
}

Complex complex_mult(Complex a, Complex b){
    Complex t;
    t.Re = a.Re*b.Re - a.Im*b.Im;
    t.Im = a.Re*b.Im + a.Im*b.Re;
    return t;
}
