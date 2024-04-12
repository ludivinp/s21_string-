#include "../../includes/s21_sprintf.h"

char *s21_inserting_specifier_start_symbol(
    char *str, const s21_specifier_info *specifier_info) {
  if (str && specifier_info) {
    str[0] = START_SPECIFIER_SYMBOL;
    ++str;
  }

  return str;
}