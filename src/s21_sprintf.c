#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

typedef struct {  // спецификация преобразования
  // ФЛАГИ
  int M;  // "-" - выравнивает вывод по лев. краю (если нет фл. "0" для чисел)
  int P;  // "+" - выводит +/- перед положит./отриц. знач-ми чисел со знаком
  int S;  // " " - выводит пробел перед положит. значением, если нет флага "+"
  int L;  // "#" - выводит 0, 0x, 0X - при oxX (для ненулевых значений);
          // вынуждаeт печатать десят. "." при eEf, даже если после неё
          // нет десятичных знаков;
          // отменяет подавление нулей дробн. части при gG
  int Z;  // "0" - дополняет числа нулями (вместо пробелов) до заданной ширины
          // (для целых чисел, если указана ширина, нет точности и флага "-")
  int W;  // признак наличия ширины в спецификации
  int A;  // признак наличия точности в спецификации
  // ШИРИНА и ТОЧНОСТЬ
  int width;  // ширина поля - минимальное количество печатаемых символов;
              // eсли значение короче, результат дополняется пробелами;
              // не усекается, если результат длиннее;
              // отрицательное значение - выравнивание по левому краю
  int accuracy;  // точность представления - не может быть отрицательной!
                 // миним. кол-во цифр для целых чисел diuoxXp (по умолч. 1);
                 // eсли значение короче, результат дополняется нулями;
                 // не усекается, если результат длиннее;
                 // 0 значит, что для целого 0 не записывается ни одного симв.;
                 // кол-во цифр после десят. точки для eEf (по умолчанию 6);
                 // максим. кол-во значащих цифр для gG (по умолчанию 6);
                 // максим. кол-во символов в строке для s (по умолч. до "\0");
                 // для спецификатора "с" никак не влияет
  // МОДИФИКАТОР длины
  char modifier;
  /*
    h - целое типа short для idouxXn;
        вещественное число типа float для eEfgG (?)
    l - целое типа long для idouxXn;
        вещественное число типа double для eEfgG (?);
        широкий символ или строка широких символов для c и s
    L - вещественное число типа long double для eEfgG
  */
  // СПЕЦИФИКАТОР преобразования
  char specifier;
  /*
    d - выводит десятичное целое со знаком
    i - выводит десятичное целое со знаком
    u - выводит десятичное целое без знака
    o - выводит восьмеричное целое без знака
    x - выводит шестнадцатиричное целое без знака, 0-9, a-f
    X - выводит шестнадцатиричное целое без знака, 0-9, A-F
    f - выводит значение с плавающей точкой
    e - выводит значение с плавающей точкой в эксп. нотации (e)
    E - выводит значение с плавающей точкой в эксп. нотации (E)
    g - выводит значение с плав. тчк. либо как f, либо как e без нулей в конце
    G - выводит значение с плав. тчк. либо как f, либо как E без нулей в конце
    c - выводит символ
    s - выводит строку
    p - выводит указатель
    n - сохраняет число символов, выведенных sprintf
    % - выводит знак процента (флаги, модиф-ры, ширина и точность не влияют)
  */
} Conv_spec;

// Функция выводит на экран параметры спецификации (нужна для отладки)
int *print_specification(Conv_spec *cs);

// Функция парсит параметры спецификации из форматной строки и возвращает
// NULL или указатель на символ форматной строки после спецификации
const char *get_specification(const char *format, Conv_spec *cs, va_list *args);

// Функция получает и преобразовывает АРГУМЕНТ в строку символов str
// согласно спецификации cs и возвращает указатель на str
char *arg_to_str(va_list *args, char *str, Conv_spec *cs);

// Функция сохраняет в аргументе-указателе число символов, выведенных
// в строку str до специф-ра 'n' из спецификации cs, и возвращает это кол-во
s21_size_t len_to_arg(va_list *args, char *str, Conv_spec *cs);

