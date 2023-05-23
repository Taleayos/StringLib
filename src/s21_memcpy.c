#include "s21_string.h"

//Копирует n символов из src в dest. (копирует байтами, а не просто копирует
//строку, поэтому нет конечной метки «\ 0» (она не остановится при обнаружении
//«/ 0»),
// и она копируется, как указано в байтах)
//Функция memcpy предполагает, что в копируемой области памяти нет перекрытия
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n; i++)
    ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
  return dest;
}
