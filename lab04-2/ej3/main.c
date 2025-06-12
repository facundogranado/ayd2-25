#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    List head = malloc(sizeof(Node));
    if (head == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    head->data = 1;
    head->next = malloc(sizeof(Node));
    if (head->next == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    if (head->next->next == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    head->next->next->data = 3;
    head->next->next->next = NULL;
    return head;
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    if (xs == NULL) {
        fprintf(stderr, "Cannot append to an empty list\n");
        return;
    }

    // Avanzar hasta el final de la lista
    while (xs->next != NULL) {
        xs = xs->next;
    }

    // Crear un nuevo nodo
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->data = 4; // Valor del nuevo nodo
    new_node->next = NULL; // El nuevo nodo será el último

    // Enlazar el nuevo nodo al final de la lista
    xs->next = new_node;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}
