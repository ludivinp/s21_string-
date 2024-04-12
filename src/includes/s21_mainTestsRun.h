#ifndef S21_MAIN_TESTS_RUN_H
#define S21_MAIN_TESTS_RUN_H

#include <check.h>
#include <float.h>
#include <limits.h>

// Тут можно это тесты
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"
#include "s21_convertions.h"

////// Suite getters for all func

// For string.h
Suite *s21_memchr_suite();
Suite *s21_memcmp_suite();
Suite *s21_memcpy_suite();
Suite *s21_memset_suite();
Suite *s21_strcspn_suite();

Suite *s21_strchr_suite();
Suite *s21_strerror_suite();
Suite *s21_strlen_suite();
Suite *s21_strncat_suite();
Suite *s21_strncmp_suite();
Suite *s21_strncpy_suite();
Suite *s21_strpbrk_suite();
Suite *s21_strrchr_suite();
Suite *s21_strstr_suite();
Suite *s21_strtok_suite();

Suite *s21_memmove_suite();
//

// For sprintf
Suite *s21_sprintf_suite();

TCase *s21_sprintf_tcase_default();
TCase *s21_sprintf_tcase_c();
TCase *s21_sprintf_tcase_d();
TCase *s21_sprintf_tcase_i();
TCase *s21_sprintf_tcase_e();
TCase *s21_sprintf_tcase_E();
TCase *s21_sprintf_tcase_f();
TCase *s21_sprintf_tcase_g();
TCase *s21_sprintf_tcase_G();
TCase *s21_sprintf_tcase_o();
TCase *s21_sprintf_tcase_s();
TCase *s21_sprintf_tcase_u();
TCase *s21_sprintf_tcase_x();
TCase *s21_sprintf_tcase_X();
TCase *s21_sprintf_tcase_p();
TCase *s21_sprintf_tcase_n();
TCase *s21_sprintf_start_symbol();
//

// For string.cs
Suite *s21_insert_suite();
Suite *s21_to_lower_suite();
Suite *s21_to_upper_suite();
Suite *s21_trim_suite();
//

// For additional_functions
Suite *s21_ld_to_str_suite();
Suite *s21_is_eq_ch_suite();

//
//////

// Run tests
long long int run_all_tests();
void add_all_suites_in_runner(SRunner **runner);

void add_string_h_suites_in_runner(SRunner **runner);
void add_additional_func_suites_in_runner(SRunner **runner);
void add_string_cs_suites_in_runner(SRunner **runner);

void output_failed_count(size_t failed_count);
//

#endif