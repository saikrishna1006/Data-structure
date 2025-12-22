#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(int data){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else{
         root->right=insert(root->right,data);
    }
    return root;
 }
void inorder(struct node * root){
    if(root==NULL)
      return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(struct node * root){
    if(root==NULL)
      return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node * root){
    if(root==NULL)
      return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}
void display(struct node* root){
         printf("BST elementd in inorder:");
         inorder(root);
         printf("\n");
}
int main(){
    struct node* root=NULL;
    int choice,data;
        printf("\n---BINARY SEARCH TREE---\n");
        printf("1.Insert into BST\n");
        printf("2.Inorder traversal\n");
        printf("3.Preorder traversal\n");
        printf("4.Postorder traversal\n");
        printf("5.Display BST\n");
        printf("6.Exit\n");
        while(1){
        printf("Enter choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to be inserted:");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            case 2:
                printf("Inorder travesral:");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder travesral:");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder traversal:");
                postorder(root);
                printf("\n");
                break;

            case 5:
                display(root);
                break;

            case 6:
               exit(0);

            default:
                printf("INVALID CHOICE\n");

        }
    }
    return 0;
}

