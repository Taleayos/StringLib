#include "test_string.h"
START_TEST(strncat_1) {
  char src[] = "Happy New Year!";
  char dest[100] = "The strcpy() function copies the string";
  ck_assert_str_eq(strncat(dest, src, 16), s21_strncat(dest, src, 16));
}
END_TEST

START_TEST(strncat_2) {
  char src[50] = "Happy New Year!";
  char dest[100] = "123456789";
  size_t n = 5;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_3) {
  char src[50] = "Happy New Year!";
  char dest[100] = "\0";
  size_t n = 7;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_4) {
  char src[50] = "\0";
  char dest[100] = "Happy New Year!";
  size_t n = 10;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_5) {
  char src[50] = "\nqwerty";
  char dest[100] = "The strcpy() function copies the string";
  size_t n = 4;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_6) {
  char src[50] = "Happy New Year!";
  char dest[100] = "\nqwerty";
  size_t n = 4;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_7) {
  char src[50] = "\0";
  char dest[100] = "\0";
  size_t n = 0;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_8) {
  char src[50] = "  school21";
  char dest[100] = "The strcpy() function copies the string";
  size_t n = 5;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_9) {
  char src[50] = "01/01/2023";
  char dest[100] = "12345";
  size_t n = 10;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_10) {
  char src[50] = " ";
  char dest[100] = " ";
  size_t n = 1;
  ck_assert_str_eq(strncat(dest, src, n), s21_strncat(dest, src, n));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("s21_strncat");
  TCase *tc = tcase_create("as21_strncat");

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);

  suite_add_tcase(s, tc);
  return s;
}
