#include "test_string.h"

START_TEST(strncmp_1) {
  char str1[] = "\0";
  char str2[] = "\0";
  size_t n = 1;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  char str1[] = "";
  char str2[] = "";
  size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  char str1[] = "\n";
  char str2[] = "\n";
  size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  char str1[] = "s21_NULL";
  char str2[] = "\n s21_NULL";
  size_t n = 5;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  char str1[] = "\tHello\0";
  char str2[] = "Hello world!";
  size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6) {
  char str1[] = "School_21\nSchool_21";
  char str2[] = "School_21";
  size_t n = 11;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  char str1[] = "987654321";
  char str2[] = "Hello world!";
  size_t n = 4;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8) {
  char str1[] = "";
  char str2[] = "Hello world!";
  size_t n = 45;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9) {
  char str1[] = " \0";
  char str2[] = "Hello world!";
  size_t n = 6;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_10) {
  char str1[] = "     \n";
  char str2[] = "Hello world!";
  size_t n = 10;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_11) {
  char str1[] = "SCHOOL21";
  char str2[] = "Hello world!";
  size_t n = 0;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_12) {
  char str1[] =
      "Computes the length of the string str up to but not including the "
      "terminating null character.";
  char str2[] = "Hello world!";
  size_t n = 6;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_13) {
  char str1[] =
      "Computes\tthe\tlength\tof\tthe\tstring\tstr\tup\tto\tbut\tnot\tincluding"
      "\tthe\tterminating\tnull\tcharacter.";
  char str2[] = "Hello world!";
  size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14) {
  char str1[] =
      "Вычисляет длину строки str, не включая завершающий нулевой символ.";
  char str2[] = "Hello world!";
  size_t n = 3;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_15) {
  char str1[] = "School_21\0School_21";
  char str2[] = "Hello world!";
  size_t n = 4;
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc = tcase_create("s21_strncmp");

  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);
  tcase_add_test(tc, strncmp_11);
  tcase_add_test(tc, strncmp_12);
  tcase_add_test(tc, strncmp_13);
  tcase_add_test(tc, strncmp_14);
  tcase_add_test(tc, strncmp_15);

  suite_add_tcase(s, tc);
  return s;
}
