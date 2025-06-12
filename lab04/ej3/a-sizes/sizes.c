#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t *messi = malloc(sizeof(data_t));
    messi->age = 36;
    messi->height = 170;
    strcpy(messi->name, "Lionel Messi");
    print_data(*messi);
    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi->name),sizeof(messi->age),sizeof(messi->height), sizeof(messi));

    printf("name-memory: %lu\n"
           "age-memory : %lu\n"
           "height-memory: %lu\n"
           "data_t-memory: %lu\n", (uintptr_t) &messi->name, (uintptr_t) &messi->age, (uintptr_t) &messi->height, (uintptr_t) &messi);
    
    free(messi);
    return EXIT_SUCCESS;
}

// La suma de memoria de los tipos de datos no es igual al tamaño de la estructura y campo name no depende del nombre que contiene

// La dirreccion de memoria de name es la misma que la de messi 