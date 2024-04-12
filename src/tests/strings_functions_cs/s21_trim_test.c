#include "../../includes/s21_mainTestsRun.h"

// s21_trim

START_TEST(test_trim_01) {
  const char *src = "   Hello, World!   ";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_02) {
  const char *src = "Hello, World!";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_03) {
  const char *src = "";
  const char *trim_chars = " ";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_trim_04) {
  const char *src = "!!!---Hello, World!!---!!!";
  const char *trim_chars = "!-";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World");
  free(result);
}
END_TEST

START_TEST(test_trim_05) {
  const char *src = "\t  \nHello, World!\t\n ";
  const char *trim_chars = " \t\n";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "Hello, World!");
  free(result);
}
END_TEST

START_TEST(test_trim_06) {
  const char *src = "abcdefg";
  const char *trim_chars = "abcdefg";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_trim_07) {
  const char *src = "   Hello, World!   ";
  const char *trim_chars = "";
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, "   Hello, World!   ");
  free(result);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_trim");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_trim_01);
  tcase_add_test(tc_core, test_trim_02);
  tcase_add_test(tc_core, test_trim_03);
  tcase_add_test(tc_core, test_trim_04);
  tcase_add_test(tc_core, test_trim_05);
  tcase_add_test(tc_core, test_trim_06);
  tcase_add_test(tc_core, test_trim_07);

  suite_add_tcase(suite, tc_core);

  return suite;
}
