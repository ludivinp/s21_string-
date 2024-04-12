#include "../includes/s21_convertions.h"

int s21_is_eq_ch(char ch, const char *str2) {
  int ret = 0;
  for (s21_size_t i = 0; i < (s21_size_t)s21_strlen(str2); ++i) {
    if (ch == str2[i]) {
      ret = 1;
      break;
    }
  }
  return ret;
}