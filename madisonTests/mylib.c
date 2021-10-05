#include <assert.h>
#include <ctype.h>
#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h"

/**
 * Allocates memory and includes error checking.
 *
 * @param s -  type size_t, amount of memory to allocate.
 *
 * @return result - indicates successful memory allocation.
 */
void *emalloc(size_t s) {
    void *result = malloc(s);
    /* If memory allocation doesn't work print error message and exit */
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/**
 * Reallocates memory and includes error checking.
 *
 * @param *p - type void
 * @param s - type size_t amount of memory to reallocate.
 *
 * @return result - indicates successful memory allocation.
 */
void *erealloc(void *p, size_t s) {
    void *result = realloc(p, s);
    /* If memory reallocation doesn't work print error message and exit */
    if (NULL == result) {
        fprintf(stderr, "memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/**
 * Gets the word for us from the stream.
 *
 * @param s - char*, the word.
 * @param limit - int.
 * @param stream - FILE *, location where the words are gathered from.
 *
 * @return int, EOF or difference between two string arrays.
 */
int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);

    /* skip to the start of the word */
    while (!isalnum(c = getc(stream)) && EOF != c);
    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
        *w++ = tolower(c);
    }
    while (--limit > 0) {
        if (isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}


