#include<stdio.h>
int graph[20][20],visited[20],n;
void DFS(int start){
    int stack[20],top=-1;
    stack[++top]=start;
    while(top!=-1){
        int node=stack[top--];
        printf("%d \n",node);
        if(!visited[node]){
            visited[node]=1;
            for(int i=0;i<n;i++){
                if(graph[node][i]==1 && !visited[i]){
                    stack[++top]=i;
                }
            }
        }
    }
}
int main(){
    int start;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    printf("Enter the starting index:");
    scanf("%d",&start);
    printf("DFS traversal:\n");
    DFS(start);
   int connected=1;
   for(int i=0;i<n;i++){
       if(!visited[i]){
          connected=0;
          break;
   }
}
if(connected){
    printf("Graph is connected\n");
}
else{
    printf("Graph is not connected\n");
}
}
