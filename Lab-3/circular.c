#include <stdio.h>
#define N 5
int Q[N];
int f=-1,r=-1;

void insert(int x){
    if(f==-1&&r==-1){
        f=r=0;
        Q[r] = x;
    }
    else if(f==(r+1)%N){
        printf("Queue is Full");
    }
    else{
        r = (r+1)%N;
        Q[r] = x;
    }
}

void delete(){
    if(f==-1&&r==-1){
        printf("Queue is empty");
    }
    else if(f==r){
        printf("Value deleted : %d\n",Q[f]);
        f = r = -1;
    }
    else{
        printf("Value deleted : %d\n",Q[f]);
        f = (f+1)%N;
    }
}

void display(){
    if(f==-1&&r==-1){
        printf("Queue is empty");
    }
    else{
        printf("Queue contains:\n");
        int i = f;
        while (1) {
            printf("%d ", Q[i]);
            if (i == r)
                break;
            i = (i + 1) % N;
            }
        }
}


int main(){
    int value,choice;
    printf("\n---- CIRCULAR QUEUE  ----\n");
    printf("1.INSERT\n 2.DELETE \n 3.DISPLAY \n 4.EXIT");
    while(1){
        printf("\n Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter your value: ");
            scanf("%d",&value);
            insert(value);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            return 0;
            default :
            printf("ïnvalid statement");
            break;}
}
}
