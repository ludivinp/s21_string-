#include "../s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t counter = 0;
  if (str != S21_NULL) {
    while (str[counter] != '\0') {
      counter++;
    }
  }
  return counter;
}
