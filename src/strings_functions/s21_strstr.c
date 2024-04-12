#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t length_haystack = s21_strlen(haystack);
  s21_size_t length_needle = s21_strlen(needle);
  char *address = S21_NULL;
  if (haystack != S21_NULL && needle != S21_NULL &&
      length_needle <= length_haystack) {
    if (length_needle != 0) {
      for (int i = 0; i <= (int)length_haystack - (int)length_needle; i++) {
        if (s21_strncmp(haystack + i, needle, length_needle) == 0) {
          address = (char *)(haystack + i);
          break;
        }
      }
    } else {
      address = (char *)(haystack);
    }
  }
  return address;
}