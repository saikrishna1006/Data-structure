#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 30
char stack[N];
int top=-1;

void push(char x){
    if (top==N-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}

char pop(){
    char item;
    if(top==-1){
        printf("Stack Underflow");
    }
    else{
        item=stack[top];
        top--;
    }
    return item;
}

char peek(){
    if(top==-1){
        return '\0';
    }
    return stack[top];
}

int precedence(char x){
    switch(x){
        case '+':
        return 1;
        case '-':
        return 1;
        case '*':
        return 2;
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}

int isright(char x){
    return x == '^';
}

int isop(char x){
    return x=='+' || x=='-' || x=='*' || x=='/' || x=='^';
}

void itp(char infix[], char postfix[]){
    int j=0;
    char ch;
    for(int i=0; infix[i]!='\0';i++){
        ch=infix[i];
        if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while(top!=-1 && peek()!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(isop(ch)){
            while(top != -1 && peek() != '(' &&
                 (precedence(ch) < precedence(peek()) ||
                 (precedence(ch) == precedence(peek()) && !isright(ch)))){
                    postfix[j++] = pop();
            }
            push(ch);
}

    }

    while(top!=-1){
        postfix[j++]=pop();
    }

    postfix[j]='\0';
}

int main(){
    char infix[N], postfix[N];
    printf("Enter expression: ");
    scanf("%s",infix);

    itp(infix,postfix);

    printf("%s",postfix);

    return 0;
}


