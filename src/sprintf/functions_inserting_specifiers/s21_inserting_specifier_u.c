#include "../../includes/s21_convertions.h"
#include "../../includes/s21_sprintf.h"

char *s21_inserting_specifier_u(char *str,
                                const s21_specifier_info *specifier_info,
                                unsigned long long int input_data) {
  if (str) {
    if (!(specifier_info->accuracy == 0 && input_data == 0)) {
      determining_length_uint(&input_data, specifier_info->length_flags);

      const int decimal_digits =
          s21_count_signed_decimal_digits(input_data, 10);
      const long long accuracy = specifier_info->accuracy;

      int zeros_padding =
          (accuracy > decimal_digits) ? (accuracy - decimal_digits) : 0;
      int str_shift = zeros_padding + decimal_digits;

      str += str_shift - 1;

      // Convert to decimal. Start from end.
      do {
        *str = '0' + input_data % 10;
        --str;
        input_data /= 10;
      } while (input_data);

      while (zeros_padding) {
        *str = '0';
        --str;
        --zeros_padding;
      }

      str += str_shift + 1;
    }
  }

  return str;
}