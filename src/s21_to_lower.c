#include "s21_string.h"

//Возвращает копию строки (str), преобразованной в нижний регистр.
//В случае какой-либо ошибки следует вернуть значение NULL
void *s21_to_lower(const char *str) {
  int i = 0;
  char *dest = calloc(s21_strlen(str) + 1, sizeof(char));
  if (!dest) return s21_NULL;
  while (str[i]) {
    if (str[i] >= 65 && str[i] <= 90) {
      dest[i] = str[i] + 32;
      i++;
    } else {
      dest[i] = str[i];
      i++;
    }
  }
  return dest;
}