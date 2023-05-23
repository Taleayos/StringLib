#include "test_string.h"

START_TEST(strrchr_1) {
  char str[] = "\0";
  int c = 123;
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "Hello world!";
  int c = 'w';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "";
  int c = 'a';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "AaaaaaaaaaaaaA";
  int c = 97;  // 97 = 'a'
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "AaaaaaaaaaaaaA";
  int c = 98;  // 97 = 'b'
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_6) {
  char str[] = "1902939999209";
  int c = '9';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_7) {
  char str[] = "1902939999209";
  int c = 57;  // 57 = '9'
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_8) {
  char str[] = "135";
  int c = '1';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_9) {
  char str[] = "\tHello world!\n\0";
  int c = 'w';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

START_TEST(strrchr_10) {
  char str[] = "\tHello world!\n\0";
  int c = '\t';
  ck_assert_ptr_eq(strrchr(str, c), s21_strrchr(str, c));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("s21_strrchr");

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);

  suite_add_tcase(s, tc);
  return s;
}
