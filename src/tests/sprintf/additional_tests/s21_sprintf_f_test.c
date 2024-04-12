// TODO: What's up with the 'L' length flag?

#include <float.h>

#include "../../../includes/s21_mainTestsRun.h"

#define MAX_STR_LEN 1000

#define BIG_DOUBLE 1234567890.0987654321

START_TEST(s21_sprintf_f_test_00) {
  const char *format_str =
      "\t First = |%f|,\n\t Second = |%f|,\n\t Third = |%f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_01) {
  const char *format_str =
      "\t First = |%-1f|,\n\t Second = |%-10f|,\n\t Third = |%-100f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_02) {
  const char *format_str =
      "\t First = |%+f|,\n\t Second = |%+f|,\n\t Third = |%+f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_03) {
  const char *format_str =
      "\t First = |%01f|,\n\t Second = |%010f|,\n\t Third = |%020f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_04) {
  const char *format_str =
      "\t First = |%.0f|,\n\t Second = |%.10f|,\n\t Third = |%.100f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_05) {
  const char *format_str =
      "\t First = |%.0f|,\n\t Second = |%.10f|,\n\t Third = |%.100f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_06) {
  const char *format_str =
      "\t First = |%1.0f|,\n\t Second = |%10.10f|,\n\t Third = |%100.100f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_07) {
  const char *format_str =
      "\t First = |%-1.0f|,\n\t Second = |%-10.10f|,\n\t Third = "
      "|%-100.100f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_08) {
  const char *format_str =
      "\t First = |%+-1.0f|,\n\t Second = |%+-10.10f|,\n\t Third = "
      "|%+-100.100f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE);
  const int s21 = s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_09) {
  const char *format_str =
      "\t First = |%*f|,\n\t Second = |%*f|,\n\t Third = |%*f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE, 0, 10, 100);
  const int s21 =
      s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE, 0, 10, 100);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_10) {
  const char *format_str =
      "\t First = |%.*f|,\n\t Second = |%.*f|,\n\t Third = |%.*f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, DBL_MIN, 0, BIG_DOUBLE, 0, 10, 100);
  const int s21 =
      s21_sprintf(s21_output, format_str, DBL_MIN, 0, BIG_DOUBLE, 0, 10, 100);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_11) {
  const char *format_str = "First = |%Lf|,\nSecond = |%Lf|,\nThird = |%Lf|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, LDBL_MIN, 0.0L, 0.0L);
  const int s21 = s21_sprintf(s21_output, format_str, LDBL_MIN, 0.0L, 0.0L);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_12) {
  const char *format_str =
      "First = |%+-1.0Lf|,\nSecond = |%+-10.10Lf|,\nThird = |%+-16.16Lf|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std = sprintf(std_output, format_str, LDBL_MIN, 0.0L, 0.0L);
  const int s21 = s21_sprintf(s21_output, format_str, LDBL_MIN, 0.0L, 0.0L);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

START_TEST(s21_sprintf_f_test_13) {
  const char *format_str =
      "First = |%#.0f|,\nSecond = |%#.0f|,\nThird = |%#.0f|\n";

  char std_output[MAX_STR_LEN] = {};
  char s21_output[MAX_STR_LEN] = {};

  const int std =
      sprintf(std_output, format_str, LDBL_MIN, 123456.0, 1234567.0);
  const int s21 =
      s21_sprintf(s21_output, format_str, LDBL_MIN, 123456.0, 1234567.0);

  ck_assert_pstr_eq(std_output, s21_output);
  ck_assert_int_eq(std, s21);
}
END_TEST

TCase *s21_sprintf_tcase_f() {
  TCase *tcase = tcase_create("s21_sprintf_tcase_f");

  tcase_add_test(tcase, s21_sprintf_f_test_00);
  tcase_add_test(tcase, s21_sprintf_f_test_01);
  tcase_add_test(tcase, s21_sprintf_f_test_02);
  tcase_add_test(tcase, s21_sprintf_f_test_03);
  tcase_add_test(tcase, s21_sprintf_f_test_04);
  tcase_add_test(tcase, s21_sprintf_f_test_05);
  tcase_add_test(tcase, s21_sprintf_f_test_06);
  tcase_add_test(tcase, s21_sprintf_f_test_07);
  tcase_add_test(tcase, s21_sprintf_f_test_08);
  tcase_add_test(tcase, s21_sprintf_f_test_09);
  tcase_add_test(tcase, s21_sprintf_f_test_10);
  tcase_add_test(tcase, s21_sprintf_f_test_11);
  tcase_add_test(tcase, s21_sprintf_f_test_12);
  tcase_add_test(tcase, s21_sprintf_f_test_13);

  return tcase;
}