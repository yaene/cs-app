#include <stdio.h>

typedef unsigned float_bits;

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_twice(float_bits f) {
  unsigned s = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  /* if f is infinity or NaN just return f */
  if (exp == 0xFF) {
    return f;
  }

  /* for normalized nrs just adding 1 to the exponent will result in x2
   * overflow to infinity can happen -> need to make sure frac = 0 so it does
   * not turn into NaN */
  if (exp == 0)
    /* denormalized */
    /* shift also works when leading bit of frac is 1 since it effectively adds
     * one to the exponent but keeps value of frac the same (shift is offset by
     * switch from de- to normalized considering frac with an implied 1) */
    frac <<= 1;
  else {
    /* normalized */
    ++exp;
  }

  /*handle overflow */
  if (exp == 0xFF) {
    frac = 0;
  }

  return s << 31 | exp << 23 | frac;
}

/* union only for test program */
union float_data {
  float_bits u;
  float f;
} expected, actual;

int main() {
  for (float_bits i = 0; i < ~0; ++i) {
    expected.u = i;
    expected.f = expected.f * 2.0;
    actual.u = float_twice(i);

    /* fails for NaN numbers as multiplying NaN by 2 using my machine's floating
     * point operations still changes the underlying bits */
    if (actual.u != expected.u) {
      printf("%u\n", i);
      printf("expected=%f, actual=%f\n", expected.f, actual.f);
      printf("expected=%u, actual=%u\n", expected.u, actual.u);
      break;
    }
  }
  return 0;
}