// Функция получает и преобразовывает целый аргумент в строку символов str
// согласно спецификации cs и возвращает указатель на str
char *int_to_str(va_list *args, char *str, Conv_spec *cs);

// Функция получает и преобразовывает адресный аргумент в строку символов str
// согласно спецификации cs и возвращает указатель на str
char *ptr_to_str(va_list *args, char *str, Conv_spec *cs);

// Функция получает и преобразовывает вещественный аргумент в строку
// символов str согласно спецификации cs и возвращает указатель на str
char *flt_to_str(va_list *args, char *str, Conv_spec *cs);

// Функция получает и преобразовывает строковый аргумент в строку
// символов str согласно спецификации cs и возвращает указатель на str
char *str_to_str(va_list *args, char *str, Conv_spec *cs);

// Функция получает и преобразовывает символьный аргумент в строку
// символов str согласно спецификации cs и возвращает указатель на str
char *chr_to_str(va_list *args, char *str, Conv_spec *cs);

// Функция преобразует целое значение value в строку символов str
// в системе счисления radix. Возвращает указатель на строку str
char *s21_itoa(long long value, char *str, int radix);

// Функция преобразует модуль веществ-го значения value в строку символов str
// с точностью accuracy после точки. Возвращает указатель на строку str
// При f = 1 точность - кол-во знач-х цифр; при f = 0 - кол-во цифр после точки
char *s21_ftoa(long double value, char *str, s21_size_t accuracy, int f);

// Функция возвращает число - результат преобразование строки в целое число;
// если в начале строки содержится не цифра, то возвращается ноль
int s21_atoi(char *str);

// Функция вставляет n раз символ ch в начало (f=0) или конец (f=1) строки str
char *strchrncat(char *str, char ch, int n, int f);

// Функция отправляет форматированный вывод в строку, на которую указывает str
int s21_sprintf(char *str, const char *format, ...) {
  setlocale(LC_ALL, "");
  //  setlocale(LC_ALL, "en_US.UTF-8");
  va_list args;
  va_start(args, format);
  str[0] = '\0';
  while (format) {
    // найти и скопировать часть форматной строки до начала спецификации
    int n = s21_strcspn(format, "%");
    s21_strncat(str, format, n);  // '\0' добавляется автоматичеки в конец
    format += n;  // переместить указатель на признак начала спецификации "%"
    if (*format == '%') format++;  // переместить указатель на символ после "%"

    Conv_spec cs = {0};  // обнулить параметры спецификации по умолчанию
    format = get_specification(format, &cs, &args);
    if (format) {
      // вывести параметры спецификации (для отладки)
      // print_specification(&cs);
      //  получить и отформатировать аргумент согласно спецификации
      arg_to_str(&args, str + s21_strlen(str), &cs);
      // сохранить в аргументе количество выведенных символов
      if (cs.specifier == 'n') len_to_arg(&args, str, &cs);
    }
  }
  va_end(args);
  return s21_strlen(str);
}  // конец s21_sprintf

