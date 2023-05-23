#include <stdio.h>

#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2. Считает количество совпадений каждого символа str2 в str1.

s21_size_t s21_strspn(const char *str1, const char *str2) {
  const char *p_str1;
  const char *p_str2;
  int count = 0;
  for (p_str1 = str1; *p_str1 != '\0'; ++p_str1) {
    for (p_str2 = str2; *p_str2 != '\0'; ++p_str2) {
      if (*p_str1 == *p_str2) {
        count++;
        break;
      }
    }
    if (*p_str2 == '\0') return count;
  }
  return count;
}
