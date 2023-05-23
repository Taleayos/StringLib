#include "s21_string.h"

int is_white_space(char c);
int get_first_position(char const *str);
int get_last_position(char const *str);
int get_trim_len(char const *str);
char *trim_func(char *src, char *trim_chars);

int is_white_space(char c) { return (c == ' ' || c == '\t' || c == '\n'); }
int get_first_position(char const *str) {
  int i = 0;
  while (is_white_space(str[i])) {
    i += 1;
  }
  return (i);
}

int get_last_position(char const *str) {
  size_t i = s21_strlen(str) - 1;
  while (is_white_space(str[i])) {
    i -= 1;
  }
  return (int)i;
}

int get_trim_len(char const *str) {
  return (get_last_position(str) - get_first_position(str));
}
char *trim_func(char *src, char *trim_chars) {
  char *trim = s21_NULL;
  if (src && trim_chars) {
    char *ptr_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++)
      ;
    for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1));
         end_str--)
      ;
    trim = (char *)calloc((end_str - ptr_str + 1), sizeof(char));
    if (trim) {
      s21_strncpy(trim, ptr_str, end_str - ptr_str);
      *(trim + (end_str - ptr_str)) = '\0';
    }
  }
  return trim;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trim = s21_NULL;
  if (trim_chars != s21_NULL) {
    if (s21_strlen(trim_chars) != 0) {
      trim = trim_func((char *)src, (char *)trim_chars);
    } else {
      int i, len, start;
      if (src != s21_NULL) {
        i = 0;
        len = get_trim_len(src) + 1;
        char *ptr_str = (char *)src;
        char *end_str = (char *)src + s21_strlen(src);
        trim = (char *)calloc((end_str - ptr_str + 1), sizeof(char));
        // trim = (char *)calloc(len, sizeof(char));
        start = get_first_position(src);
        while (i < len) {
          trim[i] = src[start];
          i += 1;
          start += 1;
        }
        if (i == 0) return "\0";
        trim[i] = '\0';
      }
    }
  } else {
    int i, len, start;
    if (src != s21_NULL) {
      i = 0;
      len = get_trim_len(src) + 1;
      char *ptr_str = (char *)src;
      char *end_str = (char *)src + s21_strlen(src);
      trim = (char *)calloc((end_str - ptr_str + 1), sizeof(char));
      //      trim = (char *)calloc(len, sizeof(char));
      start = get_first_position(src);
      while (i < len) {
        trim[i] = src[start];
        i += 1;
        start += 1;
      }
      if (i == 0) return "\0";
      trim[i] = '\0';
    }
  }
  return (trim);
}
