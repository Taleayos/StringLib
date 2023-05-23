#include "s21_string.h"
// cравнивает по байтно n первых символов из строк str1 с str2, и возвращает
// значение больше 0 если s1 больше, значение меньше 0 если s1 меньше и 0 если
// s1 и s2 совпадают. Функция учитывает регистр символов.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  if (n > s21_strlen(str1)) {
    n = s21_strlen(str1) + 1;
  }
  while (n > 0) {
    if (*str1 == *str2) {
      str1++;
      str2++;
      n--;
    } else {
      res = *(const unsigned char *)str1 - *(const unsigned char *)str2;
      break;
    }
  }
  return res;
}
