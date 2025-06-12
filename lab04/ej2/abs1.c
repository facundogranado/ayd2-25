#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x>=0) {
        y = x;
    }else {
        y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    printf("The absolute value of %d is %d\n", a, res);
    return EXIT_SUCCESS;
}

// El valor que  se muestra por pantalla es 0, no coincide con el valor en el lenguaje de teorico