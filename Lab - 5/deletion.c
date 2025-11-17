#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int n) {
    struct Node *NewNode, *temp;
    int data;

    if (n <= 0) {
        printf("\nInvalid Length\n");
        return;
    }

    head = NULL;

    for (int i = 1; i <= n; i++) {
        NewNode = (struct Node *)malloc(sizeof(struct Node));
        if (NewNode == NULL) {
            printf("\nNo Memory available\n");
            return;
        }

        printf("Enter data : ");
        scanf("%d", &data);

        NewNode->data = data;
        NewNode->next = NULL;

        if (head == NULL) {
            head = NewNode;
            temp = head;
        } else {
            temp->next = NewNode;
            temp = NewNode;
        }
    }
}

void delfirst() {
    struct Node *temp;
    if (head == NULL) {
        printf("\nEmpty List\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("%d deleted\n", temp->data);
    free(temp);
}

void delLast(){ 
    struct Node *temp,*prev; 
    temp = head; 
    if(head == NULL)
        { printf("\nEmpty List"); } 
    while(temp->next != NULL)
        {   prev = temp; 
            temp = temp->next; }
     prev -> next = NULL;
     printf("%d deleted",temp->data);
     free(temp); }

void delVal(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("\nEmpty List\n");
        return;
    }
    if(head->data == value){
        temp = head;
        head = head->next;
        free(temp);
        printf("%d deleted",value);
        return;
    }
    temp = head;
    while(temp->next!= NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp;
    free(temp);
    printf("%d deleted",value);
}

void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("\nEmpty List\n");
        return;
    }

    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int c, n, x;

    printf("\nMenu:\n 1. Create Linked List\n 2. Delete First\n 3. Delete Last\n 4. Delete by Value\n 5. Display\n 6. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter list length: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                delfirst();
                break;

            case 3:
                delLast();
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                delVal(x);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exit!\n");
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}