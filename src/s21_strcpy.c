#include "s21_string.h"

//Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
  char *res = dest;
  while ((*dest++ = *src++) != '\0') continue;
  return res;
}