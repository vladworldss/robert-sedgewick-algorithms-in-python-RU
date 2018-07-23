/* Программа 3.18
 * Представление графа в виде матрицы смежности
 *
 * Программа выполняет чтение набора ребер, описывающих неориентированный
 * граф, и создает для него представление в виде матрицы смежности.
 * При этом элементам a[i][j] и a[j][i] присваивается значение 1,
 * если существует ребро от i до j либо от j до i.
 * В противном случае элементам присваивается значение 0.
 *
 * Динамическое создание матриц.
 * */

#include <stdio.h>
#include <stdlib.h>


int** init_matrix(unsigned rows, unsigned cols){
    if ((rows < 2) || (cols < 2)){
        perror("Bad matrix size");
        exit(1);
    }
    int** adj = calloc(rows, sizeof(*adj));
    for (int i = 0; i < rows; i++)
        adj[i] = calloc(cols, sizeof(int));

    return adj;
}


void print_matrix(int** m, unsigned size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}

int main(int argc, char** argv){
    int i, j;
    unsigned N = atoi(argv[1]);

    int** adj = init_matrix(N, N);

    for (i=0; j < N; i++){
        adj[i][i] = 1;
    }

    while(scanf("%d %d", &i, &j) == 2){
        adj[i][j] = 1;
        adj[j][i] = 1;
    }

    print_matrix(adj, N);
    return 0;
}