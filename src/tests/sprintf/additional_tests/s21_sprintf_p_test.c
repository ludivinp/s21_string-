#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

START_TEST(s21_sprintf_p_test_00) {
  int x = 512;
  int *y = malloc(sizeof(y));

  const char *format_str = "== &x: |%p|, &y: |%p| ==\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, &x, y);
  const int s21 = s21_sprintf(s21_output, format_str, &x, y);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);

  if (y) {
    free(y);
  }
}
END_TEST

START_TEST(s21_sprintf_p_test_01) {
  const char *format_str = "== &x: |%p|, &y: |%p| ==\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  int x = 512;
  int *y = NULL;

  const int std = sprintf(std_output, format_str, &x, y);
  const int s21 = s21_sprintf(s21_output, format_str, &x, y);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_p() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_p");

  tcase_add_test(tcase, s21_sprintf_p_test_00);
  tcase_add_test(tcase, s21_sprintf_p_test_01);

  return tcase;
}