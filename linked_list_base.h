#ifndef LINKED_LIST_BASE_H
#define LINKED_LIST_BASE_H

#include <stdio.h>
#include <stdlib.h>

/* Node pour liste simplement chaînée */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* DNode pour liste doublement chaînée */
typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

/* Fonctions utilitaires pour listes simples */
void print_list(Node *head);
void free_list(Node *head);

/* Fonctions utilitaires pour listes doubles */
void print_dlist(DNode *head);
void free_dlist(DNode *head);

/* Fonctions utilitaires pour listes circulaires */
void print_circular_singly(Node *head);
void print_circular_doubly(DNode *head);

#endif /* LINKED_LIST_BASE_H */