// получение (парсинг) параметров спецификации
const char *get_specification(const char *format, Conv_spec *cs,
                              va_list *args) {
  // найти спецификатор
  const char *pSpec = s21_strpbrk(format, "diuoxXfeEgGcspn%");
  if (!pSpec) return NULL;  // вернуть NULL, если спецификатор не найден
  // если найден спецификатор, определить другие параметры спецификции
  char *p;  // указатель на символ в форматной строке
  // определить наличие ФЛАГОВ в спецификации
  cs->M = ((p = s21_strchr(format, '-')) && p < pSpec);  // флаг "-"
  cs->P = ((p = s21_strchr(format, '+')) && p < pSpec);  // флаг "+"
  cs->S = ((p = s21_strchr(format, ' ')) && p < pSpec);  // флаг " "
  cs->L = ((p = s21_strchr(format, '#')) && p < pSpec);  // флаг "#"
  // определить наличие МОДИФИКАТОРОВ длины в спецификации
  if ((p = s21_strchr(format, 'h')) && p < pSpec) cs->modifier = 'h';
  if ((p = s21_strchr(format, 'l')) && p < pSpec) cs->modifier = 'l';
  if ((p = s21_strchr(format, 'L')) && p < pSpec) cs->modifier = 'L';
  // записать значение СПЕЦИФИКАТОРА из найденных спецификаторов
  cs->specifier = *pSpec;  // спецификатор из "diuoxXfeEgGcspn%"
  // определить значение ТОЧНОСТИ представления по умолчанию
  if (s21_strchr("diuoxXp", cs->specifier)) cs->accuracy = 1;
  if (s21_strchr("feEgG", cs->specifier)) cs->accuracy = 6;
  if (s21_strchr("s", cs->specifier)) cs->accuracy = INT_MAX;
  // определить наличие точки, звездочки и цифр в спецификации
  char *dot = ((dot = s21_strchr(format, '.')) && dot < pSpec ? dot : NULL);
  char *asterisk =
      ((asterisk = s21_strchr(format, '*')) && asterisk < pSpec ? asterisk
                                                                : NULL);
  char *digit =
      ((digit = s21_strpbrk(format, "123456789")) && digit < pSpec ? digit
                                                                   : NULL);
  // определить наличие ФЛАГА "0" в спецификации
  if (!dot)
    cs->Z = ((p = s21_strchr(format, '0')) && (digit ? p < digit : p < pSpec));
  else
    cs->Z = ((p = s21_strchr(format, '0')) &&
             (digit ? (p < digit) && (p < dot) : p < dot));
  // определить наличие и вычислить ШИРИНУ поля и ТОЧНОСТЬ представления
  // когда только ширина в спецификации (приоритет "звездочке")
  if (!dot && (asterisk || digit)) {
    cs->width = (asterisk ? va_arg(*args, int) : s21_atoi(digit));
    cs->W = 1;  // признак наличия ширины в спецификации
  }
  if (dot) cs->W = cs->A = 1;  // признак наличия ширины и точности в спец-ции
  // когда есть только точка, но явно не указана ни ширина, ни точность
  if (dot && !asterisk && !digit) cs->accuracy = 0;
  // когда есть и ширина, и, возможно, точность в спецификации
  if (dot && (asterisk || digit)) {
    // вычислить ширину - приоритет "звездочке"
    if (asterisk && asterisk < dot)
      cs->width = va_arg(*args, int);
    else if (digit && digit < dot)
      cs->width = s21_atoi(digit);
    // искать признак наличия точности ("*" и цифры) после точки
    asterisk = ((asterisk = s21_strchr(dot, '*')) && asterisk < pSpec ? asterisk
                                                                      : NULL);
    digit = ((digit = s21_strpbrk(dot, "0123456789")) && digit < pSpec ? digit
                                                                       : NULL);
    // вычислить точность - приоритет "звездочке"
    if (asterisk || digit)
      cs->accuracy = (asterisk ? va_arg(*args, int) : s21_atoi(digit));
    if (!asterisk && !digit)
      cs->accuracy = 0;  // обнулить точность, если после точки нет "*" и цифр
  }
  /*  для Windows
  // вычислить точность по умолчанию для спецификатора "p"
  if (s21_strchr("p", cs->specifier) && !cs->M && !cs->P && !cs->S && !cs->L &&
      !cs->Z && !cs->W && !cs->A)
    cs->accuracy = 16;
  */
  // выравнивать по левому краю, если ширина поля отрицательна
  if (cs->width < 0) cs->M = 1;  // флаг "-"
  cs->width = abs(cs->width);
  // вернуть указатель на хвост форматной строки после спецификации
  return ++pSpec;
}  // конец get_specification

