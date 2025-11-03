# include <stdio.h>
# define N 5
int q[N];
int f = -1;
int r = -1;


void enque(int x){
    if(r==N-1)
    {
        printf("Queue overflow\n");
    }
    else if(f==-1 && r==-1)
    {
        f = r =0;
        q[r]=x;
    }
    else
    {
        r++;
        q[r] = x;
    }
}
void deque(){
    if(f==-1 && r==-1){
        printf("Queue is empty\n");
    }
    else if(f==r){
        f=r=-1;
    }
    else{
        printf("%d is deleted\n",q[f]);
        f++;
    }
}

void display(){
    if(f==-1 && r==-1){
        printf("Queue is empty\n");
    }
    else {
        printf("Ëlements of queue\n");
        for(int i=f;i<=r;i++){
            printf("%d\n",q[i]);
        }
    }
}
void peek(){
    if(f==-1 && r==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("%d\n",q[f]);
    }
}

void main(){
    int c;
    printf("Enter your choice\n1.Enque\n2,Deque\n3.Display\n4.Peek\n5.Exit\n");
    scanf("%d",&c);
    while(c!=5){
        switch(c){
            case 1 :  { int x;
                        printf("Enter a value\n");
                        scanf("%d",&x);
                        enque(x);
                        break;}

            case 2: deque();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            default : printf("Invalid entry\n");
                    break;
        }
        printf("Enter your choice\n");
        scanf("%d",&c);

    }
    printf("EXIT");
}
