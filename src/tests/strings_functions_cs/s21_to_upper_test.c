#include "../../includes/s21_mainTestsRun.h"

// s21_to_upper

START_TEST(test_to_upper_01) {
  const char *src = "Hello, World!";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(test_to_upper_02) {
  const char *src = "lowercase";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "LOWERCASE");
  free(result);
}
END_TEST

START_TEST(test_to_upper_03) {
  const char *src = "12345";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(test_to_upper_04) {
  const char *src = "!@#$%^&*()";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_to_upper_05) {
  const char *src = "";
  char *result = s21_to_upper(src);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_to_upper");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_to_upper_01);
  tcase_add_test(tc_core, test_to_upper_02);
  tcase_add_test(tc_core, test_to_upper_03);
  tcase_add_test(tc_core, test_to_upper_04);
  tcase_add_test(tc_core, test_to_upper_05);

  suite_add_tcase(suite, tc_core);

  return suite;
}
