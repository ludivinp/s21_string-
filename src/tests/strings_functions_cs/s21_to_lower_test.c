#include "../../includes/s21_mainTestsRun.h"

// s21_to_lower

START_TEST(test_to_lower_01) {
  const char *src = "Hello, World!";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(test_to_lower_02) {
  const char *src = "UPPERCASE";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "uppercase");
  free(result);
}
END_TEST

START_TEST(test_to_lower_03) {
  const char *src = "12345";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "12345");
  free(result);
}
END_TEST

START_TEST(test_to_lower_04) {
  const char *src = "!@#$%^&*()";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "!@#$%^&*()");
  free(result);
}
END_TEST

START_TEST(test_to_lower_05) {
  const char *src = "";
  char *result = s21_to_lower(src);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_to_lower");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_to_lower_01);
  tcase_add_test(tc_core, test_to_lower_02);
  tcase_add_test(tc_core, test_to_lower_03);
  tcase_add_test(tc_core, test_to_lower_04);
  tcase_add_test(tc_core, test_to_lower_05);

  suite_add_tcase(suite, tc_core);

  return suite;
}
