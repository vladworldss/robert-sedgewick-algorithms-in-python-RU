//
// Created by vladworldss on 24.07.18.
//
#include <stdio.h>
#include <string.h>



int main(int argc, char** argv){

    const char* str = "hello";
    str = "world";
    printf("%s\n", str);

//    const char* str = "hello";

    int a = 1;
    const int* val = &a;

    char b = 'h';
    val = &b;
    printf("%c\n", *val);

    b = 'a';
    printf("%c\n", *val);

    int q=1;
    const int *p;
    p = &q; //на что указывает p можно менять
    *p = 5; //ошибка, число менять уже нельзя
    return 0;
}