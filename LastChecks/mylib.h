/**
 * mylib.h
 * @authors Madison Wong, George Churton, Shay Stevens.
 * PURPOSE - This file holds the headers for the mylib file.
 * All functions in mylib.c are delceared within this file.
 */

#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *, int, FILE *);

#endif