// получение и преобразование аргумента в строку символов str согласно
// спецификации cs
char *arg_to_str(va_list *args, char *str, Conv_spec *cs) {
  // добавление целого аргумента в строку
  if (s21_strchr("diuoxX", cs->specifier)) int_to_str(args, str, cs);
  // добавление адресного аргумента в строку
  if (s21_strchr("p", cs->specifier)) ptr_to_str(args, str, cs);
  // добавление вещественного аргумента в строку
  if (s21_strchr("feEgG", cs->specifier)) flt_to_str(args, str, cs);
  // добавление строкового аргумента в строку
  if (s21_strchr("s", cs->specifier)) str_to_str(args, str, cs);
  // добавление символьного аргумента в строку
  if (s21_strchr("c", cs->specifier)) chr_to_str(args, str, cs);
  // добавление "%" в строку
  if (s21_strchr("%", cs->specifier)) s21_strcat(str, "%");
  return str;
}  // конец arg_to_str

// сохранение в аргументе-указателе числа символов, выведенных
// в строку str до спецификатора 'n' из спецификации cs
s21_size_t len_to_arg(va_list *args, char *str, Conv_spec *cs) {
  // получить адрес аргумента и передать ему количество обработанных символов
  if (cs->modifier == 0) {
    int *pArg = va_arg(*args, int *);
    *pArg = (int)s21_strlen(str);
  }
  if (cs->modifier == 'h') {
    short *pArg = va_arg(*args, short *);
    *pArg = (short)s21_strlen(str);
  }
  if (cs->modifier == 'l') {
    long *pArg = va_arg(*args, long *);
    *pArg = (long)s21_strlen(str);
  }
  return s21_strlen(str);
}  // len_to_arg

// получение и преобразование целого аргумента в строку символов str согласно
// спецификации cs
char *int_to_str(va_list *args, char *str, Conv_spec *cs) {
  long long arg = 0;  // значение целого аргумента
  if (s21_strchr("di", cs->specifier)) {
    if (cs->modifier == 0) arg = (int)va_arg(*args, int);
    if (cs->modifier == 'h') arg = (short)va_arg(*args, int);
    if (cs->modifier == 'l') arg = (long)va_arg(*args, long);
  }
  if (s21_strchr("uoxX", cs->specifier)) {
    if (cs->modifier == 0) arg = (unsigned int)va_arg(*args, unsigned int);
    if (cs->modifier == 'h') arg = (unsigned short)va_arg(*args, unsigned int);
    if (cs->modifier == 'l') arg = (unsigned long)va_arg(*args, unsigned long);
  }
  // преобразовать модуль целого числа в строку в своей системе счисления
  s21_itoa(
      arg, str,
      s21_strchr("xX", cs->specifier) ? 16 : (cs->specifier == 'o' ? 8 : 10));
  // при нулевой точности для нуля не записывается ни одного символа
  if (arg == 0 && cs->accuracy == 0) str[0] = '\0';
  // привести строковое представление 16-го числа к верх. регистру
  if (s21_strchr("X", cs->specifier))
    for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
  // buffer = to_upper(buffer);
  // дополнить число слева нулями, если число меньше точности
  strchrncat(str, '0', cs->accuracy - s21_strlen(str), 0);
  // вывести префикс 0x, 0X перед 16-м числом (для ненулевых значений)
  int k = 0;  // количество знаков в итоговом префиксе 0x, 0X, +/-, ' '
  if (cs->L && s21_strchr("xX", cs->specifier) && arg != 0) {
    strchrncat(str, cs->specifier, 1, 0);
    strchrncat(str, '0', (k += 2, 1), 0);
  }
  // добавить префикс 0 перед 8-м числом (для ненулевых значений)
  if (cs->L && s21_strchr("o", cs->specifier) && arg != 0 && (*str != '0'))
    strchrncat(str, '0', 1, 0);
  // вывести "+", " " или "-" перед положит. или отриц. значениями
  if (arg < 0) strchrncat(str, '-', (++k, 1), 0);
  if (cs->P && arg >= 0 && s21_strchr("di", cs->specifier))
    strchrncat(str, '+', (++k, 1), 0);
  if (cs->S && !cs->P && arg >= 0 && s21_strchr("di", cs->specifier))
    strchrncat(str, ' ', (++k, 1), 0);
  // дополнить пробелами или нулями (вместо пробелов) до заданной ширины
  // и выровнять вывод по левому или правому краю
  char ch = (cs->Z && !cs->M && cs->W && !cs->A ? '0' : ' ');
  strchrncat(str + (ch == '0' ? k : 0), ch, cs->width - s21_strlen(str), cs->M);
  return str;
}  // конец int_to_str

