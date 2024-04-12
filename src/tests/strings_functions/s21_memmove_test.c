#include "../../includes/s21_mainTestsRun.h"

START_TEST(s21_memmove00) {
  char dest[50] = {};
  char src[] = "1234TEST string.-]0o [acnoivbcwr9eog8h!^^#*]";
  ck_assert_str_eq(memmove(dest, src, 45), s21_memmove(dest, src, 45));
}
END_TEST

START_TEST(s21_memmove01) {
  char dest[50] = {};
  char src[] = "1234TEST string.-]0o [acnoivbcwr9eog8h!^^#*]";
  ck_assert_str_eq(memmove(dest, src, 1), s21_memmove(dest, src, 1));
}
END_TEST

START_TEST(s21_memmove02) {
  char dest[50] = {};
  char src[] = "1234TEST string.-]0o [acnoivbcwr9eog8h!^^#*]";
  ck_assert_str_eq(memmove(dest, src, 0), s21_memmove(dest, src, 0));
}
END_TEST

START_TEST(s21_memmove03) {
  char dest[100] = {};
  char src[] = "\n1234TEST \nstring.-]0o \n[acn\toivbc\twr9eog8h!^\t^#*]";
  ck_assert_str_eq(memmove(dest, src, 51), s21_memmove(dest, src, 51));
}
END_TEST

START_TEST(s21_memmove04) {
  char src[] = "\n1234TEST \nstring.-]0o \n[acn\toivbc\twr9eog8h!^\t^#*]";
  ck_assert_str_eq(memmove(src + 5, src, 10), s21_memmove(src + 5, src, 10));
}
END_TEST

START_TEST(s21_memmove05) {
  char src[] = "\n1234TEST \nstring.-]0o \n[acn\toivbc\twr9eog8h!^\t^#*]";
  ck_assert_str_eq(memmove(src, src + 5, 10), s21_memmove(src, src + 5, 10));
}
END_TEST

START_TEST(s21_memmove06) {
  char dest[] = "";
  char src[] = "";
  ck_assert_str_eq(memmove(dest, src, 1), s21_memmove(dest, src, 1));
}
END_TEST

Suite *s21_memmove_suite() {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_memmove");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_memmove00);
  tcase_add_test(tc_core, s21_memmove01);
  tcase_add_test(tc_core, s21_memmove02);
  tcase_add_test(tc_core, s21_memmove03);
  tcase_add_test(tc_core, s21_memmove04);
  tcase_add_test(tc_core, s21_memmove05);
  tcase_add_test(tc_core, s21_memmove06);

  suite_add_tcase(s, tc_core);
  return s;
}
