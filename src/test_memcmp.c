#include "test_string.h"

START_TEST(memcmp_1) {
  int str1 = 711362;
  int str2 = 717362;
  int n = 4;
  ck_assert_int_eq(memcmp(&str1, &str2, n), s21_memcmp(&str1, &str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  float str1 = 12.56;
  float str2 = 10.112;
  int n = 5;
  ck_assert_int_eq(memcmp(&str1, &str2, n), s21_memcmp(&str1, &str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  int str1 = 1;
  float str2 = 1.01;
  int n = 1;
  ck_assert_int_eq(memcmp(&str1, &str2, n), s21_memcmp(&str1, &str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "s21_NULL";
  int str2 = 6;
  int n = 5;
  ck_assert_int_eq(memcmp(str1, &str2, n), s21_memcmp(str1, &str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  long str1 = 56;
  float str2 = -56.00;
  int n = 500;
  ck_assert_int_eq(memcmp(&str1, &str2, n), s21_memcmp(&str1, &str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "School_21\nSchool_21";
  char str2[] = "School_21";
  int n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "";
  int str2 = 6;
  int n = 5;
  ck_assert_int_eq(memcmp(str1, &str2, n), s21_memcmp(str1, &str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "";
  char str2[] = "Hello world!";
  int n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = " \0";
  char str2[] = "Hello world!";
  int n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "     \n";
  char str2[] = "Hello world!";
  int n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_11) {
  char str1[] = "SCHOOL21";
  char str2[] = "Hello world!";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_12) {
  char str1[] =
      "Computes the length of the string str up to but not including the "
      "terminating null character.";
  char str2[] = "Hello world!";
  int n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_13) {
  char str1[] =
      "Computes\tthe\tlength\tof\tthe\tstring\tstr\tup\tto\tbut\tnot\tincluding"
      "\tthe\tterminating\tnull\tcharacter.";
  char str2[] = "Hello world!";
  int n = 5;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14) {
  char str1[] =
      "Вычисляет длину строки str, не включая завершающий нулевой символ.";
  char str2[] = "Hello world!";
  int n = 2;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_15) {
  char str1[] = "School_21\0School_21";
  char str2[] = "Hello world!";
  int n = 0;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_16) {
  int str1 = 1;
  int str2 = -1;
  int n = 0;
  ck_assert_int_eq(memcmp(&str1, &str2, n), s21_memcmp(&str1, &str2, n));
}
END_TEST

START_TEST(memcmp_17) {
  char str1[1] = {'\0'};
  long str2 = -1;
  int n = 0;
  ck_assert_int_eq(memcmp(str1, &str2, n), s21_memcmp(str1, &str2, n));
}
END_TEST

START_TEST(memcmp_18) {
  char str1[] = "Hello world";
  char str2[] = "Hello world!";
  int n = 10;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("s21_memcmp");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, memcmp_12);
  tcase_add_test(tc, memcmp_13);
  tcase_add_test(tc, memcmp_14);
  tcase_add_test(tc, memcmp_15);
  tcase_add_test(tc, memcmp_16);
  tcase_add_test(tc, memcmp_17);
  tcase_add_test(tc, memcmp_18);

  suite_add_tcase(s, tc);
  return s;
}
