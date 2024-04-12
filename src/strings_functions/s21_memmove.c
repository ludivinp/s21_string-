#include "../s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *dest_char = dest;

  while (n) {
    --n;
    dest_char[n] = ((char *)src)[n];
  }

  return dest;
}
