#include "test_string.h"

START_TEST(strcpy_1) {
  char src[50] = "Happy New Year!";
  char dest[50] = "The strcpy() function copies the string";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_2) {
  char src[50] = "Happy New Year!";
  char dest[50] = "123456789";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_3) {
  char src[50] = "Happy New Year!";
  char dest[50] = "\0";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_4) {
  char src[50] = "\0";
  char dest[50] = "Happy New Year!";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_5) {
  char src[50] = "\nqwerty";
  char dest[50] = "The strcpy() function copies the string";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_6) {
  char src[50] = "Happy New Year!";
  char dest[50] = "\nqwerty";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_7) {
  char src[50] = "\0";
  char dest[50] = "\0";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_8) {
  char src[50] = "  school21";
  char dest[50] = "The strcpy() function copies the string";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_9) {
  char src[50] = "01/01/2023";
  char dest[50] = "12345";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

START_TEST(strcpy_10) {
  char src[50] = " ";
  char dest[50] = " ";
  ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest, src));
}
END_TEST

Suite *test_strcpy(void) {
  Suite *s = suite_create("s21_strcpy");
  TCase *tc = tcase_create("s21_strcpy");

  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_2);
  tcase_add_test(tc, strcpy_3);
  tcase_add_test(tc, strcpy_4);
  tcase_add_test(tc, strcpy_5);
  tcase_add_test(tc, strcpy_6);
  tcase_add_test(tc, strcpy_7);
  tcase_add_test(tc, strcpy_8);
  tcase_add_test(tc, strcpy_9);
  tcase_add_test(tc, strcpy_10);

  suite_add_tcase(s, tc);
  return s;
}
