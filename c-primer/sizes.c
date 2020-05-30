// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINT_SIZE(type) printf("size of " #type ": %zu bytes \n", sizeof(type));

int main() {
  PRINT_SIZE(int)
  PRINT_SIZE(int *)
  PRINT_SIZE(int * *)
  PRINT_SIZE(short)
  PRINT_SIZE(short *)
  PRINT_SIZE(long)
  PRINT_SIZE(long *)
  PRINT_SIZE(unsigned int)
  PRINT_SIZE(unsigned int *)
  PRINT_SIZE(long long)
  PRINT_SIZE(long long *)
  PRINT_SIZE(char)
  PRINT_SIZE(char *)
  PRINT_SIZE(float)
  PRINT_SIZE(float *)
  PRINT_SIZE(double)
  PRINT_SIZE(double *)
  PRINT_SIZE(uint8_t)
  PRINT_SIZE(uint8_t *) // unsigned char = 8 bits
  PRINT_SIZE(uint16_t) // unsigned short
  PRINT_SIZE(uint16_t *) // unsigned short = 16 bits
  PRINT_SIZE(uint32_t)
  PRINT_SIZE(uint32_t *) // unsigned int = 32 bits
  PRINT_SIZE(uint64_t) // unsigned long long
  PRINT_SIZE(uint64_t *) // unsigned long long
  PRINT_SIZE(uint_fast8_t)
  PRINT_SIZE(uint_fast8_t *) // probably same as uint8_t
  PRINT_SIZE(uint_fast16_t)
  PRINT_SIZE(uint_fast16_t *) // probably same as unit16_t
  PRINT_SIZE(uintmax_t)
  PRINT_SIZE(uintmax_t *) // unsigned long
  PRINT_SIZE(intmax_t)
  PRINT_SIZE(intmax_t *) // simply a long?
  PRINT_SIZE(__int128)
  PRINT_SIZE(__int128 *) // A 16 byte long integer!
  PRINT_SIZE(int[2])
  // PRINT_SIZE(* int[2]) // Can query array directly
  
  typedef struct {
    int id;
    int year;
  } student;

  PRINT_SIZE(student)
  PRINT_SIZE(student *)
  PRINT_SIZE(student[100])

  int x[5];
  PRINT_SIZE(x)
  PRINT_SIZE(&x)

  return 0;
}
