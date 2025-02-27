#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 256

START_TEST(s21_sprintf_d_test_00) {
  const char *format_str = "\t First = |%d|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_01) {
  const char *format_str = "\t First = |%d|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, 0);
  const int s21 = s21_sprintf(s21_output, format_str, 0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_02) {
  const char *format_str = "\t First = |%d|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_03) {
  const char *format_str =
      "\t First = |%+d|,\n\t Second = |%+d|,\n\t Third = |%+d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_04) {
  const char *format_str =
      "\t First = |% d|,\n\t Second = |% d|,\n\t Third = |% d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_05) {
  const char *format_str =
      "\t First = |%1d|,\n\t Second = |%10d|,\n\t Third = |%100d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_06) {
  const char *format_str =
      "\t First = |%-1d|,\n\t Second = |%-2d|,\n\t Third = |%-5d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_07) {
  const char *format_str =
      "\t First = |%01d|,\n\t Second = |%010d|,\n\t Third = |%020d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_08) {
  const char *format_str =
      "\t First = |%.0d|,\n\t Second = |%.1d|,\n\t Third = |%.10d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_09) {
  const char *format_str =
      "\t First = |%20.0d|,\n\t Second = |%10.1d|,\n\t Third = |%20.20d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_10) {
  const char *format_str =
      "\t First = |%-20.0d|,\n\t Second = |%-10.1d|,\n\t Third = |%-5.5d|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_11) {
  const char *format_str =
      "\t First = |%+-20.0d|,\n\t Second = |%+-10.1d|,\n\t Third = |%+-5.5d|";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_12) {
  const char *format_str =
      "\t First = |%ld|,\n\t Second = |%ld|,\n\t Third = |%ld|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_13) {
  const char *format_str =
      "\t First = |%lld|,\n\t Second = |%lld|,\n\t Third = |%lld|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_14) {
  const char *format_str =
      "\t First = |%hd|,\n\t Second = |%hd|,\n\t Third = |%hd|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_d_test_15) {
  const char *format_str =
      "\t First = |%hhd|,\n\t Second = |%hhd|,\n\t Third = |%hhd|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_d() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_d");

  tcase_add_test(tcase, s21_sprintf_d_test_00);
  tcase_add_test(tcase, s21_sprintf_d_test_01);
  tcase_add_test(tcase, s21_sprintf_d_test_02);
  tcase_add_test(tcase, s21_sprintf_d_test_03);
  tcase_add_test(tcase, s21_sprintf_d_test_04);
  tcase_add_test(tcase, s21_sprintf_d_test_05);
  tcase_add_test(tcase, s21_sprintf_d_test_06);
  tcase_add_test(tcase, s21_sprintf_d_test_07);
  tcase_add_test(tcase, s21_sprintf_d_test_08);
  tcase_add_test(tcase, s21_sprintf_d_test_09);
  tcase_add_test(tcase, s21_sprintf_d_test_10);
  tcase_add_test(tcase, s21_sprintf_d_test_11);
  tcase_add_test(tcase, s21_sprintf_d_test_12);
  tcase_add_test(tcase, s21_sprintf_d_test_13);
  tcase_add_test(tcase, s21_sprintf_d_test_14);
  tcase_add_test(tcase, s21_sprintf_d_test_15);

  return tcase;
}