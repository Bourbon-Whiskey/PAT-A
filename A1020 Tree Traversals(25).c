#include<stdio.h>
#include<stdlib.h>
#define maxn 35

typedef struct TreeNode{
    int data;
    struct TreeNode *lchild,*rchild;
}Node;

int post[maxn],in[maxn],N;

void Init(){
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&post[i]);
    }
    for(i=0;i<N;i++){
        scanf("%d",&in[i]);
    }
}

Node* Create(postL,postR,inL,inR){
    int numL,k=inL;
    if(postL>postR){
        return NULL;
    }
    Node* root=(Node*)malloc(sizeof(Node));
    root->data=post[postR];
    root->lchild=NULL;
    root->rchild=NULL;
    while(in[k]!=root->data){
        k++;
    }
    numL=k-inL;
    root->lchild=Create(postL,postL+numL-1,inL,k-1);
    root->rchild=Create(postL+numL,postR-1,k+1,inR);
    return root;
}

void Layer(Node* root){
    Node *Queue[maxn],*T;
    int front=0,rear=0,k=0;
    Queue[rear++]=root;
    while(front<rear){
        T=Queue[front++];
        printf("%d",T->data);
        if(++k==N){
            printf("\n");
        }else{
            printf(" ");
        }
        if(T->lchild){
            Queue[rear++]=T->lchild;
        }
        if(T->rchild){
            Queue[rear++]=T->rchild;
        }
    }
    return;
}

int main(){
    Node* root=NULL;
    Init();
    root=Create(0,N-1,0,N-1);
    Layer(root);
    return 0;
}
