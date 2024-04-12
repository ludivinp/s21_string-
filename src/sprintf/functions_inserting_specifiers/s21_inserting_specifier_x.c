#include "../../includes/s21_convertions.h"
#include "../../includes/s21_sprintf.h"

#define BASE 16

char *s21_inserting_specifier_x(char *str,
                                const s21_specifier_info *specifier_info,
                                unsigned long long int input_data) {
  if (str) {
    if (!(specifier_info->accuracy == 0 && input_data == 0)) {
      determining_length_uint(&input_data, specifier_info->length_flags);

      const unsigned long int hex_digits =
          s21_count_signed_decimal_digits(input_data, BASE);
      const long long accuracy = specifier_info->accuracy;

      int zeros_padding = 0;
      if (accuracy != -1 && (unsigned long int)accuracy > hex_digits) {
        zeros_padding = accuracy - hex_digits;
      }

      int str_shift = zeros_padding + hex_digits;

      str += str_shift - 1;

      // Convert to hexadecimal. Start from end.
      do {
        int remainder = input_data % BASE;

        if (remainder < 10) {
          *str = '0' + remainder;
        } else if (specifier_info->specifier_symbol == 'X') {
          *str = 'A' + (remainder - 10);
        } else {
          *str = 'a' + (remainder - 10);
        }
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