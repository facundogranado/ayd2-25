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
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    if (xs == NULL) {
        fprintf(stderr, "Cannot remove tail from an empty list\n");
        return NULL;
    }

    Node* to_free = xs;
    xs = xs->next; // Mover la cabeza al siguiente nodo
    free(to_free); // Liberar el nodo eliminado
    return xs;
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

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
