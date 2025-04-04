#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
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

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der,unsigned int lenght) {
    unsigned int ppvi;
    if(der>izq){
        printf("izq:%i\n",izq);
        printf("der:%i\n",der);
        array_dump(a,lenght);
        ppvi = partition(a,izq,der);
        printf("ppvi:%i\n",ppvi);
        array_dump(a,lenght);
        if (ppvi==0){
            quick_sort_rec(a,izq,ppvi,lenght);    
        }else{
            quick_sort_rec(a,izq,ppvi-1,lenght); 
        }
        quick_sort_rec(a,ppvi+1,der,lenght);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1,length);
}

