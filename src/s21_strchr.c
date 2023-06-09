#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str. Возвращает указатель на местонахождение
// первого совпадения с символом или NULL, если символ не найден.

char* s21_strchr(const char* str, int c) {
  while (*str != c && *str != '\0') {
    str++;
  }
  if (*str == c) {
    return (char*)str;
  } else {
    return s21_NULL;
  }
}
