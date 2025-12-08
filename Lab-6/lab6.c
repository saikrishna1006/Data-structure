#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create(int n) {
    struct Node *NewNode, *temp, *headLocal = NULL;
    int data;

    for (int i = 1; i <= n; i++) {
        NewNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &data);

        NewNode->data = data;
        NewNode->next = NULL;

        if (headLocal == NULL) {
            headLocal = NewNode;
            temp = headLocal;
        } else {
            temp->next = NewNode;
            temp = NewNode;
        }
    }
    return headLocal;
}

void sort(struct Node *head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


void display(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse(struct Node **headRef) {
    struct Node *prev = NULL;
    struct Node *current = *headRef;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}


void push(struct Node **headRef, int c){
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = c;
    new->next = *headRef;
    *headRef = new;
}


void pop(struct Node **headRef){
    if (*headRef == NULL) return;
    struct Node *temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}


void concatenate(struct Node **head1, struct Node *head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node *temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

int main() {
    int x, x1;
    struct Node *head1, *head2;

    printf("Enter no of elements in list 1: ");
    scanf("%d", &x);
    head1 = create(x);

    printf("Enter no of elements in list 2: ");
    scanf("%d", &x1);
    head2 = create(x1);


    concatenate(&head1, head2);
    printf("\nConcatenated List:\n");
    display(head1);


    sort(head1);
    printf("\nSorted Concatenated List:\n");
    display(head1);

    reverse(&head1);
    printf("\nReversed List:\n");
    display(head1);


    push(&head1, 10);
    printf("\nAfter pushing 10:\n");
    display(head1);


    pop(&head1);
    printf("\nAfter popping head:\n");
    display(head1);

    return 0;
}
