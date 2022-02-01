#include <stdio.h>

typedef unsigned float_bits;

/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f) {
  if ((f >> 23 & 0xFF) == 0xFF && (f << 9)) {
    /* NaN */
    return f;
  }
  return f ^ 1 << 31;
}

int main() {
  printf("%X\n", float_negate(0));
  printf("%X\n", float_negate(0x7FFF << 16));
}