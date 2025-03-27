#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int length=0;
    for (int i = 0; i < 100 && s[i] != '\0'; i++){
            length++;
    }
return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool isEq = true;
    if(fstring_length(s1)==fstring_length(s2)){
        for (int i = 0; i < fstring_length(s1) && isEq; i++){
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
    bool leesEq = false;
    bool b = true;
    for ( int i = 0; i < 100 && !leesEq && b; i++){
        if(s1[i]<s2[i]){
            leesEq = true;
        }else if(s1[i]>s2[i]){
            b = false;
        }
    }
    return leesEq;
}

