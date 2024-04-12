#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

START_TEST(s21_sprintf_start_symbol_test_00) {
  const char format_str[] =
      "\t First = |%%|,\n\t Second = |%%|,\n\t Third = |%%|\n\t Fourth = "
      "|%%|.\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str);
  const int s21 = s21_sprintf(s21_output, format_str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_start_symbol_test_01) {
  const char format_str[] = "%%";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str);
  const int s21 = s21_sprintf(s21_output, format_str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_start_symbol_test_02) {
  const char format_str[] = "%%%%%%%%%%%%%%%%%%%%";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str);
  const int s21 = s21_sprintf(s21_output, format_str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_start_symbol_test_03) {
  const char format_str[] = "%%";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str);
  const int s21 = s21_sprintf(s21_output, format_str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase* s21_sprintf_start_symbol() {
  TCase* tcase = tcase_create("s21_sprintf_tcase_start_symbol");

  tcase_add_test(tcase, s21_sprintf_start_symbol_test_00);
  tcase_add_test(tcase, s21_sprintf_start_symbol_test_01);
  tcase_add_test(tcase, s21_sprintf_start_symbol_test_02);
  tcase_add_test(tcase, s21_sprintf_start_symbol_test_03);

  return tcase;
}