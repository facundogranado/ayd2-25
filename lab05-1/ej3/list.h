#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

/* list as a pointer to structs to guarantee encapsulation */
typedef struct _list * list;
typedef int list_elem;
/* Constructors */
list empty(void);

list addl(list l, list_elem e);

/*destroy*/
list destroy(list l);

/* Operations */
bool is_empty(list l);

/* PRECONDITION: !is_empty(l) */
list_elem head(list l);

/* PRECONDITION: !is_empty(l) */
list tail(list l);

list addr(list l, list_elem e);

int length(list l);

list concat(list l1, list l2);

/* PRECONDITION: length(l) > n */
list_elem index(list l, int n);

list take(list l, int n);

list drop(list l, int n);

list copy_list(list l);

#endif