// получение и преобразование адресного аргумента в строку символов str
// согласно спецификации cs
char *ptr_to_str(va_list *args, char *str, Conv_spec *cs) {
  void *arg = va_arg(*args, void *);  // значение адресного аргумента
  // преобразовать адресный аргумент в строку в 16-й системе счисления
  s21_itoa((long long)arg, str, 16);
  // при нулевой точности для нуля не записывается ни одного символа
  if (arg == 0 && cs->accuracy == 0) str[0] = '\0';
  // дополнить число слева нулями, если число меньше точности
  strchrncat(str, '0', cs->accuracy - s21_strlen(str), 0);
  // вывести префикс 0x перед адресом (для ненулевых значений)
  int k = 0;  // количество знаков в префиксе 0x
  // if (cs->L && arg != 0) {  // для Windows
  strchrncat(str, 'x', 1, 0);
  strchrncat(str, '0', (k += 2, 1), 0);
  // }  // для Windows
  // дополнить пробелами или нулями (вместо пробелов) до заданной ширины
  // и выровнять вывод по левому или правому краю
  char ch = (cs->Z && !cs->M && cs->W && !cs->A ? '0' : ' ');
  strchrncat(str + (ch == '0' ? k : 0), ch, cs->width - s21_strlen(str), cs->M);
  return str;
}  // конец ptr_to_str

// получение и преобразование вещественного аргумента в строку
// символов str согласно спецификации cs
char *flt_to_str(va_list *args, char *str, Conv_spec *cs) {
  long double arg = 0;  // значение вещественного аргумента
  if (cs->modifier == 0) arg = (double)va_arg(*args, double);
  if (cs->modifier == 'h') arg = (float)va_arg(*args, double);
  if (cs->modifier == 'l') arg = (double)va_arg(*args, double);
  if (cs->modifier == 'L') arg = (long double)va_arg(*args, long double);
  long double mantissa = arg;  // значение мантиссы аргумента
  int n = 0;  // порядок степени аргумента в экспоненциальной нотации
  // вычислить мантиссу и порядок степени аргумента
  if (s21_strchr("eEgG", cs->specifier)) {
    while (fabsl(mantissa) >= 10) {
      mantissa /= 10;
      n++;
    }
    while (0 < fabsl(mantissa) && fabsl(mantissa) < 1) {
      mantissa *= 10;
      n--;
    }
  }
  int f_exp = (n < -4 || n >= cs->accuracy);  // признак эксп. нотации для "gG"
  if (0 == arg || (1 <= arg && arg <= 9)) f_exp = 0;
  // преобразовать модуль вещественного числа или мантиссы аргумента в строку
  if (s21_strchr("f", cs->specifier)) s21_ftoa(arg, str, cs->accuracy, 0);
  if (s21_strchr("eE", cs->specifier)) s21_ftoa(mantissa, str, cs->accuracy, 0);
  if (s21_strchr("gG", cs->specifier))
    s21_ftoa(f_exp ? mantissa : arg, str, cs->accuracy, 1);
  // подавить вывод нулей и точки в конце дробной части для "gG"
  if (s21_strchr("gG", cs->specifier) && !cs->L) {
    char *dot = s21_strchr(str, '.');
    for (char *p;
         dot && (p = s21_strrchr(dot, '0')) && !s21_strpbrk(p, "123456789");)
      *p = '\0';
    if (dot && !s21_strpbrk(dot, "0123456789")) *dot = '\0';
  }
  int k = 0;  // количество знаков в итоговом префиксе +/-, ' '
  // вывести "+", " " или "-" перед положит. или отриц. значениями
  if (arg < 0) strchrncat(str, '-', (++k, 1), 0);
  if (cs->P && arg >= 0) strchrncat(str, '+', (++k, 1), 0);
  if (cs->S && !cs->P && arg >= 0) strchrncat(str, ' ', (++k, 1), 0);
  // добавить "." при нулевой точности
  if (cs->L && cs->accuracy == 0) s21_strcat(str, ".");
  // добавить суффикс эксп. нотации
  if (s21_strchr("eE", cs->specifier) ||
      (s21_strchr("gG", cs->specifier) && f_exp)) {
    strchrncat(str, (isupper(cs->specifier) ? 'E' : 'e'), 1, 1);
    strchrncat(str, (n >= 0 ? '+' : '-'), 1, 1);
    strchrncat(str, '0', abs(n) < 9, 1);
    s21_itoa(n, str + s21_strlen(str), 10);
  }
  // дополнить пробелами или нулями (вместо пробелов) до заданной ширины
  // и выровнять вывод по левому или правому краю
  char ch = (cs->Z && !cs->M ? '0' : ' ');
  strchrncat(str + (ch == '0' ? k : 0), ch, cs->width - s21_strlen(str), cs->M);
  return str;
}  // конец flt_to_str

