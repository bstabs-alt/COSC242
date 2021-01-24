#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern void f_append(flexarray f, int item);
extern void f_free(flexarray f);
extern flexarray f_new();
extern void f_print(flexarray f);
extern void f_sort(flexarray f);

#endif
