#include<stdio.h>
#include<stdlib.h>
int stack[5];
int top=-1;
void push(){
int val;
if(top==4){
    printf("Stack Overflow:\n");
}
else{
    printf("Enter the elemnt to be inserted:");
    scanf("%d",&val);
    top++;
    stack[top]=val;
    printf("Inserted element is %d \n",val);
}
}
void pop(){
if(top==-1){
    printf("Stack Underflow");
}
else{
    printf("The poped element is %d \n",stack[top]);
    top--;
}
}
void display(){
if(top==-1){
    printf("Stack is empty\n");
}
else{
     printf("The elements in stack are:");
     for(int i=top;i>=0;i--){
         printf("%d \n",stack[i]);
     }
}
}
int main(){
    int c;
    while(1){
    printf("\t MENU \t \n");
    printf("1. for PUSH\n 2. for POP\n 3. for DISPLAY\n 4.exit\n");
    printf("Enter your choice:");
    scanf("%d",&c);
    switch(c){
        case 1:
               push();
               break;
        case 2:
               pop();
               break;
        case 3:
               display();
               break;
        case 4:
              exit(0);
              default:
              printf("exit from c");
    }
    }
}