// получение и преобразование строкового аргумента в строку
// символов str согласно спецификации cs
char *str_to_str(va_list *args, char *str, Conv_spec *cs) {
  // строковое значение аргумента ограничить точностью
  if (cs->modifier == 0) s21_strncat(str, va_arg(*args, char *), cs->accuracy);
  // широкую строку аргумента преобразовать в многобайтовую строку
  // и ограничить ее точностью
  if (cs->modifier == 'l') {
    wchar_t *pwcs = va_arg(*args, wchar_t *);
    int n = wcstombs(str, pwcs, wcslen(pwcs) * MB_CUR_MAX);
    if (cs->accuracy < n) n = cs->accuracy;
    str[n] = '\0';
  }
  // дополнить пробелами до заданной ширины
  // и выровнять вывод по левому или правому краю
  strchrncat(str, ' ', cs->width - s21_strlen(str), cs->M);
  return str;
}  // конец str_to_str

// получение и преобразование символьного аргумента в строку
// символов str согласно спецификации cs
char *chr_to_str(va_list *args, char *str, Conv_spec *cs) {
  // если нужно преобразовать простой символ, то в строку записать код символа
  if (cs->modifier == 0) {
    str[0] = va_arg(*args, int);
    str[1] = '\0';
  }
  // если нужно преобразовать широкий символ, то сформировать
  // и записать в строку его многобайтовую последовательность
  if (cs->modifier == 'l') {
    wchar_t wc = va_arg(*args, wchar_t);
    int n = wctomb(str, wc);  // длина в байтах многобайт. последовательности
    str[n] = '\0';
  }
  // дополнить пробелами до заданной ширины
  // и выровнять вывод по левому или правому краю
  strchrncat(str, ' ', cs->width - s21_strlen(str), cs->M);
  return str;
}  // конец chr_to_str

