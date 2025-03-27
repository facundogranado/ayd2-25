#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;  
    res.is_lowerbound = true; 
    res.exists = false;
    res.where = -1;  
    for (unsigned int i = 0; i < length; i++){
        if(value>=arr[i]){
            res.is_upperbound = res.is_upperbound && true;
        }else{
            res.is_upperbound = false;
        }
        if (value<=arr[i]){
            res.is_lowerbound = res.is_lowerbound && true;
        }else{
            res.is_lowerbound = false;
        }
        if(value==arr[i]){
            res.exists = true;
            res.where = i;
        }else if(!res.exists){
            res.exists = false;
        }
    }
    
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    int value_array;
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("Ingrese un valor para la posicion %d del arreglo \n",i);
        scanf("%d",&value_array);
        a[i]=value_array;
    }
    printf("Ingrese el valor para verificar \n");
    scanf("%d",&value);
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);
    if(result.exists){
        if(result.is_upperbound){
            printf("El valor ingresado es cota superior y maximo,se encuentra en la posicion: %d\n",result.where);
        }else if(result.is_lowerbound){
            printf("El valor ingresado es cota inferior y minimo,se encuentra en la posicion: %d\n",result.is_lowerbound);
        }else if(!result.is_upperbound){
            printf("El valor ingresado es cota superior");
        }else if(!result.is_lowerbound){
            printf("El valor ingresado es cota inferior");
        }
    }else{
        if(result.is_upperbound){
            printf("El valor ingresado es cota superior\n");
        }else if(result.is_lowerbound){
            printf("El valor ingresado es cota inferior\n");
        }
    }

    return EXIT_SUCCESS;
}

