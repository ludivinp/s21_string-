#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *counter = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len = s21_strlen(str) + 1;
    for (s21_size_t i = 0; i < len; i++) {
      if (str[i] == c) {
        counter = (char *)(str + i);
        break;
      }
    }
  }
  return counter;
}