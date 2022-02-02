#include <stdio.h>
/*
* Do rotating left shift. Assume 0 <= n < w
* Examples when x = 0x12345678 and w = 32:
*
 n=4 -> 0x23456781, n=20 -> 0x67812345
*/
unsigned rotate_left(unsigned x, int n) {
  int w = sizeof(int) << 3;

  unsigned left_shifted = x << n;

  /* move n-w bits shifted off the left to the right */
  unsigned rotated = x >> (w - n);

  /* combine left shifted w-n bits and right shifted n bits */
  return rotated | left_shifted;
}

int main() {
  printf("rotate left 0x12345678 n=4: 0x%X\n", rotate_left(0x12345678, 4));
  printf("rotate left 0x12345678 n=20: 0x%X\n", rotate_left(0x12345678, 20));
  printf("rotate left 0x12345678 n=0: 0x%X\n", rotate_left(0x12345678, 0));
  return 0;
}