#include "../../includes/s21_sprintf.h"

char *s21_inserting_specifier_n(char *str, const char *str_start,
                                int *written) {
  if (str) {
    *written = (int)(str - str_start);
  }

  return str;
}