#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    int i,j;
    int ppiv;
    ppiv = izq;
    i=izq+1;
    j=der;
    while (i<=j) {
        if(goes_before(a[i],a[ppiv])){
            i++;
        }else if(goes_before(a[ppiv],a[j])){
            j--;
        }else{
            swap(a,i,j);
        }
    }
    swap(a,ppiv,j);
    ppiv = j;
    return ppiv;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int ppvi;
    if(der>izq){
        ppvi = partition(a,izq,der);
        if (ppvi==0){
            quick_sort_rec(a,izq,ppvi);    
        }else{
            quick_sort_rec(a,izq,ppvi-1); 
        }
        quick_sort_rec(a,ppvi+1,der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


