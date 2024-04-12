#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include "../s21_string.h"

#define S21_EOF (-1)
#define START_SPECIFIER_SYMBOL '%'

typedef struct specifier_flags_t {
  bool left_alignment;                  // '-'
  bool always_indicates_sign;           // '+'
  bool if_no_sign_then_space;           // ' '
  bool conversion_to_alternative_form;  // '#'
  bool spaces_should_be_zeros;          // '0'
} specifier_flags;

// MAXIMUM of ONE modified variable
// Max values - h = 2, l = 2, L = 1
// Default values = 0;
// hh: char/byte?
// h : short
// l : long / unsigned long
// ll: long long / unsigned long long
// L : long for floats
typedef struct length_flags_t {
  char h;
  char l;
  char L;
} length_flags;

// Default values - flags = false, width = 0, accuracy = -1, length_flags = 0,
// specifier_symbol = 0
typedef struct s21_specifier_info_t {
  specifier_flags flags;

  long long int width;
  long long int accuracy;

  length_flags length_flags;

  char specifier_symbol;
} s21_specifier_info;

int s21_sprintf(char *str, const char *format, ...);

// parser
const char *parse_specifier_info(const char *start_specifier_str,
                                 s21_specifier_info *specifier_info,
                                 va_list *va_list);
const char *parse_specifier_flags(const char *start_specifier_str,
                                  specifier_flags *specifier_flags);
const char *parse_length_flags(const char *start_specifier_str,
                               length_flags *length_flags);

char *s21_inserting_specifier_start_symbol(
    char *str, const s21_specifier_info *specifier_info);
//

// specifiers
char *construct_specifier_str(char *str,
                              const s21_specifier_info *specifier_info,
                              va_list *va_list, const char *str_start);

char *s21_inserting_specifier_c(char *str,
                                const s21_specifier_info *specifier_info,
                                char input_data);
char *s21_inserting_specifier_d(char *str,
                                const s21_specifier_info *specifier_info,
                                long long int input_data);
char *s21_inserting_specifier_e(char *str,
                                const s21_specifier_info *specifier_info,
                                long double input_data);
char *s21_inserting_specifier_f(char *str,
                                const s21_specifier_info *specifier_info,
                                long double input_data);
char *s21_inserting_specifier_g(char *str,
                                const s21_specifier_info *specifier_info,
                                long double input_data);
char *s21_inserting_specifier_o(char *str,
                                const s21_specifier_info *specifier_info,
                                unsigned long long int input_data);
char *s21_inserting_specifier_u(char *str,
                                const s21_specifier_info *specifier_info,
                                unsigned long long int input_data);
char *s21_inserting_specifier_x(char *str,
                                const s21_specifier_info *specifier_info,
                                unsigned long long int input_data);
char *s21_inserting_specifier_s(char *str,
                                const s21_specifier_info *specifier_info,
                                char *input_data);
char *s21_inserting_specifier_p(char *str,
                                const s21_specifier_info *specifier_info,
                                uintptr_t input_data);
char *s21_inserting_specifier_n(char *str, const char *str_start, int *written);
char *s21_inserting_specifier_start_symbol(
    char *str, const s21_specifier_info *specifier_info);

//

// formatting
char *formatting_specifier_str(char *str, s21_size_t str_len,
                               const s21_specifier_info *specifier_info);

void formatting_specifier_width(s21_size_t additional_symbols_count,
                                char **current_str, char **start_str,
                                s21_size_t str_len,
                                const s21_specifier_info *specifier_info);

void formatting_specifier_sign(char **current_str, s21_size_t str_len,
                               const s21_specifier_info *specifier_info);

void formatting_specifier_alternative_form(
    char **current_str, s21_size_t *str_len,
    const s21_specifier_info *specifier_info);
//

#endif