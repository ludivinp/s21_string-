#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *s = (char *)str;

  for (; n > 0; n--) {
    *s = (char)c;
    s++;
  }

  return str;
}