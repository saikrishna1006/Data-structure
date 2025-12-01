#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL, *tail = NULL;

void create(int n) {
    int data, i;
    for (i = 0; i < n; i++) {
        struct Node *Newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data of element %d: ", i + 1);
        scanf("%d", &data);
        Newnode->data = data;
        Newnode->next = NULL;
        Newnode->prev = tail;

        if (head == NULL) {
            head = tail = Newnode;
        } else {
            tail->next = Newnode;
            tail = Newnode;
        }
    }
}

void insertleft(int x) {
    struct Node *Newnode = (struct Node*)malloc(sizeof(struct Node));
    Newnode->data = x;
    Newnode->prev = NULL;
    Newnode->next = head;

    if (head == NULL) {
        head = tail = Newnode;
    } else {
        head->prev = Newnode;
        head = Newnode;
    }
}

void insertright(int x) {
    struct Node *Newnode = (struct Node*)malloc(sizeof(struct Node));
    Newnode->data = x;
    Newnode->next = NULL;
    Newnode->prev = tail;

    if (tail == NULL) {
        head = tail = Newnode;
    } else {
        tail->next = Newnode;
        tail = Newnode;
    }
}

void deleteval(int x) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }
    if (temp == NULL) return;

    if (temp == head) {
        head = temp->next;
        if (head) head->prev = NULL;
    } else if (temp == tail) {
        tail = temp->prev;
        if (tail) tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void display(){
    struct Node *temp = head;
    if(head==NULL){
        printf("EMPTY LIST!");
    }
    else{
        while(temp->next !=NULL){
            printf("%d ->",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
}

int main() {
    int choice, n, v, x, val;
    while (1) {
        printf("\n***MENU***\n1.Create\n2.Insert left\n3.Insert right\n4.Delete by value\n5.Display\n6.EXIT!\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                create(n);
                break;
            case 2:
                printf("Enter value to insert at front: ");
                scanf("%d", &v);
                insertleft(v);
                break;
            case 3:
                printf("Enter value to insert at last: ");
                scanf("%d", &x);
                insertright(x);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteval(val);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("---EXIT---\n");
                return 0;
        }
    }
}

