#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  char *s = (char *)src;
  for (; n > 0; --n) {
    *d = *s;
    d++;
    s++;
  }
  return dest;
}