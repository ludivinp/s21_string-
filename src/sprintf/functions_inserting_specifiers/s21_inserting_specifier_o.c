#include "../../includes/s21_convertions.h"
#include "../../includes/s21_sprintf.h"

#define BASE 8

char *s21_inserting_specifier_o(char *str,
                                const s21_specifier_info *specifier_info,
                                unsigned long long int input_data) {
  if (str) {
    if (!(specifier_info->accuracy == 0 && input_data == 0)) {
      determining_length_uint(&input_data, specifier_info->length_flags);

      const int octal_digits =
          s21_count_signed_decimal_digits(input_data, BASE);
      const long long accuracy = specifier_info->accuracy;

      int zeros_padding =
          (accuracy > octal_digits) ? (accuracy - octal_digits) : 0;
      const int str_shift = zeros_padding + octal_digits;

      str += str_shift - 1;

      // Convert to octal. Start from end.
      do {
        *str = '0' + input_data % BASE;
        --str;

        input_data /= BASE;
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