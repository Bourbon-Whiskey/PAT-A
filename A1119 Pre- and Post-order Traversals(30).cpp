#include<cstdio>
#define maxn 35
int pre[maxn],post[maxn],in[maxn];
int flag,N,seq;

struct Node{
    int data;
    struct Node *lchild,*rchild;
};



Node* Create(int preL,int preR,int postL,int postR){
    Node* root;
    int k;
    int num2=preR-preL,num1=0;
    if(preL>preR){
        return NULL;
    }
    root=new(Node);
    root->data=pre[preL];
    if(preL==preR){
        root->lchild=NULL;
        root->rchild=NULL;
        return root;
    }
    for(k=postL;k<=postR;k++){
        num1++;
        num2--;
        if(post[k]==pre[preL+1]){
            break;
        }
    }
    if(num1==0||num2==0){
        flag=1;
    }
    root->lchild=Create(preL+1,preL+num1,postL,postL+num1-1);
    root->rchild=Create(preL+num1+1,preR,postL+num1,postR-1);
    return root;
}

void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    InOrder(root->lchild);
    in[seq++]=root->data;
    InOrder(root->rchild);
}

void Print(){
    int i;
    if(flag){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    for(i=0;i<N;i++){
        printf("%d",in[i]);
        if(i<N-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

int main(){
    int i;
    Node* root=NULL;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&pre[i]);
    }
    for(i=0;i<N;i++){
        scanf("%d",&post[i]);
    }
    root=Create(0,N-1,0,N-1);
    InOrder(root);
    Print();
    return 0;
}
