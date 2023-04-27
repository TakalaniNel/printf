#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/* SIZES */
#define S_LONG 2
#define S_SHORT 1
/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;

	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int hnd_print(const char *fmt, int, va_list, char bf[], int fg, int wd, int);
/****************** FUNCTIONS ******************/
/* Funtions to print chars and strings */
int print_char(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
int print_string(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
int print_percent(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
/* Functions to print numbers */
int print_int(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
int print_binary(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
int print_unsigned(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
int print_octal(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
int print_hexadecimal(va_list tp, char buf[], int fg, int wd, int pre, int sz);
int print_hexa_upper(va_list tp, char buf[], int fg, int wd, int pre, int sz);
int print_hexa(va_list tp, char mp_to[], char bf[], int fg, char fg_ch);
/* Function to print non printable characters */
int print_non_printable(va_list tp, char bf[], int fg, int wd, int pr, int sz);
/* Funcion to print memory address */
int print_pointer(va_list tp, char buffer[], int fg, int wd, int pre, int sz);
/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
/*Function to print string in reverse*/
int print_reverse(va_list tp, char bf[], int fg, int wd, int pre, int sz);
/*Function to print a string in rot 13*/
int print_rot13string(va_list tp, char bf[], int fg, int wd, int pre, int sz);
/* width handler */
int handle_write_char(char c, char bf[], int fg, int wd, int pre, int sz);
int write_number(int is_pos, int ind, char bf[], int fg);
int write_num(int ind, char bf[], int len, char pd, char ex_c);
int write_pointer(char bf[], int id, int ln, char pd, char ex_c, int pd_st);
int write_unsgnd(int is_neg, int ind, char bf[], int fg);
/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
