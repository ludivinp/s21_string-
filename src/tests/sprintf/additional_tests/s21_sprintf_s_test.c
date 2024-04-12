#include <check.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

#define DEFAULT_STRING_01 "Hello World!!!"
#define DEFAULT_STRING_02 " \tStandart string s21 scringe stest 12345\n"
#define DEFAULT_STRING_03 "\\TEST|Русский текст|TEST\\"
#define DEFAULT_STRING_04 "A"
#define DEFAULT_STRING_05 ""

START_TEST(s21_sprintf_s_test_00) {
  const char *format_str =
      "\t First = |%s|,\n\t Second = |%s|,\n\t Third = |%s|\n\t Fourth = "
      "|%s|.\n\t Fifth = |%s|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
              DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
                  DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_s_test_01) {
  const char *format_str =
      "\t First = |%0s|,\n\t Second = |%1s|,\n\t Third = |%5s|\n\t Fourth = "
      "|%10s|.\n\t Fifth = |%30s|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
              DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
                  DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_s_test_02) {
  const char *format_str =
      "\t First = |%-0s|,\n\t Second = |%-1s|,\n\t Third = |%-5s|\n\t Fourth "
      "= "
      "|%-10s|.\n\t Fifth = |%-30s|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
              DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
                  DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_s_test_03) {
  const char *format_str =
      "\t First = |%.0s|,\n\t Second = |%.1s|,\n\t Third = |%.5s|\n\t Fourth "
      "= "
      "|%.10s|.\n\t Fifth = |%.30s|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
              DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
                  DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_s_test_04) {
  const char *format_str =
      "\t First = |%-s|,\n\t Second = |%-s|,\n\t Third = |%-s|\n\t Fourth = "
      "|%-s|.\n\t Fifth = |%-s|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
              DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
                  DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_s_test_05) {
  const char *format_str =
      "\t First = |%30.0s|,\n\t Second = |%10.1s|,\n\t Third = |%5.5s|\n\t "
      "Fourth = "
      "|%1.10s|.\n\t Fifth = |%-30.30s|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
              DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
                  DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_s_test_06) {
  const char *format_str =
      "\t First = |%-30.0s|,\n\t Second = |%-10.1s|,\n\t Third = "
      "|%-5.5s|\n\t "
      "Fourth = "
      "|%-1.10s|.\n\t Fifth = |%-30.30s|,\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
              DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);
  const int s21 =
      s21_sprintf(s21_output, format_str, DEFAULT_STRING_01, DEFAULT_STRING_02,
                  DEFAULT_STRING_03, DEFAULT_STRING_04, DEFAULT_STRING_05);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_s() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_s");

  tcase_add_test(tcase, s21_sprintf_s_test_00);
  tcase_add_test(tcase, s21_sprintf_s_test_01);
  tcase_add_test(tcase, s21_sprintf_s_test_02);
  tcase_add_test(tcase, s21_sprintf_s_test_03);
  tcase_add_test(tcase, s21_sprintf_s_test_04);
  tcase_add_test(tcase, s21_sprintf_s_test_05);
  tcase_add_test(tcase, s21_sprintf_s_test_06);

  return tcase;
}