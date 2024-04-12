#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *buffer_last;
  char *ptr;
  int working_flag = 1;
  if ((ptr = str) == S21_NULL && (ptr = buffer_last) == S21_NULL) {
    str = S21_NULL;
    working_flag = 0;
  }
  for (int i = 0; working_flag && *ptr && delim[i]; i++) {
    if (*ptr == delim[i]) {
      ptr++;
      i = -1;
    }
  }
  if (working_flag != 1 || *ptr != '\0') {
    str = ptr;
    while (working_flag && *ptr) {
      for (s21_size_t i = 0; delim[i]; i++) {
        if (*ptr == delim[i]) {
          working_flag = 0;
          *ptr = '\0';
          ptr++;
          if (*ptr == '\0') ptr = S21_NULL;
          buffer_last = ptr;
          break;
        }
      }
      if (working_flag) {
        ptr++;
        if (*ptr == '\0') {
          buffer_last = S21_NULL;
        }
      }
    }
  } else {
    ptr = S21_NULL;
    buffer_last = S21_NULL;
    str = S21_NULL;
  }
  return str;
}
