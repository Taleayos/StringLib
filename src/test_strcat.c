#include "test_string.h"

START_TEST(strcat_1) {
  char dest[50] = "Hello ";
  char src[] = "world!";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_2) {
  char dest[50] = "\0";
  char src[] = "world!";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_3) {
  char dest[50] = "Hello";
  char src[] = "\0";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_4) {
  char dest[1024] =
      "The strcat() function appends the src string to the dest string, "
      "overwriting the terminating null byte ('\0') at the end of dest, and "
      "then adds a terminating null byte.";
  char src[] = ") at the end of dest, and then adds a terminating null byte.";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_5) {
  char dest[50] = "Hello";
  char src[] = "\n\tworld!";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_6) {
  char dest[50] = "12345";
  char src[] = "678910";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_7) {
  char dest[50] = "12 + 5 = ";
  char src[] = "17";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_8) {
  char dest[50] = "\0";
  char src[] = "\0";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_9) {
  char dest[50] = "Strcat\\\\\\\0\t";
  char src[] = "strcat";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

START_TEST(strcat_10) {
  char dest[50] = "test strcat";
  char src[] = "\0\\\\\t";
  ck_assert_str_eq(strcat(dest, src), s21_strcat(dest, src));
}
END_TEST

Suite *test_strcat(void) {
  Suite *s = suite_create("s21_strcat");
  TCase *tc = tcase_create("s21_strcat");

  tcase_add_test(tc, strcat_1);
  tcase_add_test(tc, strcat_2);
  tcase_add_test(tc, strcat_3);
  tcase_add_test(tc, strcat_4);
  tcase_add_test(tc, strcat_5);
  tcase_add_test(tc, strcat_6);
  tcase_add_test(tc, strcat_7);
  tcase_add_test(tc, strcat_8);
  tcase_add_test(tc, strcat_9);
  tcase_add_test(tc, strcat_10);

  suite_add_tcase(s, tc);
  return s;
}
