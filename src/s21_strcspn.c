#include <stdio.h>

#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  // Простая реализация;

  //    const char *p_str1;
  //    const char *p_str2;
  //    int count = 0;
  //    if (*str2 == '\0') {
  //        count = s21_strlen(str1);
  //    } else {
  //    for (p_str1 = str1; *p_str1 != '\0'; ++p_str1) {
  //        for(p_str2 = str2; *p_str2 != '\0'; ++p_str2) {
  //            if (*p_str1 == *p_str2) {
  //                return count;
  //            }
  //            if (*(p_str2 + 1) == '\0')
  //                count++;
  //        }
  //    }
  //    }
  //    return count;
  //}

  // Реализация через функцию strchr
  int count = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      return count;
    } else {
      str1++;
      count++;
    }
  }
  return count;
}
