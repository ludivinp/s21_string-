#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 100

#define DEFAULT_SYMBOL_01 'A'
#define DEFAULT_SYMBOL_02 '?'
#define DEFAULT_SYMBOL_03 '\n'
#define DEFAULT_SYMBOL_04 '\0'

START_TEST(s21_sprintf_c_test_00) {
  const char *format_str =
      "\t First = |%c|,\n\t Second = |%c|,\n\t Third = |%c|\n\t Fourth = "
      "|%c|.\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
              DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
                  DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_c_test_01) {
  const char *format_str =
      "\t First = |%1c|,\n\t Second = |%3c|,\n\t Third = |%5c|\n\t Fourth = "
      "|%15c|.\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
              DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
                  DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_c_test_02) {
  const char *format_str =
      "\t First = |%-1c|,\n\t Second = |%-3c|,\n\t Third = |%-5c|\n\t Fourth "
      "= |%-15c|.\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
              DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
                  DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_c_test_03) {
  const char *format_str =
      "\t First = |%-1lc|,\n\t Second = |%-3lc|,\n\t Third = |%-5lc|\n\t "
      "Fourth = |%-15lc|.\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
              DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_SYMBOL_01, DEFAULT_SYMBOL_02,
                  DEFAULT_SYMBOL_03, DEFAULT_SYMBOL_04);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_c() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_c");

  tcase_add_test(tcase, s21_sprintf_c_test_00);
  tcase_add_test(tcase, s21_sprintf_c_test_01);
  tcase_add_test(tcase, s21_sprintf_c_test_02);
  tcase_add_test(tcase, s21_sprintf_c_test_03);

  return tcase;
}