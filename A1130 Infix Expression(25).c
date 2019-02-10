#include<stdio.h>
#define maxn 30

struct Node{
    int lchild,rchild;
    char data[15];
    int isop;
}node[maxn];

int N,isroot[maxn];

void InOrder(int root){
    if(root==-1){
        return;
    }
    if(node[node[root].lchild].isop){
        printf("(");
        InOrder(node[root].lchild);
        printf(")");
    }else{
        InOrder(node[root].lchild);
    }
    printf("%s",node[root].data);
    if(node[node[root].rchild].isop){
        printf("(");
        InOrder(node[root].rchild);
        printf(")");
    }else{
        InOrder(node[root].rchild);
    }
}


int main(){
    int i,root;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%s",node[i].data);
        scanf("%d%d",&node[i].lchild,&node[i].rchild);
        if(node[i].rchild!=-1){
            node[i].isop=1;
        }else{
            node[i].isop=0;
        }
        if(node[i].lchild!=-1){
            isroot[node[i].lchild]=1;
        }
        if(node[i].rchild!=-1){
            isroot[node[i].rchild]=1;
        }
    }
    for(root=1;root<N;root++){
        if(isroot[root]==0){
            break;
        }
    }
    InOrder(root);
    printf("\n");
    return 0;
}
