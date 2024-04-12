#include <math.h>

#include "../../includes/s21_mainTestsRun.h"

START_TEST(ld_to_str_0) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = 2.0L;
  s21_ld_to_str(num, s, 100, 1);
  sprintf(tru, "%#.*Lf", 1, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_1) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = 5.55L;
  s21_ld_to_str(num, s, 100, 2);
  sprintf(tru, "%#.*Lf", 2, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_2) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = -5.55L;
  s21_ld_to_str(num, s, 100, 2);
  sprintf(tru, "%#.*Lf", 2, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_3) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = -5.555L;
  s21_ld_to_str(num, s, 100, 1);
  sprintf(tru, "%#.*Lf", 1, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_4) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = 2.9843954374356864L;
  s21_ld_to_str(num, s, 100, 10);
  sprintf(tru, "%#.*Lf", 10, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_5) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = 9875359467895.1L;
  s21_ld_to_str(num, s, 100, 1);
  sprintf(tru, "%#.*Lf", 1, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_6) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = 0.0L;
  s21_ld_to_str(num, s, 100, 10);
  sprintf(tru, "%#.*Lf", 10, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_7) {
  char s[100] = {'\0'};
  char tru[100] = {'\0'};
  long double num = 0.0L;
  s21_ld_to_str(num, s, 100, 30);
  sprintf(tru, "%#.*Lf", 30, num);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_8) {
  char string[32] = {0};

  s21_ld_to_str(-INFINITY, string, 128, 16);
  ck_assert_str_eq(string, "-inf");
}
END_TEST

START_TEST(ld_to_str_9) {
  char string[32] = {0};

  s21_ld_to_str(INFINITY, string, 128, 16);
  ck_assert_str_eq(string, "inf");
}
END_TEST

START_TEST(ld_to_str_10) {
  char string[32] = {0};

  s21_ld_to_str(NAN, string, 128, 16);
  ck_assert_str_eq(string, "nan");
}
END_TEST

START_TEST(ld_to_str_11) {
  for (unsigned int i = 0; i < 20; ++i) {
    char s1[200] = {'\0'};
    char tru[200] = {'\0'};
    srand(i);
    int acc = rand() % 10;
    long double num = (long double)rand();
    for (int i = 0; i < acc + 1; ++i) {
      num /= 10.L;
    }

    s21_ld_to_str(num, s1, 200, acc);
    sprintf(tru, "%.*Lf", acc, num);
    ck_assert_str_eq(s1, tru);
  }
}
END_TEST

START_TEST(ld_to_str_12) {
  char s[] = {"123"};
  char tru[] = {"321"};
  s21_mirrorize_str(s, 4, 0, 3);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_13) {
  char s[] = {"1234"};
  char tru[] = {"4231"};
  s21_swap(s + 0, s + 3);
  ck_assert_str_eq(s, tru);
}
END_TEST

START_TEST(ld_to_str_14) {
  char *x = NULL;
  char *y = NULL;

  s21_swap(x, y);
  ck_assert_pstr_eq(x, y);
}
END_TEST

START_TEST(ld_to_str_15) {
  char *x = NULL;

  s21_ld_to_str(128.0, x, 1, 1);

  ck_assert_pstr_eq(x, NULL);
}
END_TEST

Suite *s21_ld_to_str_suite() {
  Suite *s = suite_create("s21_ld_to_str");
  TCase *tc_core = tcase_create("s21_ld_to_str");

  tcase_add_test(tc_core, ld_to_str_0);
  tcase_add_test(tc_core, ld_to_str_1);
  tcase_add_test(tc_core, ld_to_str_2);
  tcase_add_test(tc_core, ld_to_str_3);
  tcase_add_test(tc_core, ld_to_str_4);
  tcase_add_test(tc_core, ld_to_str_5);
  tcase_add_test(tc_core, ld_to_str_6);
  tcase_add_test(tc_core, ld_to_str_7);
  tcase_add_test(tc_core, ld_to_str_8);
  tcase_add_test(tc_core, ld_to_str_9);
  tcase_add_test(tc_core, ld_to_str_10);
  tcase_add_test(tc_core, ld_to_str_11);
  tcase_add_test(tc_core, ld_to_str_12);
  tcase_add_test(tc_core, ld_to_str_13);
  tcase_add_test(tc_core, ld_to_str_14);
  tcase_add_test(tc_core, ld_to_str_15);

  suite_add_tcase(s, tc_core);
  return s;
}
