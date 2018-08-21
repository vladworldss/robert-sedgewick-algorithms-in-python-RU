/* ex4_17.c
 *
 * Программа 4.17 Реализация типа данных комплексного числа (дескриптора).
 * */


#include <stdlib.h>
#include <errno.h>

#include "AbsComplex.h"


void ComplexError(char* msg){
    perror(msg);
    exit(1);
}


struct complex{
    float Re;
    float Im;
};

Complex complex_init(float Re, float Im){
    Complex t = calloc(1, sizeof(*t));
    if (t == NULL){
        errno = ENOMEM;
        ComplexError("Memory doesn't allocate");
    }
    t->Re = Re;
    t->Im = Im;
    return t;
}

float Re(Complex z){
    return z->Re;
}

float Im(Complex z){
    return z->Im;
}

Complex complex_mult(Complex a, Complex b){

    return complex_init(
            Re(a)*Re(b) - Im(a)*Im(b),
            Re(a)*Im(b) + Im(a)*Re(b)

    );
}