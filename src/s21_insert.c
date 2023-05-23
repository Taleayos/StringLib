#include "s21_string.h"
//Возвращает новую строку, в которой указанная строка (str) вставлена
//в указанную позицию (start_index) в данной строке (src).
//В случае какой-либо ошибки следует вернуть значение NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  s21_size_t src_len = 0, str_len = 0;
  if (src != s21_NULL) {
    src_len = s21_strlen(src);
  }
  if (str != s21_NULL) {
    str_len = s21_strlen(str);
  }
  if ((src_len < start_index)) {
  } else {
    res = calloc((src_len + str_len) + 1, sizeof(char));
    if (res) {
      for (s21_size_t i = 0; i < (src_len + str_len); i++) {
        if (i < start_index) {
          res[i] = src[i];
        } else if (i < (str_len + start_index)) {
          res[i] = str[i - start_index];
        } else {
          res[i] = src[i - str_len];
        }
      }
    }
  }
  return res;
}
