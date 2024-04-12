#include <limits.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

START_TEST(s21_sprintf_i_test_00) {
  const char *format_str = "\t First = |%i|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_01) {
  const char *format_str = "\t First = |%i|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, 0);
  const int s21 = s21_sprintf(s21_output, format_str, 0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_02) {
  const char *format_str = "\t First = |%i|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_03) {
  const char *format_str =
      "\t First = |%+i|,\n\t Second = |%+i|,\n\t Third = |%+i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_04) {
  const char *format_str =
      "\t First = |% i|,\n\t Second = |% i|,\n\t Third = |% i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_05) {
  const char *format_str =
      "\t First = |%1i|,\n\t Second = |%10i|,\n\t Third = |%100i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_06) {
  const char *format_str =
      "\t First = |%-1i|,\n\t Second = |%-2i|,\n\t Third = |%-5i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_07) {
  const char *format_str =
      "\t First = |%01i|,\n\t Second = |%010i|,\n\t Third = |%020i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_08) {
  const char *format_str =
      "\t First = |%.0i|,\n\t Second = |%.1i|,\n\t Third = |%.10i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_09) {
  const char *format_str =
      "\t First = |%20.0i|,\n\t Second = |%10.1i|,\n\t Third = |%20.20i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_10) {
  const char *format_str =
      "\t First = |%-20.0i|,\n\t Second = |%-10.1i|,\n\t Third = |%-5.5i|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_11) {
  const char *format_str =
      "\t First = |%+-20.0i|,\n\t Second = |%+-10.1i|,\n\t Third = |%+-5.5i|";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_12) {
  const char *format_str =
      "\t First = |%li|,\n\t Second = |%li|,\n\t Third = |%li|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_13) {
  const char *format_str =
      "\t First = |%lli|,\n\t Second = |%lli|,\n\t Third = |%lli|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_14) {
  const char *format_str =
      "\t First = |%hi|,\n\t Second = |%hi|,\n\t Third = |%hi|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_i_test_15) {
  const char *format_str =
      "\t First = |%hhi|,\n\t Second = |%hhi|,\n\t Third = |%hhi|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_i() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_i");

  tcase_add_test(tcase, s21_sprintf_i_test_00);
  tcase_add_test(tcase, s21_sprintf_i_test_01);
  tcase_add_test(tcase, s21_sprintf_i_test_02);
  tcase_add_test(tcase, s21_sprintf_i_test_03);
  tcase_add_test(tcase, s21_sprintf_i_test_04);
  tcase_add_test(tcase, s21_sprintf_i_test_05);
  tcase_add_test(tcase, s21_sprintf_i_test_06);
  tcase_add_test(tcase, s21_sprintf_i_test_07);
  tcase_add_test(tcase, s21_sprintf_i_test_08);
  tcase_add_test(tcase, s21_sprintf_i_test_09);
  tcase_add_test(tcase, s21_sprintf_i_test_10);
  tcase_add_test(tcase, s21_sprintf_i_test_11);
  tcase_add_test(tcase, s21_sprintf_i_test_12);
  tcase_add_test(tcase, s21_sprintf_i_test_13);
  tcase_add_test(tcase, s21_sprintf_i_test_14);
  tcase_add_test(tcase, s21_sprintf_i_test_15);

  return tcase;
}