#include <stdio.h>
#define LONG_BITS (sizeof(long) << 3)
/* decode2: 2
 subq %rdx, %rsi
 imulq %rsi, %rdi
 movq %rsi, %rax
 salq $63, %rax
 sarq $63, %rax
 xorq %rdi, %rax
 ret
 */
long decode2(long x, long y, long z) {
  long val = y - z;
  long res = (val << (LONG_BITS - 1)) >> (LONG_BITS - 1);
  return res ^ x * val;
}

int main() {
  printf("decode2(1, 2, 3) = %ld\n", decode2(1, 2, 3));
  printf("decode2(1, 3, 2) = %ld\n", decode2(1, 3, 2));
  printf("decode2(-1, 3, 2) = %ld\n", decode2(-1, 3, 2));
  return 0;
}