#include <limits.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

#define DEFAULT_INT_01 0
#define DEFAULT_INT_02 INT16_MAX
#define DEFAULT_INT_03 INT16_MIN
#define DEFAULT_INT_04 INT32_MIN
#define DEFAULT_INT_05 INT32_MAX

START_TEST(s21_sprintf_u_test_00) {
  const char *format_str =
      "\t First = |%u|,\n\t Second = |%u|,\n\t Third = |%u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_01) {
  const char *format_str =
      "\t First = |%+u|,\n\t Second = |%+u|,\n\t Third = |%+u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_03) {
  const char *format_str =
      "\t First = |% u|,\n\t Second = |% u|,\n\t Third = |% u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_04) {
  const char *format_str =
      "\t First = |%1u|,\n\t Second = |%2u|,\n\t Third = |%5u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_05) {
  const char *format_str =
      "\t First = |%-1u|,\n\t Second = |%-2u|,\n\t Third = |%-5u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_06) {
  const char *format_str =
      "\t First = |%01u|,\n\t Second = |%02u|,\n\t Third = |%05u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_07) {
  const char *format_str =
      "\t First = |%.0u|,\n\t Second = |%.10u|,\n\t Third = |%.50u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_08) {
  const char *format_str =
      "\t First = |%20.0u|,\n\t Second = |%10.1u|,\n\t Third = |%5.5u|\n\t ";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_09) {
  const char *format_str =
      "\t First = |%-20.0u|,\n\t Second = |%-10.1u|,\n\t Third = "
      "|%-5.5u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_10) {
  const char *format_str =
      "\t First = |%+-20.0u|,\n\t Second = |%+-10.1u|,\n\t Third = "
      "|%+-5.5u|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_11) {
  const char *format_str =
      "\t First = |%lu|,\n\t Second = |%lu|,\n\t Third = "
      "|%lu|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_12) {
  const char *format_str =
      "\t First = |%llu|,\n\t Second = |%llu|,\n\t Third = "
      "|%llu|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_13) {
  const char *format_str =
      "\t First = |%hu|,\n\t Second = |%hu|,\n\t Third = "
      "|%hu|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_u_test_14) {
  const char *format_str =
      "\t First = |%hhu|,\n\t Second = |%hhu|,\n\t Third = "
      "|%hhu|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_u() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_u");

  tcase_add_test(tcase, s21_sprintf_u_test_00);
  tcase_add_test(tcase, s21_sprintf_u_test_01);
  tcase_add_test(tcase, s21_sprintf_u_test_03);
  tcase_add_test(tcase, s21_sprintf_u_test_04);
  tcase_add_test(tcase, s21_sprintf_u_test_05);
  tcase_add_test(tcase, s21_sprintf_u_test_06);
  tcase_add_test(tcase, s21_sprintf_u_test_07);
  tcase_add_test(tcase, s21_sprintf_u_test_08);
  tcase_add_test(tcase, s21_sprintf_u_test_09);
  tcase_add_test(tcase, s21_sprintf_u_test_10);
  tcase_add_test(tcase, s21_sprintf_u_test_11);
  tcase_add_test(tcase, s21_sprintf_u_test_12);
  tcase_add_test(tcase, s21_sprintf_u_test_13);
  tcase_add_test(tcase, s21_sprintf_u_test_14);

  return tcase;
}