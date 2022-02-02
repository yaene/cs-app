#include <stdio.h>

int threefourths(int x) {
  int big_part = x & ~0x3;
  int small_part = x & 0x3;

  /* one half + one fourth = threefourths
   * big_part division first to avoid overflow
   * since last 2 bits are handled separately shifts dont lead to loss of
   * precision */
  big_part = (big_part >> 2) + (big_part >> 1);

  /* small_part multiply by 3 first then divide by 4 to minimize loss of
   * precision */
  int three_fourths_small_part = ((small_part << 2) - small_part) >> 2;

  /* big_part doesnt lose any precision so only small part needs rounding */
  /* add one to negative number when small part != 0 */
  int is_neg = (unsigned)x >> ((sizeof(int) << 3) - 1);
  three_fourths_small_part += is_neg & (small_part != 0);

  return big_part + three_fourths_small_part;
}

int main() {
  printf("threefourths(8)=%d\n", threefourths(8));
  printf("threefourths(9)=%d\n", threefourths(9));
  printf("threefourths(10)=%d\n", threefourths(10));
  printf("threefourths(11)=%d\n", threefourths(11));
  printf("threefourths(12)=%d\n", threefourths(12));

  printf("threefourths(-8)=%d\n", threefourths(-8));
  printf("threefourths(-9)=%d\n", threefourths(-9));
  printf("threefourths(-10)=%d\n", threefourths(-10));
  printf("threefourths(-11)=%d\n", threefourths(-11));
  printf("threefourths(-12)=%d\n", threefourths(-12));

  return 0;
}