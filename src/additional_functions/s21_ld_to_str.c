#include "../includes/s21_convertions.h"

void s21_swap(char *ch1, char *ch2) {
  if (ch1 == S21_NULL || ch2 == S21_NULL) return;
  char tmp = *ch1;
  *ch1 = *ch2;
  *ch2 = tmp;
}

void s21_mirrorize_str(char *str, s21_size_t len, s21_size_t start_point,
                       s21_size_t end_point) {
  for (s21_size_t j = start_point, i = end_point - 1; j < i && end_point < len;
       j++, i--) {
    s21_swap(str + j, str + i);
  }
}

void s21_ld_int_to_str(s21_size_t *index, s21_size_t len,
                       long double integr_part, char *str,
                       s21_size_t start_point, s21_size_t *len_inp) {
  if (integr_part == 0 && *index < len) {
    str[*index] = '0';
    *index += 1;
    ++(*len_inp);
  }
  for (; *index < len && integr_part > 0.0L; ++(*index)) {
    integr_part /= TEN_L;
    long double new_integr_part = 0.0L;
    long double n_tmp = modfl(integr_part, &new_integr_part);
    n_tmp += FIX_PRECISION;
    n_tmp *= TEN_L;
    str[*index] = (int)n_tmp + 48;
    integr_part = new_integr_part;
    ++(*len_inp);
  }
  s21_mirrorize_str(str, len, start_point, *index);
}

int s21_is_nan_or_inf(long double number, char *str,
                      const bool capital_letters) {
  int written = 0;

  if (isnan(number)) {
    s21_memcpy(str, (capital_letters == true) ? "NAN" : "nan", 3);
    written = 3;
  } else if (isinf(number)) {
    if (number < 0.0) {
      s21_memcpy(str, (capital_letters == true) ? "-INF" : "-inf", 4);
      written = 4;
    } else {
      s21_memcpy(str, (capital_letters == true) ? "INF" : "inf", 3);
      written = 3;
    }
  }

  return written;
}

s21_size_t s21_ld_to_str(long double number, char *str, s21_size_t len,
                         int acc) {
  s21_size_t len_inp = 0;
  if (len == 0 || str == S21_NULL) {
    len_inp = 0;
  } else if ((len_inp = s21_is_nan_or_inf(number, str, false)) == 0) {
    s21_size_t start_point = 0;
    if (number < 0.0L) {
      start_point = 1;
      number *= -1;
      str[0] = '-';
      ++len_inp;
    }
    if (acc == 0) {
      number = roundl(number);
    }
    long double integr_part = 0.0L;
    long double floating_part = modfl(number, &integr_part);
    s21_size_t index = start_point;
    s21_ld_int_to_str(&index, len, integr_part, str, start_point, &len_inp);
    if (acc > 0) {
      str[index] = '.';
      ++len_inp;
      ++index;
      if (acc <= 17) {
        for (int i = 0; i < acc; ++i) {
          floating_part *= TEN_L;
        }
        floating_part = roundl(floating_part);
        s21_size_t fl_ull = floating_part;
        s21_size_t i = index;
        for (; i < len && acc > 0; ++i, acc--) {
          str[i] = (fl_ull % 10) + 48;
          fl_ull /= 10;
          ++len_inp;
        }
        s21_mirrorize_str(str, len, index, i);
      } else {
        for (; index < len && acc > 0; ++index, --acc) {
          floating_part *= TEN_L;
          str[index] = (int)floating_part + 48;
          floating_part -= (int)floating_part;
          ++len_inp;
        }
      }
    }
  }
  return len_inp;
}
