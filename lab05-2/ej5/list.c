#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

list empty(void) {
    list l = malloc(sizeof(struct _list));
    l->size = 0;
    return l;
}

list addl(elem e, list l) {
    assert(l->size < MAX_LENGTH);
    for (int i = l->size; i > 0; i--) {
        l->elems[i] = l->elems[i - 1];
    }
    l->elems[0] = e;
    l->size++;
    return l;
}

bool is_empty(list l) {
    return l->size == 0;
}

elem head(list l) {
    assert(!is_empty(l));
    return l->elems[0];
}
list tail(list l) {
    assert(!is_empty(l));
    for (int i = 0; i < l->size - 1; i++) {
        l->elems[i] = l->elems[i + 1];
    }
    l->size--;
    return l;
}
list addr(list l, elem e) {
    assert(l->size < MAX_LENGTH);
    l->elems[l->size] = e;
    l->size++;
    return l;
}
int length(list l) {
    return l->size;
}
list concat(list l, list l0) {
    assert(l->size + l0->size <= MAX_LENGTH);
    for (int i = 0; i < l0->size; i++) {
        l = addr(l, l0->elems[i]);
    }
    return l;
}
list copy_list(list l) {
    list new_list = empty();
    for (int i = 0; i < l->size; i++) {
        new_list = addr(new_list, l->elems[i]);
    }
    return new_list;
}
void destroy_list(list l) {
    free(l);
}

elem index(list l, int n) {
    assert(n >= 0 && n < l->size);
    return l->elems[n];
}

list take(list l, int n) {
    l->size = n > l->size ? l->size : n;
    return l;
}
list drop(list l, int n) {
    assert(n >= 0 && n <= l->size);
    for (int i = 0; i < l->size - n; i++) {
        l->elems[i] = l->elems[i + n];
    }
    l->size -= n;
    return l;
}