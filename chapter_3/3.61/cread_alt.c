/* compile to assembly code and low optimization level to see conditional move
 * (on clang its -S -O)
 * compare with output of cread.c
 */
long cread_alt(long *xp) {
  long zero = 0;
  return *(xp ? xp : &zero);
}