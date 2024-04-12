#include "../../includes/s21_sprintf.h"

char *s21_inserting_specifier_s(char *str,
                                const s21_specifier_info *specifier_info,
                                char *input_data) {
  if (str && input_data && specifier_info) {
    long long int accuracy = specifier_info->accuracy;
    while (*input_data && (accuracy == -1 || accuracy-- > 0)) {
      *str = *input_data;

      ++str;
      ++input_data;
    }
  }

  return str;
}