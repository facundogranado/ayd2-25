#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct _list {
    list_elem elem;
    struct _list *next;
};

list empty(void) {
    list p = NULL;
    return p;
}

list addl(list l, list_elem e) {
    list p = malloc(sizeof(struct _list));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}

bool is_empty(list l) {
    return l == NULL;
}

list_elem head(list l) {
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l) {
    assert(!is_empty(l));
    list p;
    p = l;
    l = l->next;
    free(p);
    return l;
}

list addr(list l, list_elem e) {
    list p,q;
    q = malloc(sizeof(struct _list));
    q->elem = e;
    q->next = NULL;
    if (!is_empty(l)) {
        p = l;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    } else {
        l = q;
    }
    return l;
}

int length(list l) {
    int count = 0;
    list p = l;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

list concat(list l1, list l2) {
    if (is_empty(l1)) {
        l1 = l2;
    } else {
        list p = l1;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = l2;
    }
    return l1;
}

list_elem index(list l, int n) {
    assert(n >= 0 && n < length(l));
    list p = l;
    for (int i = 0; i < n; i++) {
        p = p->next;
    }
    return p->elem;
}

list take(list l, int n) {
    assert(n >= 0);
    list p = l;
    for (int i = 0; i < n && p != NULL; i++) {
        p = p->next;
    }
    while (p != NULL) {
        list temp = p;
        p = p->next;
        free(temp);
    }
    return l;
}

list drop(list l, int n) {
    assert(n >= 0);
    list p = l;
    for (int i = 0; i < n && p != NULL; i++) {
        list temp = p;
        p = p->next;
        free(temp);
    }
    l = p; // Update the head of the list
    return l;
}

list copy_list(list l) {
    list new_list = empty();
    list p = l;
    int j = length(l);
    int i = 0;
    while(i<j) {
       new_list = addr(new_list, p->elem);
        p = p->next;
        i++;
    }
    return new_list;
}

list destroy(list l) {
    while (!is_empty(l)) {
        tail(l);
    }
    return NULL;
}
