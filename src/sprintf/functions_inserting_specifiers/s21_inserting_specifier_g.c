#include "../../includes/s21_sprintf.h"

char *s21_inserting_specifier_g(char *str,
                                const s21_specifier_info *specifier_info,
                                long double input_data) {
  long long accuracy = specifier_info->accuracy;
  if (accuracy == -1) {
    accuracy = 6;
  } else if (accuracy == 0) {
    accuracy = 1;
  }

  int exp = 0;
  long double input_data_copy = (input_data < 0) ? input_data * -1 : input_data;
  if (input_data_copy != 0) {
    while (input_data_copy < 1) {
      input_data_copy *= 10;
      --exp;
    }
    while (input_data_copy >= 10) {
      input_data_copy /= 10;
      ++exp;
    }
  }

  s21_specifier_info temp_specifier_info = *specifier_info;
  if (exp < accuracy && exp >= -4) {
    temp_specifier_info.accuracy = accuracy - exp - 1;

    str = s21_inserting_specifier_f(str, &temp_specifier_info, input_data);
  } else {
    temp_specifier_info.accuracy = accuracy - 1;
    temp_specifier_info.specifier_symbol =
        (temp_specifier_info.specifier_symbol == 'G') ? 'E' : 'e';

    str = s21_inserting_specifier_e(str, &temp_specifier_info, input_data);
  }

  do {
    --str;
  } while (*str == '0');
  if (*str != '.') {
    ++str;
  }

  return str;
}