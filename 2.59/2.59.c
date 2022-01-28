#include <stdio.h>

// show_bytes implementation from book
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++)
    printf(" %.2x", start[i]);
  printf("\n");
}

int main() {
  // int assuming 32-bit int implementation (thats how it is on my machine)
  int x = 0x89ABCDEF;
  int y = 0x76543210;
  int z;

  z = (x & 0xFF) + (y & ~0xFF);

  /* will show ef 32 54 76 for 0x765432EF on my machine
  (correct because its little endian) */
  show_bytes((byte_pointer)&z, sizeof z);
}