#include "test_string.h"

START_TEST(trim_1) {
  char src[] = "123Hello world123";
  char trim_chars[] = "123";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Hello world";
  ck_assert_str_eq(my_trim, real);
  free(my_trim);
}
END_TEST

START_TEST(trim_2) {
  char *src = "123Happy 123 New Year123";
  char *trim_chars = "123";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Happy 123 New Year";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_3) {
  char src[] = "     Trim-function      ";
  char trim_chars[] = "123 ";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Trim-function";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_4) {
  char src[] = "\t\n   Trim-function!     \t\n";
  char trim_chars[] = " \t\n!";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Trim-function";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_5) {
  char src[] = "12321";
  char trim_chars[] = "123";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_6) {
  char src[] = "    Hello world!    ";
  char trim_chars[] = "";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Hello world!";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_7) {
  char src[] = "    \t\nHello world!\t\n    ";
  char trim_chars[] = "";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Hello world!";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_8) {
  char src[] = "    \t\n\t\n    ";
  char *trim_chars = "";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "";
  ck_assert_str_eq(my_trim, real);
  //  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_9) {
  char src[] = "    \t\nHello world!\t\n    ";
  char *trim_chars = NULL;
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Hello world!";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_10) {
  char src[] = "    \t\nHello world!";
  char *trim_chars = NULL;
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "Hello world!";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_11) {
  char src[] = "    \t\n\t\n    ";
  char *trim_chars = NULL;
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "";
  ck_assert_str_eq(my_trim, real);
  //  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_12) {
  char src[] = "";
  char *trim_chars = NULL;
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "";
  ck_assert_str_eq(my_trim, real);
  //  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_13) {
  char *src = s21_NULL;
  char *trim_chars = "1234567890";
  char *my_trim = s21_trim(src, trim_chars);
  char *real = s21_NULL;
  ck_assert_ptr_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_14) {
  char *src = s21_NULL;
  char trim_chars[] = "";
  char *my_trim = s21_trim(src, trim_chars);
  char *real = s21_NULL;
  ck_assert_ptr_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

START_TEST(trim_15) {
  char src[] = "1234567890";
  char trim_chars[] = "a";
  char *my_trim = s21_trim(src, trim_chars);
  char real[] = "1234567890";
  ck_assert_str_eq(my_trim, real);
  if (my_trim) free(my_trim);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("s21_trim");

  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, trim_6);
  tcase_add_test(tc, trim_7);
  tcase_add_test(tc, trim_8);
  tcase_add_test(tc, trim_9);
  tcase_add_test(tc, trim_10);
  tcase_add_test(tc, trim_11);
  tcase_add_test(tc, trim_12);
  tcase_add_test(tc, trim_13);
  tcase_add_test(tc, trim_14);
  tcase_add_test(tc, trim_15);

  suite_add_tcase(s, tc);
  return s;
}
