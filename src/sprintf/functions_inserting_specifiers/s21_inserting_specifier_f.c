#include <float.h>

#include "../../includes/s21_convertions.h"
#include "../../includes/s21_sprintf.h"

// See https://stackoverflow.com/a/1701272/17386531
#define INITIAL_BUFFER_SIZE (3 + LDBL_MANT_DIG - LDBL_MIN_EXP)

char *s21_inserting_specifier_f(char *str,
                                const s21_specifier_info *specifier_info,
                                long double input_data) {
  if (str) {
    const long long int accuracy =
        (specifier_info->accuracy == -1) ? 6 : specifier_info->accuracy;

    const int final_string_length = s21_ld_to_str(
        input_data, str,
        (accuracy > INITIAL_BUFFER_SIZE) ? accuracy : INITIAL_BUFFER_SIZE,
        accuracy);

    str += final_string_length;
  }

  return str;
}