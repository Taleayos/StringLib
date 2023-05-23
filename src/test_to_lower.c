#include "test_string.h"

START_TEST(to_lower_1) {
  char str1[] = "ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(to_lower_2) {
  char str1[] = "happy";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "happy");
  free(str2);
}
END_TEST

START_TEST(to_lower_3) {
  char str1[] = "Happy New Year";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "happy new year");
  free(str2);
}
END_TEST

START_TEST(to_lower_4) {
  char str1[] = "VER666TER";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "ver666ter");
  free(str2);
}
END_TEST

START_TEST(to_lower_5) {
  char str1[] = ")(*&^YTRYUIKJHWR<LR3.,jkdfhgsh.";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, ")(*&^ytryuikjhwr<lr3.,jkdfhgsh.");
  free(str2);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("s21_to_lower");

  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, to_lower_3);
  tcase_add_test(tc, to_lower_4);
  tcase_add_test(tc, to_lower_5);

  suite_add_tcase(s, tc);
  return s;
}
