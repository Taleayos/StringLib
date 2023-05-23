#include "test_string.h"

START_TEST(strcmp_1) {
  char str1[] = "\0";
  char str2[] = "\0";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_2) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_3) {
  char str1[] = "\n";
  char str2[] = "\n";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_4) {
  char str1[] = "s21_NULL";
  char str2[] = "\n s21_NULL";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_5) {
  char str1[] = "\tHello\0";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_6) {
  char str1[] = "School_21\nSchool_21";
  char str2[] = "School_21";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_7) {
  char str1[] = "987654321";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_8) {
  char str1[] = "";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_9) {
  char str1[] = " \0";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_10) {
  char str1[] = "     \n";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_11) {
  char str1[] = "SCHOOL21";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_12) {
  char str1[] =
      "Computes the length of the string str up to but not including the "
      "terminating null character.";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_13) {
  char str1[] =
      "Computes\tthe\tlength\tof\tthe\tstring\tstr\tup\tto\tbut\tnot\tincluding"
      "\tthe\tterminating\tnull\tcharacter.";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_14) {
  char str1[] =
      "Вычисляет длину строки str, не включая завершающий нулевой символ.";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_15) {
  char str1[] = "School_21\0School_21";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

Suite *test_strcmp(void) {
  Suite *s = suite_create("s21_strcmp");
  TCase *tc = tcase_create("s21_strcmp");

  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);
  tcase_add_test(tc, strcmp_4);
  tcase_add_test(tc, strcmp_5);
  tcase_add_test(tc, strcmp_6);
  tcase_add_test(tc, strcmp_7);
  tcase_add_test(tc, strcmp_8);
  tcase_add_test(tc, strcmp_9);
  tcase_add_test(tc, strcmp_10);
  tcase_add_test(tc, strcmp_11);
  tcase_add_test(tc, strcmp_12);
  tcase_add_test(tc, strcmp_13);
  tcase_add_test(tc, strcmp_14);
  tcase_add_test(tc, strcmp_15);

  suite_add_tcase(s, tc);
  return s;
}
