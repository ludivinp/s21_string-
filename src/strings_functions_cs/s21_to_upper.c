#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));

  if (result) {
    s21_memcpy(result, str, s21_strlen(str) + 1);

    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (result[i] >= 'a' && result[i] <= 'z') result[i] -= ('a' - 'A');
    }
  }

  return (void *)result;
}