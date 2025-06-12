#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(void) {
    int x = 6, y = 4;
    printf("Before swap: a = %d, b = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: a = %d, b = %d\n", x, y);
    return EXIT_SUCCESS;
}