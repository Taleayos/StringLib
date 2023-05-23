#include "test_string.h"

START_TEST(to_upper_1) {
  char str1[] = "ABC";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(to_upper_2) {
  char str1[] = "happy";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "HAPPY");
  free(str2);
}
END_TEST

START_TEST(to_upper_3) {
  char str1[] = "Happy New Year";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "HAPPY NEW YEAR");
  free(str2);
}
END_TEST

START_TEST(to_upper_4) {
  char str1[] = "ver666TER{}";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "VER666TER{}");
  free(str2);
}
END_TEST

START_TEST(to_upper_5) {
  char str1[] = ")(*&^YTRYUIKJHWR<LR3.,tmwnrg.";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, ")(*&^YTRYUIKJHWR<LR3.,TMWNRG.");
  free(str2);
}
END_TEST

START_TEST(to_upper_6) {
  char str1[] = "22*12*2022";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "22*12*2022");
  free(str2);
}
END_TEST

START_TEST(to_upper_7) {
  char str1[] = "";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("s21_to_upper");

  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_3);
  tcase_add_test(tc, to_upper_4);
  tcase_add_test(tc, to_upper_5);
  tcase_add_test(tc, to_upper_6);
  tcase_add_test(tc, to_upper_7);

  suite_add_tcase(s, tc);
  return s;
}
