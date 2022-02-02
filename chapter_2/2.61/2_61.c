#include <stdio.h>

int main() {
  int x = 0xFF;
  /* A */
  printf("any bit of x equals 1: %d\n", x != 0);
  /* B */
  printf("any bit of x equals 0: %d\n", x != ~0);
  /* C */
  printf("any bit in the ls byte equals 1: %d\n", (x & 0xFF) != 0);
  /* D */
  printf("any bit int the ms byte equals 0: %d\n",
         (x >> ((sizeof(int) - 1) << 3) & 0xFF) != 0xFF);
  return 0;
}