#include "pair.h"
#include <stdlib.h>
#include <stdio.h>
pair_t pair_new(int x, int y){
    pair_t p;
    p.fst = x;
    p.snd = y;
    return p;
}
int pair_first(pair_t p){
    return p.fst;
}
int pair_second(pair_t p){
    return p.snd;
}
pair_t pair_swapped(pair_t p){
    pair_t swapped;
    swapped.fst = p.snd;
    swapped.snd = p.fst;
    return swapped;
}
void pair_destroy(pair_t p){
    // In this case, no dynamic memory allocation is used,
    (void)p; // Avoid unused parameter warning    
}