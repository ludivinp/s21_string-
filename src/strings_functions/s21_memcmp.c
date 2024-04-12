#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  int res = 0;
  for (; n > 0; n--) {
    res = (int)*s1 - (int)*s2;
    if (res != 0) {
      n = 1;
      continue;
    }
    s1++;
    s2++;
  }
  return res;
}