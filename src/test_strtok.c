#include "test_string.h"

START_TEST(strtok_1) {
  char s1[] = "/testing/with/original/string.h/";
  char s2[] = "/testing/with/original/string.h/";
  char del[] = "/";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_2) {
  char s1[] = ". . testing with original string.h";
  char s2[] = ". . testing with original string.h";
  char del[] = ". ";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_3) {
  char s1[] = "testing with original string.h";
  char s2[] = "testing with original string.h";
  char del[] = ". ";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_4) {
  char s1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char s2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_5) {
  char s1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char s2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_6) {
  char s1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char s2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_7) {
  char s1[] = "AbobaHasNoDelims";
  char s2[] = "AbobaHasNoDelims";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_8) {
  char s1[] = "++++++++";
  char s2[] = "++++++++";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  ck_assert_ptr_null(p1);
  ck_assert_ptr_null(p2);
}
END_TEST

START_TEST(strtok_9) {
  char s1[] = "Aboba_Floppa_Roba";
  char s2[] = "Aboba_Floppa_Roba";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_10) {
  char s1[] = "Roba++++Kepa++A++++B__V";
  char s2[] = "Roba++++Kepa++A++++B__V";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_11) {
  char s1[] = "Aboba__+Floppa_  Roba";
  char s2[] = "Aboba__+Floppa_  Roba";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_12) {
  char s1[] = "Aboba__Floppa_+++Roba_Kepa";
  char s2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_13) {
  char s1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char s2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_14) {
  char s1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char s2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_15) {
  char s1[] = "!       A!B!C!D!E!!F!!G";
  char s2[] = "!       A!B!C!D!E!!F!!G";
  const char del[] = "+_! =";
  char *p1 = strtok(s1, del);
  char *p2 = s21_strtok(s2, del);
  while (p1 != NULL) {
    ck_assert_str_eq(p1, p2);
    p1 = strtok(NULL, del);
    p2 = s21_strtok(NULL, del);
  }
}
END_TEST

START_TEST(strtok_16) {
  char *p1 = strtok(NULL, NULL);
  char *p2 = s21_strtok(NULL, NULL);
  ck_assert_ptr_null(p1);
  ck_assert_ptr_null(p2);
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("case_strtok");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  tcase_add_test(tc, strtok_11);
  tcase_add_test(tc, strtok_12);
  tcase_add_test(tc, strtok_13);
  tcase_add_test(tc, strtok_14);
  tcase_add_test(tc, strtok_15);
  tcase_add_test(tc, strtok_16);

  suite_add_tcase(s, tc);
  return s;
}
