#include "../includes/s21_convertions.h"

s21_size_t str_to_ll(const char *str, long long int *number) {
  s21_size_t return_result = 0;

  const char *temp_str = str;

  *number = 0;
  while (temp_str && *temp_str) {
    if (*temp_str >= '0' && *temp_str <= '9') {
      *number = *number * 10 + (*temp_str - 48);
      ++temp_str;
    } else {
      return_result = temp_str - str;
      temp_str = S21_NULL;
    }
  }

  return return_result;
}
