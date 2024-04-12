#include "../../includes/s21_mainTestsRun.h"

// s21_is_eq_ch
START_TEST(s21_is_eq_ch0) {
  char s2[] = "lkldsfioosdfif";
  ck_assert_int_eq(1, s21_is_eq_ch('o', s2));
}
END_TEST

Suite *s21_is_eq_ch_suite() {
  Suite *s;
  TCase *tc_is_eq_ch;

  s = suite_create("S21_is_eq_ch");
  tc_is_eq_ch = tcase_create("core");

  tcase_add_test(tc_is_eq_ch, s21_is_eq_ch0);

  suite_add_tcase(s, tc_is_eq_ch);

  return s;
}