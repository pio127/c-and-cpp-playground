#include <stdio.h>

int main() {
  char character = 'a';
  int number = 5;
  char *charPtr = &character;
  int *intPtr = &number;

  intPtr = (char*)charPtr;
  
  printf("int* to char*\n");
  printf("char pointer: %x \n", *charPtr);
  printf("int pointer: %x \n", *intPtr);

  return 0;
}
