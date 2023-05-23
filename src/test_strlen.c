#include "test_string.h"

START_TEST(strlen_1) {
  char str1[] = "\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_2) {
  char str1[] = "Hello world!";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_3) {
  char str1[] = "\n";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_4) {
  char str1[] = "\tHello";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_5) {
  char str1[] = "\tHello\0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_6) {
  char str1[] = "School_21\nSchool_21";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_7) {
  char str1[] = "987654321";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_8) {
  char str1[] = "";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_9) {
  char str1[] = " \0";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_10) {
  char str1[] = "     \n";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_11) {
  char str1[] = "SCHOOL21";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_12) {
  char str1[] =
      "Computes the length of the string str up to but not including the "
      "terminating null character.";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_13) {
  char str1[] =
      "Computes\tthe\tlength\tof\tthe\tstring\tstr\tup\tto\tbut\tnot\tincluding"
      "\tthe\tterminating\tnull\tcharacter.";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_14) {
  char str1[] =
      "Вычисляет длину строки str, не включая завершающий нулевой символ.";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

START_TEST(strlen_15) {
  char str1[] = "School_21\0School_21";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
}
END_TEST

Suite *test_strlen(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("s21_strlen");

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);
  tcase_add_test(tc, strlen_6);
  tcase_add_test(tc, strlen_7);
  tcase_add_test(tc, strlen_8);
  tcase_add_test(tc, strlen_9);
  tcase_add_test(tc, strlen_10);
  tcase_add_test(tc, strlen_11);
  tcase_add_test(tc, strlen_12);
  tcase_add_test(tc, strlen_13);
  tcase_add_test(tc, strlen_14);
  tcase_add_test(tc, strlen_15);

  suite_add_tcase(s, tc);
  return s;
}
