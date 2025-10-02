#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* inserer_trie(Node* head, int val) {
    Node* new = malloc(sizeof(Node));
    new->data = val;
    new->next = NULL;

    if (!head || val < head->data) {
        new->next = head;
        return new;
    }

    Node* temp = head;
    while (temp->next && temp->next->data < val)
        temp = temp->next;

    new->next = temp->next;
    temp->next = new;
    return head;
}

void afficher(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int val, n;
    printf("Combien d’éléments à insérer ? ");
    scanf("%d", &n);
    printf("Entrez les éléments triés un par un :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = inserer_trie(head, val);
    }
    printf("Liste triée : ");
    afficher(head);
    return 0;
}
