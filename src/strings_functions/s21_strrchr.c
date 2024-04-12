#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *counter = S21_NULL;
  if (str != S21_NULL) {
    for (int i = (int)s21_strlen(str); i >= 0; i--) {
      if (str[i] == c) {
        counter = (char *)str + i;
        break;
      }
    }
  }
  return counter;
}
