// #include <stdio.h>
#include "s21_string.h"
// cравнивает по байтно заданную строку str1 с str2, и возвращает значение
// больше 0 если s1 больше, значение меньше 0 если s1 меньше и 0 если s1 и s2
// совпадают. Функция учитывает регистр символов.

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1) {
    if (*str1 != *str2) {
      break;
    }
    str1++;
    str2++;
  }
  return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}
