#include "../includes/s21_strerror.h"

#include "../s21_string.h"

char *s21_strerror(int errnum) {
  static char buffer[180];
  if ((errnum > 0) && (errnum <= s21_number_of_error)) {
    s21_strncpy(buffer, s21_errors[errnum], 180);
  } else {
#if defined(__APPLE__) && defined(__MACH__)
    s21_sprintf(buffer, "Unknown error: %d", errnum);
#elif defined(__linux__)
    s21_sprintf(buffer, "Unknown error %d", errnum);
#endif
  }
  return buffer;
}
