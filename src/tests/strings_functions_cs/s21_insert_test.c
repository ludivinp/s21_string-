#include "../../includes/s21_mainTestsRun.h"

// s21_insert

START_TEST(test_insert_01) {
  const char *src = "";
  const char *str = "";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_insert_02) {
  const char *src = "aaaaa";
  const char *str = "bbb";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "bbbaaaaa");
  free(result);
}
END_TEST

START_TEST(test_insert_03) {
  const char *src = "aaaaa";
  const char *str = "bbb";
  size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "aaaaabbb");
  free(result);
}
END_TEST

START_TEST(test_insert_04) {
  const char *src = "aaaaa";
  const char *str = "bbb";
  size_t start_index = 2;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "aabbbaaa");
  free(result);
}
END_TEST

START_TEST(test_insert_05) {
  const char *src = "";
  const char *str = "bbb";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "bbb");
  free(result);
}
END_TEST

START_TEST(test_insert_06) {
  const char *src = "aaaa";
  const char *str = "";
  size_t start_index = 0;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "aaaa");
  free(result);
}
END_TEST

START_TEST(test_insert_07) {
  const char *src = "aaaa";
  const char *str = "";
  size_t start_index = 4;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "aaaa");
  free(result);
}
END_TEST

START_TEST(test_insert_08) {
  const char *src = "aaaa";
  const char *str = "";
  size_t start_index = 2;
  char *result = s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "aaaa");
  free(result);
}
END_TEST

START_TEST(test_insert_09) {
  const char *src = "aaaa";
  const char *str = "bbb";
  size_t start_index = 5;
  char *result = s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
  free(result);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("s21_insert");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_insert_01);
  tcase_add_test(tc_core, test_insert_02);
  tcase_add_test(tc_core, test_insert_03);
  tcase_add_test(tc_core, test_insert_04);
  tcase_add_test(tc_core, test_insert_05);
  tcase_add_test(tc_core, test_insert_06);
  tcase_add_test(tc_core, test_insert_07);
  tcase_add_test(tc_core, test_insert_08);
  tcase_add_test(tc_core, test_insert_09);

  suite_add_tcase(suite, tc_core);

  return suite;
}
