#include <stdio.h>

typedef unsigned float_bits;

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
  unsigned s = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned exp_and_frac = f & 0x7FFFFFFF;

  /* if f is infinity or NaN just return f */
  if (exp == 0xFF) {
    return f;
  }

  /* add this after shifting to round to even */
  int rounding = (frac & 3) == 3;

  /* for normalized nrs just subtracting 1 from the exponent will result in /2
   * when exp is 1 dividing by 2 will result in denormalized number
   * should behave like a shift of exp and frac (similar to reverse of ex2.94)
   */
  if (exp == 0) {
    /* denormalized */
    frac >>= 1;
    frac += rounding;
  } else {
    /* normalized */
    --exp;
    if (exp == 0) {
      /* turned into denormalized number */
      exp_and_frac >>= 1;
      exp_and_frac += rounding;
      exp = exp_and_frac >> 23 & 0xFF;
      frac = exp_and_frac & 0x7FFFFF;
    }
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
    expected.f = expected.f / 2.0;
    actual.u = float_half(i);

    /* fails for NaN numbers as dividing NaN by 2 using my machine's floating
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