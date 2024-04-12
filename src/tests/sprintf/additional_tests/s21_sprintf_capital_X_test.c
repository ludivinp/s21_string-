#include <limits.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

START_TEST(s21_sprintf_x_test_00) {
  const char *format_str =
      "\t First = |%X|,\n\t Second = |%X|,\n\t Third = |%X|\n";

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
      "\t First = |%+X|,\n\t Second = |%+X|,\n\t Third = |%+X|\n";

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
      "\t First = |% X|,\n\t Second = |% X|,\n\t Third = |% X|\n";

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
      "\t First = |%1X|,\n\t Second = |%2X|,\n\t Third = |%5X|\n";

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
      "\t First = |%-1X|,\n\t Second = |%-2X|,\n\t Third = |%-5X|\n";

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
      "\t First = |%01X|,\n\t Second = |%02X|,\n\t Third = |%05X|\n";

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
      "\t First = |%.0X|,\n\t Second = |%.1X|,\n\t Third = |%.5X|\n";

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
      "\t First = |%20.0X|,\n\t Second = |%10.1X|,\n\t Third = |%5.5X|\n";

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
      "\t First = |%-20.0X|,\n\t Second = |%-10.1X|,\n\t Third = "
      "|%-5.5X|\n";

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
      "\t First = |%+-20.0X|,\n\t Second = |%+-10.1X|,\n\t Third = "
      "|%+-5.5X|\n";

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
      "\t First = |%lX|,\n\t Second = |%lX|,\n\t Third = "
      "|%lX|\n";

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
      "\t First = |%llX|,\n\t Second = |%llX|,\n\t Third = "
      "|%llX|\n";

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
      "\t First = |%hX|,\n\t Second = |%hX|,\n\t Third = "
      "|%hX|\n";

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
      "\t First = |%hhX|,\n\t Second = |%hhX|,\n\t Third = "
      "|%hhX|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_x_test_14) {
  const char *format_str =
      "\t First = |%#X|,\n\t Second = |%#X|,\n\t Third = |%#X|\n";

  char output_str[MAX_STR_LEN] = {};
  char s21_output_str[MAX_STR_LEN] = {};

  int std = sprintf(output_str, format_str, INT_MIN, 0, INT_MAX);
  int s21 = s21_sprintf(s21_output_str, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(output_str, s21_output_str);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_X() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_X");

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
  tcase_add_test(tcase, s21_sprintf_x_test_14);

  return tcase;
}