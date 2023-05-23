#include "test_string.h"

START_TEST(strstr_1) {
  char haystack[] = "Hello world!";
  char needle[] = "world";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_2) {
  char haystack[] = "Hello world!";
  char needle[] = "LO";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_3) {
  char haystack[] = "\0";
  char needle[] = "123";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_4) {
  char haystack[] = "Hello world!";
  char needle[] = "\0";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_5) {
  char haystack[] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.  The terminating null bytes ('\0') are "
      "not compared.";
  char needle[] = "\0";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_6) {
  char haystack[] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.";
  char needle[] = " ";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_7) {
  char haystack[] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.";
  char needle[] = "()";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_8) {
  char haystack[] =
      "The strstr() function finds the first occurrence of the substring "
      "needle in the string haystack.";
  char needle[] = ".";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_9) {
  char haystack[] = ".";
  char needle[] = "hello";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_10) {
  char haystack[] = "Hello";
  char needle[] = "hello";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_11) {
  char haystack[] = "1212121212121";
  char needle[] = "21";
  ck_assert_ptr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("s21_strstr");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  tcase_add_test(tc, strstr_11);

  suite_add_tcase(s, tc);
  return s;
}
