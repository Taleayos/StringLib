#include "s21_string.h"

//Еще одна функция для копирования n символов из src в dest
//Области памяти могут перекрываться
//Основное отличие между memmove() и memcpy() в том, что в memmove()
//используется a buffer - временная память, поэтому риска перекрытия нет
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *temp = (char *)calloc(n, sizeof(char));
  s21_memcpy(temp, src, n);
  s21_memcpy(dest, temp, n);
  free(temp);
  return dest;
}
