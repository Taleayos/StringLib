#include <stdio.h>

#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest.

char* s21_strcat(char* dest, const char* src) {
  // делаем так, чтобы `ptr` указывал на конец строки назначения
  char* ptr = dest + s21_strlen(dest);
  // добавляет символы источника к строке назначения
  while (*src != '\0') {
    *ptr++ = *src++;
  }
  // нулевая завершающая строка назначения
  *ptr = '\0';
  // пункт назначения возвращается стандартной функцией `strcat()`
  return dest;
}

// Альтернативная реализация

// char* adress = dest;
// if (s21_strlen(dest) != 0) {
//     dest += s21_strlen(dest);
// }
// while (*src != '\0') {
//     *dest = *src;
//     dest++;
//     src++;
// }
//
// return adress;
// }
