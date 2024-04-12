#include "../../includes/s21_sprintf.h"

char *s21_inserting_specifier_p(char *str,
                                const s21_specifier_info *specifier_info,
                                uintptr_t input_data) {
  if (str) {
    if (input_data == 0) {
#ifdef __APPLE__
      s21_memcpy(str, "0x0", 3);
      str += 3;
#elif __linux__
      s21_memcpy(str, "(nil)", 5);
      str += 5;
#endif
    } else {
      s21_memcpy(str, "0x", 2);
      str += 2;

      s21_specifier_info new_specifier_info = *specifier_info;
      new_specifier_info.length_flags.l = 2;

      str = s21_inserting_specifier_x(str, &new_specifier_info, input_data);
    }
  }

  return str;
}