#include "../includes/s21_sprintf.h"

#include "../includes/s21_convertions.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *current_str = str;

  if (str && format) {
    const char *start_specifier_str = S21_NULL;

    va_list main_va_list;
    va_start(main_va_list, format);
    do {
      start_specifier_str = s21_strchr(format, START_SPECIFIER_SYMBOL);

      if (start_specifier_str) {
        current_str =
            s21_memcpy(current_str, format, start_specifier_str - format);
        current_str = current_str ? current_str + (start_specifier_str - format)
                                  : current_str;

        s21_specifier_info specifier_info = {};
        specifier_info.accuracy = -1;

        // парсим спецификатор
        const char *end_specifier = parse_specifier_info(
            start_specifier_str + 1, &specifier_info, &main_va_list);

        // создание строки со спецификатором
        char *temp_str = construct_specifier_str(current_str, &specifier_info,
                                                 &main_va_list, str);

        if (temp_str) {
          // форматирование строки
          current_str = formatting_specifier_str(
              current_str, temp_str - current_str, &specifier_info);
        } else {
          current_str = s21_memcpy(current_str, start_specifier_str,
                                   end_specifier - start_specifier_str);
          current_str += end_specifier - start_specifier_str;
        }

        format = end_specifier;
      } else {
        current_str = s21_memcpy(current_str, format, s21_strlen(format));
        current_str += s21_strlen(format);
      }

    } while (start_specifier_str);
    va_end(main_va_list);

    current_str[0] = '\0';
  }

  return current_str ? current_str - str : S21_EOF;
}

char *construct_specifier_str(char *str,
                              const s21_specifier_info *specifier_info,
                              va_list *va_list, const char *str_start) {
  char *return_result = S21_NULL;

  switch (specifier_info->specifier_symbol) {
    case 'c':
      return_result =
          s21_inserting_specifier_c(str, specifier_info, va_arg(*va_list, int));
      break;
    case 'd':
    case 'i':
      return_result = s21_inserting_specifier_d(
          str, specifier_info, va_arg(*va_list, long long int));
      break;
    case 'e':
    case 'E':
      if (specifier_info->length_flags.L == 0) {
        return_result = s21_inserting_specifier_e(str, specifier_info,
                                                  va_arg(*va_list, double));
      } else {
        return_result = s21_inserting_specifier_e(
            str, specifier_info, va_arg(*va_list, long double));
      }
      break;
    case 'f':
      if (specifier_info->length_flags.L == 0) {
        return_result = s21_inserting_specifier_f(str, specifier_info,
                                                  va_arg(*va_list, double));
      } else {
        return_result = s21_inserting_specifier_f(
            str, specifier_info, va_arg(*va_list, long double));
      }
      break;
    case 'g':
    case 'G':
      if (specifier_info->length_flags.L == 0) {
        return_result = s21_inserting_specifier_g(str, specifier_info,
                                                  va_arg(*va_list, double));
      } else {
        return_result = s21_inserting_specifier_g(
            str, specifier_info, va_arg(*va_list, long double));
      }
      break;
    case 'o':
      return_result = s21_inserting_specifier_o(
          str, specifier_info, va_arg(*va_list, long long int));
      break;
    case 's':
      return_result = s21_inserting_specifier_s(str, specifier_info,
                                                va_arg(*va_list, char *));
      break;
    case 'u':
      return_result = s21_inserting_specifier_u(
          str, specifier_info, va_arg(*va_list, long long int));
      break;
    case 'x':
    case 'X':
      return_result = s21_inserting_specifier_x(
          str, specifier_info, va_arg(*va_list, long long int));
      break;
    case 'p':
      return_result = s21_inserting_specifier_p(str, specifier_info,
                                                va_arg(*va_list, uintptr_t));
      break;
    case 'n':
      return_result =
          s21_inserting_specifier_n(str, str_start, va_arg(*va_list, int *));
      break;
    case '%':
      return_result = s21_inserting_specifier_start_symbol(str, specifier_info);
      break;
  }

  return return_result;
}

