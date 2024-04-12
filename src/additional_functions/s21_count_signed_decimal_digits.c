#include "../includes/s21_convertions.h"

int s21_count_signed_decimal_digits(long long int decimal_number,
                                    long long int base) {
  int result = 0;

  do {
    ++result;
    decimal_number /= base;
  } while (decimal_number);

  return result;
}