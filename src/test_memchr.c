#include "test_string.h"

START_TEST(memchr_1) {
  char str[] = "Hello world!";
  int c = 72;  // 72 = 'H'
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello world!";
  int c = '!';
  size_t n = 2;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char str[] =
      "The memchr() function scans the initial n bytes of the memory area "
      "pointed to by s for the first instance of c.  Both c and the bytes of "
      "the memory area pointed to by s are interpreted as unsigned char.";
  int c = '(';
  size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "Hello world!\0";
  int c = '\0';
  size_t n = 13;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "1234567890";
  int c = '4';
  size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = ".";
  int c = 'L';
  size_t n = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_7) {
  char str[] =
      "The memchr() function scans the initial n bytes of the memory area "
      "pointed to by s for the first instance of c. Both c and the bytes of "
      "the memory area pointed to by s are interpreted as unsigned char.";
  int c = '.';
  size_t n = 112;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "";
  int c = 'x';
  size_t n = 3;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "School-21";
  int c = '2';
  size_t n = 11;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST
START_TEST(memchr_10) {
  char str[] = "School-21";
  int c = '*';
  size_t n = 11;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

Suite *test_memchr(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc = tcase_create("s21_memchr");

  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);
  tcase_add_test(tc, memchr_10);

  suite_add_tcase(s, tc);
  return s;
}
