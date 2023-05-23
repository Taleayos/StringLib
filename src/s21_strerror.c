#include "s21_strerror.h"

#include "s21_string.h"

// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.

char* s21_strerror(int errnum) {
  char* error[] = ERR_LIST;
  static char buf[1024];
  char* print_error = s21_NULL;
  char* unknown_error_linux = "Unknown error ";
  char* unknown_error_mac = "Unknown error: ";
  if (STD == 0) {  // s21_strerror.h Ошибки для linux
    if (errnum >= 0 && errnum <= 133) {
      print_error = error[errnum];
    } else {
      s21_sprintf(buf, "%s%d", unknown_error_linux, errnum);
    }
  }
  if (STD == 1) {  // s21_strerror.h Ошибки для mac
    if (errnum >= 0 && errnum <= 106) {
      print_error = error[errnum];
    } else {
      s21_sprintf(buf, "%s%d", unknown_error_mac,
                  errnum);  //!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
  }
  return print_error != s21_NULL ? print_error : buf;
}
