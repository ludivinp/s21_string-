#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

#define BIG_DOUBLE 1234567890.0987654321

START_TEST(s21_sprintf_e_test_00) {
  const char *format_str = "First = |%e|,\nSecond = |%e|,\nThird = |%e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_01) {
  const char *format_str =
      "First = |%-1e|,\nSecond = |%-10e|,\nThird = |%-100e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_02) {
  const char *format_str = "First = |%+e|,\nSecond = |%+e|,\nThird = |%+e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_03) {
  const char *format_str =
      "First = |%01e|,\nSecond = |%010e|,\nThird = |%010e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_04) {
  const char *format_str =
      "First = |%.0e|,\nSecond = |%.10e|,\nThird = |%.16e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_05) {
  const char *format_str =
      "First = |%.0e|,\nSecond = |%.10e|,\nThird = |%.16e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_06) {
  const char *format_str =
      "First = |%1.0e|,\nSecond = |%10.10e|,\nThird = |%16.16e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_07) {
  const char *format_str =
      "First = |%-1.0e|,\nSecond = |%-10.10e|,\nThird = |%-16.16e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_08) {
  const char *format_str =
      "First = |%+-1.0e|,\nSecond = |%+-10.10e|,\nThird = |%+-16.16e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_09) {
  const char *format_str = "First = |%Le|,\nSecond = |%Le|,\nThird = |%Le|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, LDBL_MIN, 0.0L, (long double)BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, LDBL_MIN, 0.0L,
                              (long double)BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_10) {
  const char *format_str =
      "First = |%+-1.0Le|,\nSecond = |%+-10.10Le|,\nThird = |%+-16.16Le|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, LDBL_MIN, 0.0L, (long double)BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, LDBL_MIN, 0.0L,
                              (long double)BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_e_test_11) {
  const char *format_str =
      "First = |%#.0e|,\nSecond = |%#.0e|,\nThird = |%#.0e|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0.0, 69.0);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0.0, 69.0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_e() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_e");

  tcase_add_test(tcase, s21_sprintf_e_test_00);
  tcase_add_test(tcase, s21_sprintf_e_test_01);
  tcase_add_test(tcase, s21_sprintf_e_test_02);
  tcase_add_test(tcase, s21_sprintf_e_test_03);
  tcase_add_test(tcase, s21_sprintf_e_test_04);
  tcase_add_test(tcase, s21_sprintf_e_test_05);
  tcase_add_test(tcase, s21_sprintf_e_test_06);
  tcase_add_test(tcase, s21_sprintf_e_test_07);
  tcase_add_test(tcase, s21_sprintf_e_test_08);
  tcase_add_test(tcase, s21_sprintf_e_test_09);
  tcase_add_test(tcase, s21_sprintf_e_test_10);
  tcase_add_test(tcase, s21_sprintf_e_test_11);

  return tcase;
}