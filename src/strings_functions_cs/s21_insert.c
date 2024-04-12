#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if ((char *)src == S21_NULL || str == S21_NULL) {
    return S21_NULL;
  }

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  int result_len = src_len + str_len + 1;
  char *result = (char *)malloc(sizeof(char) * result_len);

  if (result != S21_NULL && src_len >= start_index) {
    for (s21_size_t i = 0; i < start_index; i++) {
      result[i] = src[i];
    }

    for (s21_size_t i = 0; i < str_len; i++) {
      result[i + start_index] = str[i];
    }

    for (s21_size_t i = start_index; i < src_len; i++) {
      result[i + str_len] = src[i];
    }

    result[result_len - 1] = '\0';

  } else if (result != S21_NULL) {
    free(result);
    result = S21_NULL;
  }

  return result;
}