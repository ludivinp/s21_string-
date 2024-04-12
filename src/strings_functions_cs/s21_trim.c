#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == S21_NULL || trim_chars == S21_NULL) {
    return S21_NULL;
  }

  char *result = S21_NULL;
  if (s21_strlen(src) == 0) {
    result = (char *)malloc(sizeof(char));
    result[0] = '\0';
  } else {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t start = 0;
    s21_size_t end = src_len - 1;

    while (start < src_len && s21_strchr(trim_chars, src[start]) != S21_NULL) {
      start++;
    }

    while (end > start && s21_strchr(trim_chars, src[end]) != S21_NULL) {
      end--;
    }

    s21_size_t trimmed_len = (end >= start) ? (end - start + 1) : 0;

    result = (char *)malloc(sizeof(char) * (trimmed_len + 1));
    if (result != S21_NULL) {
      s21_strncpy(result, src + start, trimmed_len);
      result[trimmed_len] = '\0';
    }
  }

  return result;
}
