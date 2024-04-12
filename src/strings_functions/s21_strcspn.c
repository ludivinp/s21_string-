#include "../includes/s21_convertions.h"
#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  if (str1 == S21_NULL || str2 == S21_NULL) {
    return 0;
  }
  s21_size_t res = 0;

  for (s21_size_t i = 0; i < (s21_size_t)s21_strlen(str1); ++i) {
    if (!s21_is_eq_ch(str1[i], str2)) {
      res++;
    } else {
      break;
    }
  }
  return res;
}