// преобразование целого значения value в строку символов str
// в системе счисления по основанию radix (8, 10, 16)
char *s21_itoa(long long value, char *str, int radix) {
  char *buffer = str;
  value = llabs(value);  // преобразовывать в положительное число
  do {  // вычленить и заменить цифру на соответствующую букву в своей
        // системе счисления ('0'=48 ... '9'=57, 'a'=97 ... 'f'=102)
    *buffer = value % radix + (value % radix < 10 ? 48 : 87);
    ++buffer;
    value /= radix;
  } while (value != 0);
  *buffer = '\0';
  --buffer;
  // перевернуть строку
  for (int i = 0; (str + i) < (buffer - i); i++) {
    char temp = *(str + i);
    *(str + i) = *(buffer - i);
    *(buffer - i) = temp;
  }
  return str;
}  // конец s21_itoa

// преобразование модуля вещественного значения value в строку символов str;
// при f = 1 точность - кол-во знач-х цифр; при f = 0 - кол-во цифр после точки
char *s21_ftoa(long double value, char *str, s21_size_t accuracy, int f) {
  char *p;  // указатель на начало дробной части
  char *digit;  // указатель на первую ненулевую цифру в строк. предст-ии числа
  s21_size_t n = (f ? 0 : accuracy);  // количество цифр после точки
  value = fabsl(value);
  do {
    long double a, b;  // целая и дробная части числа
    // округлить число до n знаков после точки и выделить дробн. и цел. части
    b = modfl(roundl(value * pow(10, n)) / pow(10, n), &a);
    s21_itoa(llroundl(a), str, 10);  // преобразовать в строку целую часть
    p = str + s21_strlen(str);  // найти начало дробной части в строке
    // преобразовать в строку дробную часть
    if (n > 0) s21_itoa(llroundl(b * pow(10, n)), p, 10);
    // добавить в дробную часть недостающие нули
    strchrncat(p, '0', n++ - s21_strlen(p), 0);
    if (f && value == 0 && n == accuracy) break;
    digit = s21_strpbrk(str, "123456789");
    // округлять число до количества значащих цифр
  } while (f && (!digit || s21_strlen(digit) < accuracy));
  // вставить точку перед дробной частью
  strchrncat(p, '.', (--n > 0), 0);
  return str;
}  // конец s21_ftoa

// преобразование строки в целое число; возвращается ноль,
// eсли в начале строки стоит символ, не являющейся цифрой
int s21_atoi(char *str) {
  int sum = 0;
  s21_size_t n = s21_strspn(str, "1234567890");  // количество цифр в числе
  for (s21_size_t i = 0; i < n; i++) sum += (str[n - i - 1] - 48) * pow(10, i);
  return sum;
}  // конец s21_atoi

// вставка n раз символа ch в начало (f = 0) или конец (f = 1) строки str
char *strchrncat(char *str, char ch, int n, int f) {
  if (n <= 0) return str;
  s21_size_t m = s21_strlen(str);
  if (f) {  // дублировать символ ch в конец строки n раз
    s21_memset(str + m, ch, n);
    str[m + n] = '\0';
  } else {  // дублировать символ ch в начало строки n раз
    s21_memmove(str + n, str, m + 1);
    s21_memset(str, ch, n);
  }
  return str;
}  // конец strchrncat

/*
// печать параметров спецификации (для отладки)
int *print_specification(Conv_spec *cs) {
  printf("-+S#ZWA=%d%d%d%d%d%d%d\t", cs->M, cs->P, cs->S, cs->L, cs->Z, cs->W,
         cs->A);
  printf("%3d %3d\t", cs->width, cs->accuracy);
  printf("%c\t%c\n", cs->modifier, cs->specifier);
  return 0;
}  // конец print_specification
*/
/*
// ГЛАВНАЯ функция (для отладки)
int main() {
  char str1[4096];
  char str2[4096];

  char *format = "%p";
  int val = 5;

  int n = s21_sprintf(str1, format, &val);
  int m = sprintf(str2, format, &val);

  printf("%d %d\n", n, m);

  puts(str1);
  puts(str2);
  printf("%d\n", strcmp(str1, str2));

  printf("% -f\n", INFINITY);
  return 0;
}
*/
