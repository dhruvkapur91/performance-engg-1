#include "./matrix_multiply.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "./tbassert.h"

// Allocates a row-by-cols matrix and returns it
matrix* make_matrix(int rows, int cols) {
  matrix* new_matrix = malloc(sizeof(matrix));

  // Set the number of rows and columns
  new_matrix->rows = rows;
  new_matrix->cols = cols;

  // Allocate a buffer big enough to hold the matrix.
  new_matrix->values = (int**)malloc(sizeof(int*) * rows);
  for (int i = 0; i < rows; i++) {
    new_matrix->values[i] = (int*)malloc(sizeof(int) * cols);
  }

  return new_matrix;
}

// Frees an allocated matrix
void free_matrix(matrix* m) {
  for (int i = 0; i < m->rows; i++) {
    free(m->values[i]);
  }
  free(m->values);
  free(m);
}

// Print matrix
void print_matrix(const matrix* m) {
  printf("------------\n");
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      printf("  %3d  ", m->values[i][j]);
    }
    printf("\n");
  }
  printf("------------\n");
}


// Multiply matrix A*B, store result in C.
int matrix_multiply_run(const matrix* A, const matrix* B, matrix* C) {
  tbassert(A->cols == B->rows,
           "A->cols = %d, B->rows = %d\n", A->cols, B->rows);
  tbassert(A->rows == C->rows,
           "A->rows = %d, C->rows = %d\n", A->rows, C->rows);
  tbassert(B->cols == C->cols,
           "B->cols = %d, C->cols = %d\n", B->cols, C->cols);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->cols; j++) {
      for (int k = 0; k < A->cols; k++) {
        C->values[i][j] += A->values[i][k] * B->values[k][j];
      }
    }
  }

  return 0;
}
