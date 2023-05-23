#include "test_string.h"

int main(void) {
  Suite *suites[] = {test_strlen(),   test_strspn(),
                     test_strcspn(),  test_strchr(),
                     test_strrchr(),  test_strstr(),
                     test_strtok(),   test_strpbrk(),
                     test_strcpy(),   test_strncpy(),
                     test_memcpy(),   test_memmove(),
                     test_memset(),   test_memchr(),
                     test_strerror(), test_strcat(),
                     test_strncat(),  test_to_upper(),
                     test_to_lower(), test_insert(),
                     test_trim(),     test_strcmp(),
                     test_strncmp(),  test_memcmp(),
                     test_sprintf(),  NULL};

  for (Suite **pS = suites; *pS != NULL; pS++) {
    SRunner *sr = srunner_create(*pS);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }
  return 0;
}
