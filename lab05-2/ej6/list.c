#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

list empty() {
    list l = malloc(sizeof(struct _list));
    l->start = 0;
    l->size = 0;
    return l;
}
list addl(elem e, list l) {
    assert(l->size < MAX_LENGTH);
    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;
    l->a[l->start] = e;
    l->size++;
    return l;
}
bool is_empty(list l) {
    return l->size == 0;
}
elem head(list l) {
    assert(!is_empty(l));
    return l->a[l->start];
}
list tail(list l) {
    assert(!is_empty(l));
    l->start = (l->start + 1) % MAX_LENGTH;
    l->size--;
    return l;
}
list addr(list l, elem e) {
    assert(l->size < MAX_LENGTH);
    int end = (l->start + l->size) % MAX_LENGTH;
    l->a[end] = e;
    l->size++;
    return l;
}
int length(list l) {
    return l->size;
}
list concat(list l, list l0) {
    for (int i = 0; i < l0->size; i++) {
        addr(l, l0->a[(l0->start + i) % MAX_LENGTH]);
    }
    return l;
}
list copy_list(list l) {
    list new_list = empty();
    for (int i = 0; i < l->size; i++) {
        new_list = addr(new_list, l->a[(l->start + i) % MAX_LENGTH]);
    }   
    return new_list;
}

elem index(list l, int i) {
    return l->a[(l->start + i) % MAX_LENGTH];
}

list take(list l, int n) {
    list new_list = empty();
    if(n > l->size) {
        n = l->size;
    }
    for (int i = 0; i < n; i++) {
        new_list = addr(new_list, index(l, i));
    }
    return new_list;
}

list drop(list l, int n) {
    assert(n >= 0 && n <= l->size);
    l->start = (l->start + n) % MAX_LENGTH;
    l->size -= n;
    return l;
}
void destroy_list(list l) {
    free(l);
}