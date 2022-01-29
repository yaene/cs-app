#include <stdio.h>

int int_shifts_are_arithmetic() {
  int num = -1; /* all bit 1s in twos complement */
  return num >> 1 ==
         num; /* logic shift gives 0111.. while arithmetic keeps all 1 */
}

int main() {
  printf("int shifts are arithmetic: %d", int_shifts_are_arithmetic());
  return 0;
}