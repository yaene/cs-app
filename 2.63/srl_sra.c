#include <stdio.h>

unsigned srl(unsigned x, int k) {
  /* perform shift arithmetically */
  unsigned xsra = (int)x >> k;

  /* arithmetic shift introduces k 1's for negative numbers
  these need to be replaced by 0 */

  int word_size = sizeof(int) << 3;
  /* bit mask with k 0s followed by 1s as big as word size */
  int bit_mask = ~(-1 << (word_size - k));

  return xsra & bit_mask;
}

int sra(int x, int k) {
  /* perform shift logically */
  int xsrl = (unsigned)x >> k;

  /* logical shift adds 0s in first k bits for negative numbers
   * these need to be replaced by 1 */

  int word_size = sizeof(int) << 3;

  /* bit mask with k 1s and word_size -k 0s */
  int bit_mask = -1 << (word_size - k);
  /* set bit mask to 0 if first bit is 1 (x is positive), as logical shift is
   * correct for positive numbers */
  /* subtracting 1 from bool value (0 or 1) makes 0 to -1 (all 1s in binary) and
   * 1 to 0 (all 0s in binary) */
  bit_mask &= !(((x >> (word_size - 1)) & 1) == 1) - 1;

  return xsrl | bit_mask;
}

int main() {
  printf("-1 right shift arithmetic: %d\n", sra(-1, 31)); /* still -1 */
  printf("-1 right shift logic: %d\n", srl(-1, 31));      /* turns into 1 */
  printf("0xFF arithmetic right shift by 7: %d\n",
         sra(0xFF, 7)); /* turns into 1 */
  return 0;
}