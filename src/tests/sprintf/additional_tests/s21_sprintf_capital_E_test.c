#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

#define BIG_DOUBLE 1234567890.0987654321

START_TEST(s21_sprintf_E_test_00) {
  const char *format_str = "First = |%E|,\nSecond = |%E|,\nThird = |%E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_01) {
  const char *format_str =
      "First = |%-1E|,\nSecond = |%-10E|,\nThird = |%-16E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_02) {
  const char *format_str = "First = |%+E|,\nSecond = |%+E|,\nThird = |%+E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_03) {
  const char *format_str =
      "First = |%01E|,\nSecond = |%010E|,\nThird = |%016E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_04) {
  const char *format_str =
      "First = |%.0E|,\nSecond = |%.10E|,\nThird = |%.16E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_05) {
  const char *format_str =
      "First = |%.0E|,\nSecond = |%.10E|,\nThird = |%.16E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_06) {
  const char *format_str =
      "First = |%1.0E|,\nSecond = |%10.10E|,\nThird = |%16.16E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_07) {
  const char *format_str =
      "First = |%-1.0E|,\nSecond = |%-10.10E|,\nThird = |%-16.16E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_08) {
  const char *format_str =
      "First = |%+-1.0E|,\nSecond = |%+-10.10E|,\nThird = |%+-16.16E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_09) {
  const char *format_str = "First = |%LE|,\nSecond = |%LE|,\nThird = |%LE|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, LDBL_MIN, 0.0L, LDBL_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, LDBL_MIN, 0.0L, LDBL_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_10) {
  const char *format_str =
      "First = |%+-1.0LE|,\nSecond = |%+-10.10LE|,\nThird = |%+-16.16LE|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, LDBL_MIN, 0.0L, LDBL_MAX);
  const int s21 = s21_sprintf(s21_output, format_str, LDBL_MIN, 0.0L, LDBL_MAX);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_11) {
  const char *format_str = "First = |%LE|,\nSecond = |%E|,\nThird = |%E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, LDBL_MIN, INFINITY, -INFINITY);
  const int s21 =
      s21_sprintf(s21_output, format_str, LDBL_MIN, INFINITY, -INFINITY);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_E_test_12) {
  const char *format_str =
      "First = |%#.0E|,\nSecond = |%#.0E|,\nThird = |%#.0E|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, 69.0);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, 69.0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_E() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_E");

  tcase_add_test(tcase, s21_sprintf_E_test_00);
  tcase_add_test(tcase, s21_sprintf_E_test_01);
  tcase_add_test(tcase, s21_sprintf_E_test_02);
  tcase_add_test(tcase, s21_sprintf_E_test_03);
  tcase_add_test(tcase, s21_sprintf_E_test_04);
  tcase_add_test(tcase, s21_sprintf_E_test_05);
  tcase_add_test(tcase, s21_sprintf_E_test_06);
  tcase_add_test(tcase, s21_sprintf_E_test_07);
  tcase_add_test(tcase, s21_sprintf_E_test_08);
  tcase_add_test(tcase, s21_sprintf_E_test_09);
  tcase_add_test(tcase, s21_sprintf_E_test_10);
  tcase_add_test(tcase, s21_sprintf_E_test_11);
  tcase_add_test(tcase, s21_sprintf_E_test_12);

  return tcase;
}