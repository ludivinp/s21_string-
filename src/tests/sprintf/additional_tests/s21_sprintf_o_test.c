#include <limits.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

#define DEFAULT_INT_01 0
#define DEFAULT_INT_02 INT16_MAX
#define DEFAULT_INT_03 INT16_MIN
#define DEFAULT_INT_04 INT32_MIN
#define DEFAULT_INT_05 INT32_MAX

START_TEST(s21_sprintf_o_test_00) {
  const char *format_str =
      "\t First = |%o|,\n\t Second = |%o|,\n\t Third = |%o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_01) {
  const char *format_str =
      "\t First = |%+o|,\n\t Second = |%+o|,\n\t Third = |%+o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_02) {
  const char *format_str =
      "\t First = |%#o|,\n\t Second = |%#o|,\n\t Third = |%#o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_03) {
  const char *format_str =
      "\t First = |% o|,\n\t Second = |% o|,\n\t Third = |% o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_04) {
  const char *format_str =
      "\t First = |%1o|,\n\t Second = |%2o|,\n\t Third = |%5o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_05) {
  const char *format_str =
      "\t First = |%-1o|,\n\t Second = |%-2o|,\n\t Third = |%-5o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_06) {
  const char *format_str =
      "\t First = |%01o|,\n\t Second = |%02o|,\n\t Third = |%05o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_07) {
  const char *format_str =
      "\t First = |%.0o|,\n\t Second = |%.10o|,\n\t Third = |%.100o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_08) {
  const char *format_str =
      "\t First = |%20.0o|,\n\t Second = |%10.1o|,\n\t Third = |%5.5o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_09) {
  const char *format_str =
      "\t First = |%-20.0o|,\n\t Second = |%-10.1o|,\n\t Third = |%-5.5o|\n\t";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_10) {
  const char *format_str =
      "\t First = |%+-20.0o|,\n\t Second = |%+-10.1o|,\n\t Third = "
      "|%+-5.5o|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_11) {
  const char *format_str =
      "\t First = |%lo|,\n\t Second = |%lo|,\n\t Third = "
      "|%lo|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_12) {
  const char *format_str =
      "\t First = |%llo|,\n\t Second = |%llo|,\n\t Third = "
      "|%llo|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_13) {
  const char *format_str =
      "\t First = |%ho|,\n\t Second = |%ho|,\n\t Third = "
      "|%ho|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_o_test_14) {
  const char *format_str =
      "\t First = |%hho|,\n\t Second = |%hho|,\n\t Third = "
      "|%hho|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, INT_MIN, 0, INT_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, INT_MIN, 0, INT_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_o() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_o");

  tcase_add_test(tcase, s21_sprintf_o_test_00);
  tcase_add_test(tcase, s21_sprintf_o_test_01);
  tcase_add_test(tcase, s21_sprintf_o_test_02);
  tcase_add_test(tcase, s21_sprintf_o_test_03);
  tcase_add_test(tcase, s21_sprintf_o_test_04);
  tcase_add_test(tcase, s21_sprintf_o_test_05);
  tcase_add_test(tcase, s21_sprintf_o_test_06);
  tcase_add_test(tcase, s21_sprintf_o_test_07);
  tcase_add_test(tcase, s21_sprintf_o_test_08);
  tcase_add_test(tcase, s21_sprintf_o_test_09);
  tcase_add_test(tcase, s21_sprintf_o_test_10);
  tcase_add_test(tcase, s21_sprintf_o_test_11);
  tcase_add_test(tcase, s21_sprintf_o_test_12);
  tcase_add_test(tcase, s21_sprintf_o_test_13);
  tcase_add_test(tcase, s21_sprintf_o_test_14);

  return tcase;
}