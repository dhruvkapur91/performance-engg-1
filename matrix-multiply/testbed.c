/**
 * testbed.c:
 *
 * This file runs your code, timing its execution and printing out the result.
 **/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./fasttime.h"
#include "./matrix_multiply.h"


int main(int argc, char** argv) {
  int optchar = 0;
  int show_usec = 0;
  int should_print = 0;
  int use_zero_matrix = 0;

  // Always use the same seed, so that our tests are repeatable.
  unsigned int randomSeed = 1;

  matrix* A;
  matrix* B;
  matrix* C;

  const int kMatrixSize = 4;


  // Parse command line arguments
  while ((optchar = getopt(argc, argv, "upz")) != -1) {
    switch (optchar) {
      case 'u':
        show_usec = 1;
        break;
      case 'p':
        should_print = 1;
        break;
      case 'z':
        use_zero_matrix = 1;
        break;
      default:
        printf("Ignoring unrecognized option: %c\n", optchar);
        continue;
    }
  }

  // This is a trick to make the memory bug leads to a wrong output.
  int size = sizeof(int) * 4;
  int* temp[20];

  for (int i = 0; i < 20; i++) {
    temp[i] = (int*)malloc(size);
    memset(temp[i], 1, size);
  }
  int total = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 4; j++) {
      total += temp[i][j];
    }
  }
  if (!total) printf("Trick to stop mallocs from being optimized out.");
  for (int i = 0; i < 20; i++) {
    free(temp[i]);
  }

  fprintf(stderr, "Setup\n");

  A = make_matrix(kMatrixSize, kMatrixSize);
  B = make_matrix(kMatrixSize, kMatrixSize);
  C = make_matrix(kMatrixSize, kMatrixSize);

  if (use_zero_matrix) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->cols; j++) {
        A->values[i][j] = 0;
      }
    }
    for (int i = 0; i < B->rows; i++) {
      for (int j = 0; j < B->cols; j++) {
        B->values[i][j] = 0;
      }
    }
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->cols; j++) {
        A->values[i][j] = rand_r(&randomSeed) % 10;
      }
    }
    for (int i = 0; i < B->rows; i++) {
      for (int j = 0; j < B->cols; j++) {
        B->values[i][j] = rand_r(&randomSeed) % 10;
      }
    }
  }

  if (should_print) {
    printf("Matrix A: \n");
    print_matrix(A);

    printf("Matrix B: \n");
    print_matrix(B);
  }

  fprintf(stderr, "Running matrix_multiply_run()...\n");

  fasttime_t time1 = gettime();
  matrix_multiply_run(A, B, C);
  fasttime_t time2 = gettime();

  if (should_print) {
    printf("---- RESULTS ----\n");
    printf("Result: \n");
    print_matrix(C);
    printf("---- END RESULTS ----\n");
  }

  if (show_usec) {
    double elapsed = tdiff(time1, time2);
    printf("Elapsed execution time: %f usec\n",
           elapsed * (1000.0 * 1000.0));
  } else {
    double elapsed = tdiff(time1, time2);
    printf("Elapsed execution time: %f sec\n", elapsed);
  }

  return 0;
}
