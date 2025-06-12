#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
void absolute(int x, int *y) {
    if(x >= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---
    a = -10;
    absolute(a, &res);  
    printf("The absolute value of %d is %d\n", a, res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

