#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

START_TEST(s21_sprintf_n_test_00) {
  const char *format_str = "Hello, World!%n\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  int output_count = 69;
  int s21_output_count = 420;

  const int std = sprintf(std_output, format_str, &output_count);
  const int s21 = s21_sprintf(s21_output, format_str, &s21_output_count);

  ck_assert_int_eq(std, s21);

  ck_assert_int_eq(output_count, s21_output_count);

  ck_assert_pstr_eq(std_output, s21_output);
}
END_TEST

START_TEST(s21_sprintf_n_test_01) {
  const char *format_str = "%n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  int output_count = 0;
  int s21_output_count = 0;

  const int std = sprintf(std_output, format_str, &output_count);
  const int s21 = s21_sprintf(s21_output, format_str, &s21_output_count);

  ck_assert_int_eq(std, s21);

  ck_assert_int_eq(output_count, s21_output_count);

  ck_assert_pstr_eq(std_output, s21_output);
}
END_TEST

TCase *s21_sprintf_tcase_n() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_n");

  tcase_add_test(tcase, s21_sprintf_n_test_00);
  tcase_add_test(tcase, s21_sprintf_n_test_01);

  return tcase;
}