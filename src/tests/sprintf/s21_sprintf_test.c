#include "../../includes/s21_mainTestsRun.h"

Suite *s21_sprintf_suite() {
  Suite *suite = suite_create("s21_sprintf");

  suite_add_tcase(suite, s21_sprintf_tcase_default());
  suite_add_tcase(suite, s21_sprintf_tcase_c());
  suite_add_tcase(suite, s21_sprintf_tcase_d());
  suite_add_tcase(suite, s21_sprintf_tcase_i());
  suite_add_tcase(suite, s21_sprintf_tcase_e());
  suite_add_tcase(suite, s21_sprintf_tcase_E());
  suite_add_tcase(suite, s21_sprintf_tcase_f());
  suite_add_tcase(suite, s21_sprintf_tcase_g());
  suite_add_tcase(suite, s21_sprintf_tcase_G());
  suite_add_tcase(suite, s21_sprintf_tcase_o());
  suite_add_tcase(suite, s21_sprintf_tcase_s());
  suite_add_tcase(suite, s21_sprintf_tcase_u());
  suite_add_tcase(suite, s21_sprintf_tcase_x());
  suite_add_tcase(suite, s21_sprintf_tcase_X());
  suite_add_tcase(suite, s21_sprintf_tcase_p());
  suite_add_tcase(suite, s21_sprintf_tcase_n());
  suite_add_tcase(suite, s21_sprintf_start_symbol());

  return suite;
}