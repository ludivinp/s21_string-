#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *adress = S21_NULL;
  int i, j;
  int str1_length = s21_strlen(str1);
  int str2_length = s21_strlen(str2);
  for (i = 0; i < str1_length && adress == S21_NULL; i++) {
    for (j = 0; j < str2_length; j++) {
      if (str1[i] == str2[j]) {
        adress = (char *)str1 + i;
        break;
      }
    }
  }
  return adress;
}