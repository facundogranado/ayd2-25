#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"
#include <assert.h>
/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */

 bool tiene_cima1(int a[], int length) {
    int k=0;
    while (k<length-1 && a[k]<a[k+1])
    {
        k++;
    }
    while (k<length-1 && a[k]>a[k+1])
    {
        k++;
    }
    return k == length-1;
}


 bool es_cima(int a[],int i,int length){
    assert(tiene_cima1(a,length));
    return (i == 0 || a[i] > a[i-1]) && (i == length - 1 || a[i] > a[i+1]);
}

bool izq_cima(int a[],int i,int length){
    assert(tiene_cima1(a,length));
    return i>0 && a[i]<a[i-1];  
}
bool der_cima(int a[],int i,int length){
    assert(tiene_cima1(a,length));
    return i<length-1 && a[i]<a[i+1];
}
int cima_rec(int a[],int left,int rgt,int length){
    assert(tiene_cima1(a,length));
    int result;
    int mid = (left + rgt) / 2;
    if(es_cima(a,mid,length)){
        result = mid;
    }else if(izq_cima(a,mid,length)){
        result = cima_rec(a,left,mid-1,length);
    }else if(der_cima(a,mid,length)){
        result = cima_rec(a,mid+1,rgt,length);
    }
    return result;
}
int cima_log(int a[], int length) {
    int result;
    result = cima_rec(a,0,length-1,length);
    return result;
}


