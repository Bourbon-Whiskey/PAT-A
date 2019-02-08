#include<stdio.h>

struct Node{
    int lchild,rchild;
}node[15];

int N,root,HashTable[15];

void Init(){
    int i;
    char a,b;
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++){
        scanf("%c %c",&a,&b);
        getchar();
        if(a=='-'){
            node[i].lchild=-1;
        }else{
            node[i].lchild=a-'0';
            HashTable[a-'0']=1;
        }
        if(b=='-'){
            node[i].rchild=-1;
        }else{
            node[i].rchild=b-'0';
            HashTable[b-'0']=1;
        }
    }
    for(i=0;i<N;i++){
        if(HashTable[i]==0){
            root=i;
            break;
        }
    }
}

void LayerOrder(){
    int Queue[15],rear=0,front=0;
    int top,num=N;
    Queue[rear++]=root;
    while(rear>front){
        top=Queue[front++];
        printf("%d",top);
        if(--num){
            printf(" ");
        }
        if(node[top].rchild!=-1){
            Queue[rear++]=node[top].rchild;
        }
        if(node[top].lchild!=-1){
            Queue[rear++]=node[top].lchild;
        }
    }
    printf("\n");
}

void InOrder(int r){
    if(r==-1){
        return;
    }
    InOrder(node[r].rchild);
    printf("%d",r);
    if(--N){
        printf(" ");
    }
    InOrder(node[r].lchild);
}

int main(){
    Init();
    LayerOrder();
    InOrder(root);
    printf("\n");
    return 0;
}
