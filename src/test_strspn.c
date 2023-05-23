#include "test_string.h"

START_TEST(strspn_1) {
  char str1[] = "Hello world";
  char str2[] = "world";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_2) {
  char str1[] = "Hello world";
  char str2[] = "\0";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_3) {
  char str1[] = "Hello world\nHello world\0";
  char str2[] = "world";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_4) {
  char str1[] = "ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2))";
  char str2[] = "world";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_5) {
  char str1[] = "\0";
  char str2[] = "world";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_6) {
  char str1[] = "world123456789";
  char str2[] = "45";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_7) {
  char str1[] = "SCHOOL21_SCHOOL21";
  char str2[] = "OO";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_8) {
  char str1[] = "MooMooMooMooMooMooMoo";
  char str2[] = "M";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_9) {
  char str1[] = "ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2))";
  char str2[] = " ";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(strspn_10) {
  char str1[] = "ck\t\t\tck\t\t\tck";
  char str2[] = "     ";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

Suite* test_strspn(void) {
  Suite* s = suite_create("s21_strspn");
  TCase* tc = tcase_create("s21_strspn");

  tcase_add_test(tc, strspn_1);
  tcase_add_test(tc, strspn_2);
  tcase_add_test(tc, strspn_3);
  tcase_add_test(tc, strspn_4);
  tcase_add_test(tc, strspn_5);
  tcase_add_test(tc, strspn_6);
  tcase_add_test(tc, strspn_7);
  tcase_add_test(tc, strspn_8);
  tcase_add_test(tc, strspn_9);
  tcase_add_test(tc, strspn_10);

  suite_add_tcase(s, tc);
  return s;
}
