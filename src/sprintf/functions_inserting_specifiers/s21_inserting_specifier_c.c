#include "../../includes/s21_sprintf.h"

char *s21_inserting_specifier_c(char *str,
                                const s21_specifier_info *specifier_info,
                                char input_data) {
  if (str && specifier_info) {
    str[0] = input_data;
    ++str;
  }

  return str;
}