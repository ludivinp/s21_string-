#include "../includes/s21_convertions.h"

void determining_length_int(long long int *input_data,
                            length_flags length_flags) {
  switch (length_flags.l) {
    case 0:
      *input_data = (int)*input_data;
      break;
    case 1:
      *input_data = (long int)*input_data;
      break;
  }

  switch (length_flags.h) {
    case 1:
      *input_data = (short int)*input_data;
      break;
    case 2:
      *input_data = (char)*input_data;
      break;
  }
}

void determining_length_uint(unsigned long long int *input_data,
                             length_flags length_flags) {
  switch (length_flags.l) {
    case 0:
      *input_data = (unsigned int)*input_data;
      break;
    case 1:
      *input_data = (unsigned long int)*input_data;
      break;
  }

  switch (length_flags.h) {
    case 1:
      *input_data = (unsigned short int)*input_data;
      break;
    case 2:
      *input_data = (unsigned char)*input_data;
      break;
  }
}