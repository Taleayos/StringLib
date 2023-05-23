#include "test_string.h"

START_TEST(strpbrk_1) {
  char str1[] = "Hello world!";
  char str2[] = "on12";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str1[] = "Hello world!";
  char str2[] = "+=!";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str1[] = "Hello world!";
  char str2[] = "+";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str1[] = "\0";
  char str2[] = "1234";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str1[] =
      "The strpbrk() function locates the first occurrence in the string s of "
      "any of the characters in the string accept.";
  char str2[] = "\0";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  char str1[] =
      "The strpbrk() function locates the first occurrence in the string s of "
      "any of the characters in the string accept.";
  char str2[] = "t";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_7) {
  char str1[] =
      "The strpbrk() function locates the first occurrence in the string s of "
      "any of the characters in the string accept.";
  char str2[] = "-+=.";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_8) {
  char str1[] = "school-21";
  char str2[] = "SCHOOL";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_9) {
  char str1[] = "12343434343567";
  char str2[] = "50945";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_10) {
  char str1[] = ".";
  char str2[] = "hello.";
  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("s21_strpbrk");

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strpbrk_9);
  tcase_add_test(tc, strpbrk_10);

  suite_add_tcase(s, tc);
  return s;
}
