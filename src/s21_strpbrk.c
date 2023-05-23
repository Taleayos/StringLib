#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2. Возвращает всю строку, начиная с первого совпадения.

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *scanp;
  int c, sc;

  while ((c = *str1++) != 0) {
    for (scanp = str2; (sc = *scanp++) != '\0';)
      if (sc == c) return ((char *)(str1 - 1));
  }
  return (s21_NULL);
}
