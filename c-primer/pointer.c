// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {   // What is the type of argv? - pointer to a pointer to char?
  int i = 5; // integer value
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i; // pi is the pointer to an integer, specifically i...
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi; // dereference 

  char c[] = "6.172"; // c is a pointer to c[0]?
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc; // value in c[0]
  printf("char d = %c\n", d);  // What does this print? - right.. the first value of c -> 6

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid? because argv is a pointer to a pointer of char

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c;  // What is the type of pcc2? // pcc2 is a constant pointer to a char constant

  // For each of the following, why is the assignment:
  // *pcc = '7';  // invalid? -- because pcc points to a char constant and hence can't be changed
  pcc = *pcp;  // valid? -- here we are not changing the contents of the char, but the where the pointer is pointing to
  pcc = argv[0];  // valid? -- same as above... changing where pcc is pointing to... though these locations are likely invalid... 

  char * const cp = c;  // cp is a const pointer to char
  // For each of the following, why is the assignment:
  // cp = *pcp;  // invalid? -- the location cp is pointing to can't change
  // cp = *argv;  // invalid? -- same.. the location cp is pointing to can't change
  *cp = '!';  // valid? -- we are not changing the location but the value stored in the character

  const char * const cpc = c;  // cpc is a const pointer to char const // this is hehehe
  // For each of the following, why is the assignment:
  // cpc = *pcp;  // invalid? -- nothing can change... can't change where I am pointing to.. .
  // cpc = argv[0];  // invalid? -- same as above?
  // *cpc = '@';  // invalid? -- can't change contents either...

  return 0;
}
