#ifndef LD_TO_STR_H
#define LD_TO_STR_H

#include <math.h>

#include "../s21_string.h"
#include "s21_sprintf.h"

#define TEN_L 10.0L
#define FIX_PRECISION 0.01L

s21_size_t s21_ld_to_str(long double number, char *str, s21_size_t len,
                         int acc);
void s21_ld_int_to_str(s21_size_t *index, s21_size_t len,
                       long double integr_part, char *str,
                       s21_size_t start_point, s21_size_t *len_inp);
void s21_swap(char *ch1, char *ch2);
void s21_mirrorize_str(char *str, s21_size_t len, s21_size_t start_point,
                       s21_size_t end_point);
int s21_is_nan_or_inf(long double number, char *str,
                      const bool capital_letters);
int s21_is_eq_ch(char ch, const char *str2);

s21_size_t str_to_ll(const char *str, long long int *number);

int s21_count_signed_decimal_digits(long long int decimal_number,
                                    long long int base);

void determining_length_int(long long int *input_data,
                            length_flags length_flags);
void determining_length_uint(unsigned long long int *input_data,
                             length_flags length_flags);

#endif
