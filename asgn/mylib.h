#ifndef MYLIB_H_
#define MYLIB_H_
#include <stddef.h>

/*Functions for memory allocation and reallocation.
  Reads word from stream of file or stdin
*/
extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *, int, FILE*);

#endif

