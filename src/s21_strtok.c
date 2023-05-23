#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *sn;  // начало лексемы
  static char *sk;  // конец исходной строки
  // обработать (поломать) всю исходную строку
  if (str != s21_NULL) {
    sn = str;  // начало самой первой лексемы
    // заменить все разделители на '\0' во всей строке
    for (; *str; str++) {
      for (int i = 0; *(delim + i); i++)
        if (*str == *(delim + i)) {
          *str = '\0';
          break;
        }
    }
    sk = str;  // запомнить конец исходной строки
  }
  // проскочить все '\0' в начале лексемы
  for (; (*sn == '\0') && (sn != sk); sn++) {
  }
  char *s = sn;  // запомнить "ненулевое" начало лексемы
  // найти "нулевое" начало следующей лексемы
  for (; (*sn != '\0') && (sn != sk); sn++) {
  }
  return (*s == '\0' ? s21_NULL : s);
}
