#include "test_string.h"

START_TEST(strncpy_1) {
  char src[50] = "Happy New Year!";
  char dest[50] = "The strcpy() function copies the string";
  size_t n = 4;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  char src[50] = "Happy New Year!";
  char dest[50] = "123456789";
  size_t n = 8;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_3) {
  char src[50] = "Happy New Year!";
  char dest[50] = "\0";
  size_t n = 1;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_4) {
  char src[50] = "\0";
  char dest[50] = "Happy New Year!";
  size_t n = 10;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_5) {
  char src[50] = "\nqwerty";
  char dest[50] = "The strcpy() function copies the string";
  size_t n = 4;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_6) {
  char src[50] = "Happy New Year!";
  char dest[50] = "\nqwerty";
  size_t n = 4;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_7) {
  char src[50] = "\0";
  char dest[50] = "\0";
  size_t n = 0;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_8) {
  char src[50] = "  school21";
  char dest[50] = "The strcpy() function copies the string";
  size_t n = 5;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_9) {
  char src[50] = "01/01/2023";
  char dest[50] = "12345";
  size_t n = 10;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_10) {
  char src[50] = " ";
  char dest[50] = " ";
  size_t n = 1;
  ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("s21_strncpy");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);
  tcase_add_test(tc, strncpy_8);
  tcase_add_test(tc, strncpy_9);
  tcase_add_test(tc, strncpy_10);

  suite_add_tcase(s, tc);
  return s;
}
