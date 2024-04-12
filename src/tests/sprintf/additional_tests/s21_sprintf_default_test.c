#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 256

START_TEST(s21_sprintf_default_test_00) {
  const char str[] = "STANDART_test_string_12340-928021985";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, str);
  const int s21 = s21_sprintf(s21_output, str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_default_test_01) {
  const char str[] = "-[-ew0divjuvosvih09i03r9];";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, str);
  const int s21 = s21_sprintf(s21_output, str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_default_test_02) {
  const char str[] = "        ";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, str);
  const int s21 = s21_sprintf(s21_output, str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_default_test_03) {
  const char str[] = "\t\t\t\t\\\\\n\b";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, str);
  const int s21 = s21_sprintf(s21_output, str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_default_test_04) {
  const char str[] = "1";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, str);
  const int s21 = s21_sprintf(s21_output, str);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_default() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_default");

  tcase_add_test(tcase, s21_sprintf_default_test_00);
  tcase_add_test(tcase, s21_sprintf_default_test_01);
  tcase_add_test(tcase, s21_sprintf_default_test_02);
  tcase_add_test(tcase, s21_sprintf_default_test_03);
  tcase_add_test(tcase, s21_sprintf_default_test_04);

  return tcase;
}