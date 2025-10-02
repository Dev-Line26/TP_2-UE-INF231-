#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* inserer_tete(Node* tail, int val) {
    Node* new = malloc(sizeof(Node));
    new->data = val;

    if (!tail) {
        new->next = new;
        return new;
    }

    new->next = tail->next;
    tail->next = new;
    return tail;
}

Node* inserer_queue(Node* tail, int val) {
    tail = inserer_tete(tail, val);
    return tail->next;
}

void afficher(Node* tail) {
    if (!tail) return;
    Node* p = tail->next;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("...\n");
}

int main() {
    Node* tail = NULL;
    tail = inserer_tete(tail, 20);
    tail = inserer_tete(tail, 10);
    tail = inserer_queue(tail, 30);
    afficher(tail);
    return 0;
}

