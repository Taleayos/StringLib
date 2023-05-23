#include "test_string.h"

START_TEST(strchr_1) {
  char str[] = "Hello world!";
  int c = 72;  // 72 = 'H'
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char str[] = "Hello world!";
  int c = 107;  // 107 = 'k'
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char str[] = "Hello world!";
  int c = '\0';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  char str[] = "Hello world!";
  int c = ' ';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  char str[] = "12345678987654321";
  int c = 54;  // 54 = 6
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_6) {
  char str[] = "abs'11'abs";
  int c = 11;  // 11 = VT (непечатаемый символ)
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_7) {
  char str[] = "\0";
  int c = 61;  // 61 = a
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_8) {
  char str[] = "SCHOOL_21";
  int c = 'L';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_9) {
  char str[] = "SCHOOL_21";
  int c = 'l';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_10) {
  char str[] = "qwerty";
  int c = 'w';
  ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("s21_strchr");

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);

  suite_add_tcase(s, tc);
  return s;
}
