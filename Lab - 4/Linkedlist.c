#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create(int n){
    struct Node *NewNode, *temp;
    int data;

    if(n <= 0){
        printf("\nInvalid Length");
        return;
    }

    head = NULL;

    for(int i = 1; i <= n; i++){
        NewNode = (struct Node*)malloc(sizeof(struct Node));
        if(NewNode == NULL){
            printf("\nNo Memory present");
            return;
        }

        printf("\nEnter data: ");
        scanf("%d", &data);

        NewNode->data = data;
        NewNode->next = NULL;

        if(head == NULL){
            head = NewNode;
            temp = head;        
        } else {
            temp->next = NewNode;
            temp = NewNode;
        }
    }
}

void insertfirst(int data){
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->next = head;
    head = NewNode;
    printf("\nInserted at first!");
}

void insertany(int data, int pos){
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;

    if(pos < 1){
        printf("\nInvalid Position");
        return;
    }
    else if(pos == 1){
        insertfirst(data);
        return;
    }

    NewNode->data = data;

    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL){
        printf("\nNot in range");
        free(NewNode);
        return;
    }

    NewNode->next = temp->next;
    temp->next = NewNode;
    printf("\nInserted at %d", pos);
}

void insertend(int data){
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;

    NewNode->data = data;
    NewNode->next = NULL;

    if(head == NULL){
        head = NewNode;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = NewNode;
    }
    printf("\nInserted at end");
}

void display(){
    struct Node *temp = head;

    if(head == NULL){
        printf("\nEmpty List");
        return;
    }

    printf("\nList: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    int c, data, n, pos;
    printf("\n 1.Create Linked List \n 2.Insert at First \n 3.Insert Anywhere \n 4.Insert at Last \n 5.Display \n 6.Exit");

    while(1){
        printf("\nEnter choice: ");
        scanf("%d", &c);

        if(c == 6){
            printf("Exit!");
            break;
        }

        switch(c){
            case 1:
                printf("\nEnter list length: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertfirst(data);
                break;

            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                printf("\nEnter Position: ");
                scanf("%d", &pos);
                insertany(data, pos);
                break;

            case 4:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertend(data);
                break;

            case 5:
                display();
                break;

            default:
                printf("Invalid Choice");
        }
    }
}