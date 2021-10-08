/**
 * @file mylib.h
 * @author Madison Wong, George Churton, Shay Stevens.
 * PURPOSE - This mylib.h file contains the function prototypes for
 * mylib.c as well as the headers for the mylib program.
 */

#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *, int, FILE *);

#endif
