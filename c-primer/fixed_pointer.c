#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {   // What is the type of argv? - pointer to array of chars?
  int i = 5; // integer value
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i; // pi is the pointer to an integer, specifically i...
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi; // dereference 

  char c[] = "6.172"; // c is a pointer to c[0]?
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc; // value in c[0]
  printf("char d = %c\n", d);  // What does this print?
}