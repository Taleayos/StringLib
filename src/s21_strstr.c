#include "s21_string.h"

// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack. Возвращает указатель на первое
// вхождение подстроки. Выводит всю строку с начала совпадения. Если совпадение
// не обнаружено, возвращается нулевой указатель (null).

char *s21_strstr(const char *haystack, const char *needle) {
  const char *str1 = haystack, *str2 = needle;
  for (;;) {
    if (!*str2) return (char *)haystack;
    if (!*str1) return NULL;
    if (*str1++ != *str2++) {
      str1 = ++haystack;
      str2 = needle;
    }
  }
}
