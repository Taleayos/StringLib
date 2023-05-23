#include "test_string.h"

START_TEST(memset_1) {
  char str[50] = "Happy New Year!";
  int c = 'k';
  size_t n = 4;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_2) {
  char str[50] = "Happy New Year!";
  int c = '2';
  size_t n = 4;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_3) {
  char str[50] = "Happy New Year!";
  int c = '3';
  size_t n = 1;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_4) {
  char str[50] = "\0";
  int c = 'k';
  size_t n = 1;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_5) {
  char str[50] = "\nqwerty";
  int c = '2';
  size_t n = 0;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_6) {
  char str[50] = "Happy New Year!";
  int c = 'k';
  size_t n = 4;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_7) {
  char str[50] = "\0";
  int c = 'a';
  size_t n = 10;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_8) {
  char str[50] = "  school21";
  int c = 'k';
  size_t n = 1;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_9) {
  char str[50] = "01/01/2023";
  int c = 'a';
  size_t n = 0;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_10) {
  char str[50] = " ";
  int c = 'w';
  size_t n = 5;
  ck_assert_str_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("s21_memset");
  TCase *tc = tcase_create("s21_memset");

  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);
  tcase_add_test(tc, memset_7);
  tcase_add_test(tc, memset_8);
  tcase_add_test(tc, memset_9);
  tcase_add_test(tc, memset_10);

  suite_add_tcase(s, tc);
  return s;
}
