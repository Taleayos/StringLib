#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2.

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  unsigned char *buff1 = s21_NULL;
  unsigned char *buff2 = s21_NULL;
  buff1 = (unsigned char *)str1;
  buff2 = (unsigned char *)str2;
  s21_size_t i = 0;
  while (i < n) {
    if (buff1[i] != buff2[i]) {
      res = buff1[i] - buff2[i];
      break;
    }
    i++;
  }
  return res;
}
