#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *cur_s = (char *)str;
  char *res = S21_NULL;
  for (; n > 0; n--) {
    if (*cur_s == (char)c) {
      res = cur_s;
      n = 1;
      continue;
    }
    cur_s++;
  }

  return (void *)res;
}
