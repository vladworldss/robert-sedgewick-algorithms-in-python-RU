//
// Created by vladworldss on 24.07.18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 1024
#define MAX_STR_NUM 10

int main(int argc, char** argv){

    char** a = calloc(MAX_STR_NUM, sizeof(char*));
    char* s = calloc(MAX_STR_SIZE, sizeof(char));


    unsigned N = 0;
    while(scanf("%s", s)  && strcmp(s, "--Q") && N < MAX_STR_NUM){

        a[N] = calloc(strlen(s), sizeof(char));
        strcpy(a[N], s);
        N++;
    }


    printf("free memory...\n");
    free(s);
    for (int i =0; i < N; i++){
        printf("%s\n", a[i]);
        free(a[i]);
    }
    free(a);
    return 0;
}