const char *parse_specifier_info(const char *start_specifier_str,
                                 s21_specifier_info *specifier_info,
                                 va_list *va_list) {
  if (start_specifier_str && specifier_info && va_list) {
    {  // flags
      start_specifier_str =
          parse_specifier_flags(start_specifier_str, &specifier_info->flags);
    }

    if (*start_specifier_str == '*') {  // width
      specifier_info->width = va_arg(*va_list, int);
      ++start_specifier_str;
    } else {
      start_specifier_str +=
          str_to_ll(start_specifier_str, &specifier_info->width);
    }

    if (*start_specifier_str == '.') {  // accuracy
      ++start_specifier_str;

      if (*start_specifier_str == '*') {
        specifier_info->accuracy = va_arg(*va_list, int);
        ++start_specifier_str;
      } else {
        start_specifier_str +=
            str_to_ll(start_specifier_str, &specifier_info->accuracy);
      }
    }

    {  // length_flags
      start_specifier_str = parse_length_flags(start_specifier_str,
                                               &specifier_info->length_flags);
    }

    {  // specifier_symbol
      specifier_info->specifier_symbol = *start_specifier_str;
      ++start_specifier_str;
    }
  }

  return start_specifier_str;
}

const char *parse_specifier_flags(const char *start_specifier_str,
                                  specifier_flags *specifier_flags) {
  bool exit_flag = 0;
  while (!exit_flag) {
    switch (*start_specifier_str) {
      case '-':
        specifier_flags->left_alignment = true;
        break;
      case '+':
        specifier_flags->always_indicates_sign = true;
        break;
      case ' ':
        specifier_flags->if_no_sign_then_space = true;
        break;
      case '#':
        specifier_flags->conversion_to_alternative_form = true;
        break;
      case '0':
        specifier_flags->spaces_should_be_zeros = true;
        break;

      default:
        exit_flag = 1;
        break;
    }

    if (!exit_flag) ++start_specifier_str;
  }

  return start_specifier_str;
}

const char *parse_length_flags(const char *start_specifier_str,
                               length_flags *length_flags) {
  bool exit_flag = 0;
  while (!exit_flag) {
    switch (*start_specifier_str) {
      case 'h':
        if (length_flags->h < 2 && !length_flags->l && !length_flags->L) {
          ++length_flags->h;
        } else {
          exit_flag = 1;
        }
        break;
      case 'l':
        if (length_flags->l < 2 && !length_flags->h && !length_flags->L) {
          ++length_flags->l;
        } else {
          exit_flag = 1;
        }
        break;
      case 'L':
        if (!length_flags->h && !length_flags->l && !length_flags->L) {
          ++length_flags->L;
        } else {
          exit_flag = 1;
        }
        break;

      default:
        exit_flag = 1;
        break;
    }

    if (!exit_flag) ++start_specifier_str;
  }

  return start_specifier_str;
}

char *formatting_specifier_str(char *str, s21_size_t str_len,
                               const s21_specifier_info *specifier_info) {
  char *current_str = str;
  if (specifier_info->specifier_symbol != '%' &&
      specifier_info->specifier_symbol != 'n') {
    if (specifier_info->flags.conversion_to_alternative_form) {
      formatting_specifier_alternative_form(&current_str, &str_len,
                                            specifier_info);
    }

    formatting_specifier_sign(&current_str, str_len, specifier_info);

    s21_ssize_t additional_symbols_count =
        specifier_info->width - (current_str - str + str_len);

    if (additional_symbols_count > 0) {
      formatting_specifier_width(additional_symbols_count, &current_str, &str,
                                 str_len, specifier_info);
    }
  }

  return current_str + str_len;
}

