#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

DNode* inserer_trie_double(DNode* head, int val) {
    DNode* new = malloc(sizeof(DNode));
    new->data = val;
    new->prev = new->next = NULL;

    if (!head || val < head->data) {
        new->next = head;
        if (head) head->prev = new;
        return new;
    }

    DNode* temp = head;
    while (temp->next && temp->next->data < val)
        temp = temp->next;

    new->next = temp->next;
    if (temp->next) temp->next->prev = new;
    temp->next = new;
    new->prev = temp;

    return head;
}
void afficher(DNode* head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    DNode* head = NULL;
    int val, n;
    printf("Nombre d’éléments à insérer : ");
    scanf("%d", &n);
    printf("Entrez les éléments :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = inserer_trie_double(head, val);
    }
    afficher(head);
    return 0;
}

new->next = new->prev = new;
        return new;
    }

    DNode* head = tail->next;
    new->next = head;
    new->prev = tail;
    head->prev = new;
    tail->next = new;
    return tail;
}

DNode* inserer_queue(DNode* tail, int val) {
    tail = inserer_tete(tail, val);
    return tail->next;
}

void afficher(DNode* tail) {
    if (!tail) return;
    DNode* p = tail->next;
    do {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != tail->next);
    printf("...\n");
}

int main() {
    DNode* tail = NULL;
    tail = inserer_tete(tail, 20);
    tail = inserer_tete(tail, 10);
    tail = inserer_queue(tail, 30);
    afficher(tail);
    return 0;
}
