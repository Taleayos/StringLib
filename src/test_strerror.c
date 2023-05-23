#include "test_string.h"

int i = 1;
START_TEST(strerror_1) { ck_assert_str_eq(strerror(-1), s21_strerror(-1)); }
END_TEST

START_TEST(strerror_2) { ck_assert_str_eq(strerror(0), s21_strerror(0)); }
END_TEST

START_TEST(strerror_3) {
  for (int i = 1; i < 140; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("s21_strerror");

  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);

  suite_add_tcase(s, tc);
  return s;
}
