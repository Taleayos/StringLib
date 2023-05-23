#include "test_string.h"

START_TEST(insert_1) {
  char str[] = "New ";
  char src[] = "Happy Year!";
  s21_size_t index = 6;
  char expected[] = "Happy New Year!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(insert_2) {
  char str[] = "Good ";
  char src[] = "morning!";
  s21_size_t index = 0;
  char expected[] = "Good morning!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(insert_3) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(insert_4) {
  char *src = s21_NULL;
  char *str = s21_NULL;
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(insert_5) {
  char str[] = "21";
  char src[] = "School ";
  s21_size_t index = 7;
  char expected[] = "School 21";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

START_TEST(insert_6) {
  char *str = s21_NULL;
  char src[] = "Happy  ";
  s21_size_t index = 0;
  char expected[] = "Happy  ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  free(got);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("s21_insert");

  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);

  suite_add_tcase(s, tc);
  return s;
}
