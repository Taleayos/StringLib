FLAGS = -Wall -Werror -Wextra -std=c11

all: clean gcov_report

s21_string.a:
	gcc -c $(FLAGS) s21_*.c
	ar rc s21_string.a s21_*.o
	ranlib s21_string.a

test: s21_string.a
	gcc -c $(FLAGS) test_*.c
	gcc -c $(FLAGS) main.c
	gcc -lcheck -fprofile-arcs -ftest-coverage s21_*.c s21_string.a test_*.o main.o -o tests
	./tests 

gcov_report:	test
	gcov s21_*.gcda	
	gcovr --html-details -o report.html
	open report.html

clean:
	rm -rf *.o *.a *.gcno  *.gcda *.gcov *.css *.html *.dSYM
	rm -rf tests
