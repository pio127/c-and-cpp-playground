#include <stdio.h>
#include <stdlib.h>

void print_2d_matrix(void** matrix, unsigned short rows, unsigned short columns) {
    int **matrix_pointer = (int**)matrix;
    for (int x=0; x<rows; ++x) {
        for (int y=0; y<columns; ++y) {
            printf("%i ", matrix_pointer[x][y]);
        }
        printf("\n");
    }
}
int main() {
    int matrix_cols=4;
    int matrix_rows=3;

    int matrix_size_from_values[matrix_rows][matrix_cols];

    int matrix[3][4] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    int **matrix_heap = malloc(sizeof(int)*matrix_rows);
    matrix_heap[0] = malloc(sizeof(int)*matrix_cols);
    matrix_heap[1] = malloc(sizeof(int)*matrix_cols);
    matrix_heap[2] = malloc(sizeof(int)*matrix_cols);


    print_2d_matrix(matrix_heap, 3, 4);
}
