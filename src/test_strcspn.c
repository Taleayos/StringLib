#include "test_string.h"

START_TEST(strcspn_1) {
  char str1[] = "Hello world!";
  char str2[] = "world";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  char str1[] = "Hello world!";
  char str2[] = "Hello world!";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  char str1[] = "Hello world!";
  char str2[] = "\0";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  char str1[] = "\0";
  char str2[] = "H";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  char str1[] =
      "ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2))";
  char str2[] = " ";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  char str1[] = "123456789";
  char str2[] = "+";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  char str1[] = "123456789";
  char str2[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  char str1[] = "12";
  char str2[] = "987654321";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  char str1[] =
      "The C library function strcspn() calculates the length of the number of "
      "characters before the 1st occurrence of character present in both the "
      "string.";
  char str2[] = " library";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10) {
  char str1[] =
      "The C library function strcspn() calculates the length of the number of "
      "characters before the 1st occurrence of character present in both the "
      "string.";
  char str2[] = "123456789";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

Suite *test_strcspn(void) {
  Suite *s = suite_create("s21_strcspn");
  TCase *tc = tcase_create("s21_strcspn");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);

  suite_add_tcase(s, tc);
  return s;
}
