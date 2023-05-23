#include "test_string.h"

START_TEST(memmove_1) {
  char src[50] = "Happy New Year!";
  char dest[50] = "The strcpy() function copies the string";
  size_t n = 4;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_2) {
  char src[50] = "Happy New Year!";
  char dest[50] = "123456789";
  size_t n = 8;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_3) {
  char src[50] = "Happy New Year!";
  char dest[50] = "\0";
  size_t n = 1;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_4) {
  char src[50] = "\0";
  char dest[50] = "Happy New Year!";
  size_t n = 10;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_5) {
  char src[50] = "\nqwerty";
  char dest[50] = "The strcpy() function copies the string";
  size_t n = 4;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_6) {
  char src[50] = "Happy New Year!";
  char dest[50] = "\nqwerty";
  size_t n = 4;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_7) {
  char src[50] = "\0";
  char dest[50] = "\0";
  size_t n = 0;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_8) {
  char src[50] = "  school21";
  char dest[50] = "The strcpy() function copies the string";
  size_t n = 5;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_9) {
  char src[50] = "01/01/2023";
  char dest[50] = "12345";
  size_t n = 10;
  ck_assert_str_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memmove_10) {
  char src[50] = " ";
  char dest[50] = " ";
  size_t n = 1;
  ck_assert_str_eq(memmove(dest, src, n), s21_memmove(dest, src, n));
}
END_TEST

Suite *test_memmove(void) {
  Suite *s = suite_create("s21_memmove");
  TCase *tc = tcase_create("s21_memmove");

  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);
  tcase_add_test(tc, memmove_4);
  tcase_add_test(tc, memmove_5);
  tcase_add_test(tc, memmove_6);
  tcase_add_test(tc, memmove_7);
  tcase_add_test(tc, memmove_8);
  tcase_add_test(tc, memmove_9);
  tcase_add_test(tc, memmove_10);

  suite_add_tcase(s, tc);
  return s;
}
