#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 110

struct Node{
    int lchild,rchild,data;
}BST[maxn];

int N,num[maxn],seq=0;

void Init(){
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%d",&BST[i].lchild,&BST[i].rchild);
    }
    for(i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+N);
}

void InOrder(int root){
    if(root==-1){
        return;
    }
    InOrder(BST[root].lchild);
    BST[root].data=num[seq++];
    InOrder(BST[root].rchild);
}

void LayerOrder(){
    int Queue[maxn];
    int top,front=0,rear=0;
    Queue[rear++]=0;
    while(rear>front){
        top=Queue[front++];
        printf("%d",BST[top].data);
        N--;
        if(N>0){
            printf(" ");
        }else{
            printf("\n");
        }
        if(BST[top].lchild!=-1){
            Queue[rear++]=BST[top].lchild;
        }
        if(BST[top].rchild!=-1){
            Queue[rear++]=BST[top].rchild;
        }
    }
}

int main(){
    Init();
    InOrder(0);
    LayerOrder();
    return 0;
}
