#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    unsigned int length=0;
    while (length<FIXSTRING_MAX && s[length]!='\0'){
        length++;
    }
    assert(length<FIXSTRING_MAX);
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool isEq = true;
    unsigned int tam1= fstring_length(s1);
    unsigned int tam2=fstring_length(s2);
    if(tam1==tam2){
        for (unsigned int i = 0; i < tam1 && isEq; i++){
            if(s1[i]!=s2[i]){
                isEq = false;
            }
        }
        
    }else{
        isEq=false;
    }
    return isEq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool leesEq = true;
    unsigned int i = 0;
    unsigned int tam1 = fstring_length(s1);
    unsigned int tam2 = fstring_length(s2);
    while (s1[i]==s2[i] && i<tam1 && i<tam2){
        i++;
    }
    leesEq = s1[i]<=s2[i];
    return leesEq;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);
    fstring_set(s1, s2);
    fstring_set(s2, aux);

}


