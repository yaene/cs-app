#include <stdio.h>
#define BUF_SIZE 5u

int get_line(unsigned buf_size, char *buf) {
  char c;
  unsigned read = 0;
  while (read < buf_size && (c = getchar()) != '\n' && c != EOF) {
    buf[read++] = c;
  }
  if (c == EOF)
    return EOF;
  else
    return read;
}

void good_echo() {
  char buf[BUF_SIZE + 1];
  int read = get_line(BUF_SIZE, buf);
  while (read != EOF) {
    while (read == BUF_SIZE) {
      buf[BUF_SIZE] = '\0';
      printf("%s", buf);
      read = get_line(BUF_SIZE, buf);
    }
    if (read != EOF) {
      buf[read] = '\0';
      printf("%s\n", buf);
      read = get_line(BUF_SIZE, buf);
    }
  }
}

int main() {
  good_echo();
  return 0;
}