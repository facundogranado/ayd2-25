#include <stdlib.h>
#include <stdio.h>
#include "pair.h"
pair_t pair_new(int x, int y) {
    pair_t p = malloc(sizeof(pair_t));
    if (p != NULL) {
        p->fst = x;
        p->snd = y;
    }
    return p;
}

int pair_first(pair_t p) {
    return p->fst;
}

int pair_second(pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {
    pair_t swapped = malloc(sizeof(pair_t));
    if (swapped != NULL) {
        swapped->fst = p->snd;
        swapped->snd = p->fst;
    }
    return swapped;
}

void pair_destroy(pair_t p) {
    free(p);
}
