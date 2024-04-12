#include "../../includes/s21_convertions.h"
#include "../../includes/s21_sprintf.h"

// 1e+00
#define MIN_STRING_LENGTH 5

char *s21_inserting_specifier_e(char *str,
                                const s21_specifier_info *specifier_info,
                                long double input_data) {
  if (str) {
    int offset = 0;
    const int capital_letters =
        (specifier_info->specifier_symbol == 'E') ? true : false;

    if ((offset = s21_is_nan_or_inf(input_data, str, capital_letters)) == 0) {
      const int sign = (input_data < 0) ? -1 : 1;
      const long long accuracy =
          specifier_info->accuracy == -1 ? 6 : specifier_info->accuracy;
      const unsigned long long number_string_length =
          accuracy + (sign == 1 ? MIN_STRING_LENGTH : MIN_STRING_LENGTH + 1);

      int exp = 0;
      if (input_data != 0) {
        input_data = sign == -1 ? input_data * -1 : input_data;

        while (input_data < 1) {
          input_data *= 10;
          --exp;
        }

        while (input_data >= 10) {
          input_data /= 10;
          ++exp;
        }
        input_data *= sign;
      }

      offset = s21_ld_to_str(input_data, str, number_string_length, accuracy);
      str += offset;

      offset =
          s21_sprintf(str, "%c%+03d", specifier_info->specifier_symbol, exp);
      str += offset;
    } else {
      str += offset;
    }
  }

  return str;
}