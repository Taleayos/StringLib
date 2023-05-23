#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str. strchr ожидает, что первый
// параметр оканчивается нулем и, следовательно, не требует параметра длины.
// memchr работает аналогично, но не ожидает, что блок памяти завершается нулем,
// поэтому вы можете искать \0 персонаж успешно.

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *buf = (unsigned char *)str;
  unsigned char *res = s21_NULL;
  while ((str != s21_NULL) && (n--)) {
    if (*buf != (unsigned char)c) {
      buf++;
    } else {
      res = buf;
      break;
    }
  }
  return res;
}
