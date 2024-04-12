#include <limits.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

START_TEST(s21_sprintf_x_test_00) {
  const char *format_str =
      "\t First = |%x|,\n\t Second = |%x|,\n\t Third = |%x|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_01) {
  const char *format_str =
      "\t First = |%+x|,\n\t Second = |%+x|,\n\t Third = |%+x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_02) {
  const char *format_str =
      "\t First = |%#x|,\n\t Second = |%#x|,\n\t Third = |%#x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_03) {
  const char *format_str =
      "\t First = |% x|,\n\t Second = |% x|,\n\t Third = |% x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_04) {
  const char *format_str =
      "\t First = |%1x|,\n\t Second = |%2x|,\n\t Third = |%5x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_05) {
  const char *format_str =
      "\t First = |%-1x|,\n\t Second = |%-2x|,\n\t Third = |%-5x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_06) {
  const char *format_str =
      "\t First = |%01x|,\n\t Second = |%02x|,\n\t Third = |%05x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_07) {
  const char *format_str =
      "\t First = |%.0x|,\n\t Second = |%.10x|,\n\t Third = |%.50x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_08) {
  const char *format_str =
      "\t First = |%20.0x|,\n\t Second = |%10.1x|,\n\t Third = |%5.5x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_09) {
  const char *format_str =
      "\t First = |%-20.0x|,\n\t Second = |%-10.1x|,\n\t Third = "
      "|%-5.5x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_10) {
  const char *format_str =
      "\t First = |%+-20.0x|,\n\t Second = |%+-10.1x|,\n\t Third = "
      "|%+-5.5x|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_11) {
  const char *format_str =
      "\t First = |%lx|,\n\t Second = |%lx|,\n\t Third = "
      "|%lx|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_12) {
  const char *format_str =
      "\t First = |%hx|,\n\t Second = |%hx|,\n\t Third = "
      "|%hx|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_13) {
  const char *format_str =
      "\t First = |%hhx|,\n\t Second = |%hhx|,\n\t Third = "
      "|%hhx|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_x() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_x");

  tcase_add_test(tcase, s21_sprintf_x_test_00);
  tcase_add_test(tcase, s21_sprintf_x_test_01);
  tcase_add_test(tcase, s21_sprintf_x_test_02);
  tcase_add_test(tcase, s21_sprintf_x_test_03);
  tcase_add_test(tcase, s21_sprintf_x_test_04);
  tcase_add_test(tcase, s21_sprintf_x_test_05);
  tcase_add_test(tcase, s21_sprintf_x_test_06);
  tcase_add_test(tcase, s21_sprintf_x_test_07);
  tcase_add_test(tcase, s21_sprintf_x_test_08);
  tcase_add_test(tcase, s21_sprintf_x_test_09);
  tcase_add_test(tcase, s21_sprintf_x_test_10);

  tcase_add_test(tcase, s21_sprintf_x_test_11);
  tcase_add_test(tcase, s21_sprintf_x_test_12);
  tcase_add_test(tcase, s21_sprintf_x_test_13);

  return tcase;
}