#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian() {
  int lsb = 0xFF;
  byte_pointer first_byte = (byte_pointer)&lsb;
  if (*first_byte == 0xFF)
    return 1;
  return 0;
}

int main() {
  printf("is little endian: %d", is_little_endian());
  return 0;
}