void formatting_specifier_alternative_form(
    char **current_str, s21_size_t *str_len,
    const s21_specifier_info *specifier_info) {
  if (specifier_info->specifier_symbol == 'o') {
    if (!(**current_str == '0' && *str_len == 1)) {
      *current_str = s21_memmove(*current_str + 1, *current_str, *str_len);
      s21_memcpy(*current_str - 1, "0", 1);
      (*current_str)[-1] = '0';
    }

  } else if (specifier_info->specifier_symbol == 'x') {
    if (!(**current_str == '0' && *str_len == 1)) {
      *current_str = s21_memmove(*current_str + 2, *current_str, *str_len);
      s21_memcpy(*current_str - 2, "0x", 2);
    }

  } else if (specifier_info->specifier_symbol == 'X') {
    if (!(**current_str == '0' && *str_len == 1)) {
      *current_str = s21_memmove(*current_str + 2, *current_str, *str_len);
      s21_memcpy(*current_str - 2, "0X", 2);
    }

  } else if (specifier_info->specifier_symbol == 'f' &&
             s21_memchr(*current_str, '.', *str_len) == S21_NULL) {
    (*current_str)[*str_len] = '.';
    *str_len += 1;

  } else if ((specifier_info->specifier_symbol == 'e' ||
              specifier_info->specifier_symbol == 'E' ||
              specifier_info->specifier_symbol == 'g' ||
              specifier_info->specifier_symbol == 'G') &&
             s21_memchr(*current_str, '.', *str_len) == S21_NULL) {
    char *desired_symbol_ptr;
    if ((desired_symbol_ptr = s21_memchr(*current_str, 'e', *str_len)) ||
        (desired_symbol_ptr = s21_memchr(*current_str, 'E', *str_len))) {
      s21_memmove(desired_symbol_ptr + 1, desired_symbol_ptr,
                  (*str_len - (desired_symbol_ptr - *current_str)));
      *desired_symbol_ptr = '.';
      *str_len += 1;
    } else if (specifier_info->specifier_symbol == 'g' ||
               specifier_info->specifier_symbol == 'G') {
      (*current_str)[*str_len] = '.';
      *str_len += 1;
    }
  }
}

void formatting_specifier_sign(char **current_str, s21_size_t str_len,
                               const s21_specifier_info *specifier_info) {
  if (*(current_str)[0] != '-') {
    switch (specifier_info->specifier_symbol) {
      case 'd':
      case 'i':
        // case 'o':
      case 'f':
      case 'e':
      case 'E':
      case 'g':
      case 'G':
        if (specifier_info->flags.always_indicates_sign) {
          *current_str = s21_memmove(*current_str + 1, *current_str, str_len);
          (*current_str)[-1] = '+';
        } else if (specifier_info->flags.if_no_sign_then_space) {
          *current_str = s21_memmove(*current_str + 1, *current_str, str_len);
          (*current_str)[-1] = ' ';
        }
        break;
    }
  }
}

void formatting_specifier_width(s21_size_t additional_symbols_count,
                                char **current_str, char **start_str,
                                s21_size_t str_len,
                                const s21_specifier_info *specifier_info) {
  if (specifier_info->flags.left_alignment) {
    s21_memset(*current_str + str_len, ' ', additional_symbols_count);

  } else {
    bool width_input = 0;
    if (specifier_info->flags.spaces_should_be_zeros) {
      switch (specifier_info->specifier_symbol) {
        case 'd':
        case 'i':
          if (specifier_info->accuracy != -1) break;
          __attribute__((fallthrough));
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
        case 'o':
        case 's':
        case 'u':
        case 'x':
        case 'X':
        case 'p':
          if (*(*start_str) == '-' || *(*start_str) == '+') {
            ++(*start_str);
          }

          *start_str =
              s21_memmove(*start_str + additional_symbols_count, *start_str,
                          (current_str - start_str + str_len));
          s21_memset(*start_str - additional_symbols_count, '0',
                     additional_symbols_count);

          width_input = true;
          break;
      }
    }
    if (!width_input) {
      *start_str = s21_memmove(*start_str + additional_symbols_count,
                               *start_str, (current_str - start_str + str_len));
      s21_memset(*start_str - additional_symbols_count, ' ',
                 additional_symbols_count);
    }
  }

  *current_str += additional_symbols_count;
}
