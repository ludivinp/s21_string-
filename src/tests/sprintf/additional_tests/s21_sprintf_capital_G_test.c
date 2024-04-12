#include <float.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

#define BIG_DOUBLE 1234567890.098765432

START_TEST(s21_sprintf_g_test_00) {
  const char *format_str = "First = |%G|,\nSecond = |%G|,\nThird = |%G|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_g_test_01) {
  const char *format_str = "First = |%G|\nSecond = |%G|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, 123456.0, 1234567.0);
  const int s21 = s21_sprintf(s21_output, format_str, 123456.0, 1234567.0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_g_test_02) {
  const char *format_str = "First = |%LG|\nSecond = |%LG|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, 123456.0L, 1234567.0L);
  const int s21 = s21_sprintf(s21_output, format_str, 123456.0L, 1234567.0L);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_g_test_03) {
  const char *format_str = "First = |%#G|\nSecond = |%#G|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, 123456.0, 1234567.0);
  const int s21 = s21_sprintf(s21_output, format_str, 123456.0, 1234567.0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_g_test_04) {
  const char *format_str = "First = |%#.0G|\nSecond = |%#.0G|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, 123456.0, 1234567.0);
  const int s21 = s21_sprintf(s21_output, format_str, 123456.0, 1234567.0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_G() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_G");

  tcase_add_test(tcase, s21_sprintf_g_test_00);
  tcase_add_test(tcase, s21_sprintf_g_test_01);
  tcase_add_test(tcase, s21_sprintf_g_test_02);
  tcase_add_test(tcase, s21_sprintf_g_test_03);
  tcase_add_test(tcase, s21_sprintf_g_test_04);

  return tcase;
}