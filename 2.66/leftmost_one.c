#include <stdio.h>
/*
 * Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 * Your code should contain a total of at most 15 arithmetic, bitwise, and
 * logical operations.
 */
int leftmost_one(unsigned x) {
  /* put x into form [00..0011..11] */
  x |= x >> 1;  /* set (at least) second bit after first 1 to 1 */
  x |= x >> 2;  /* set (at least) third and 4th bit to 1 */
  x |= x >> 4;  /* set (at least) 5th to 8th bit to 1 */
  x |= x >> 8;  /* first 16 bits after first 1 set to 1 */
  x |= x >> 16; /* now all max 32 bits after first 1 set to 1 */

  /* keep only first 1 */
  return (x ^ x >> 1);
}

int main() {
  printf("0x%X\n", leftmost_one(0xFF00));
  printf("0x%X\n", leftmost_one(0x6600));
  printf("0x%X\n", leftmost_one(0));
  return 0;
}