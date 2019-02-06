#include<cstdio>
#include<vector>
using namespace std;

vector<int> pre,in,post;

struct Node{
    int data;
    Node *lchild,*rchild;
};

Node* NewNode(int v){
    Node *root=new(Node);
    root->data=v;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}

Node* Create(int PreL,int PreR,int InL,int InR){
    int k,numleft=0;
    if(PreL>PreR){
        return NULL;
    }
    Node* root=NewNode(pre[PreL]);
    for(k=InL;k<InR;k++){
        if(in[k]==pre[PreL]){
            break;
        }
        numleft++;
    }
    root->lchild=Create(PreL+1,PreL+numleft,InL,k-1);
    root->rchild=Create(PreL+numleft+1,PreR,k+1,InR);
    return root; 
}

void PostOrder(Node* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    post.push_back(root->data);
}

int main(){
    int N;
    int i,a;
    char s[6];
    int stack[35],top=0;
    scanf("%d",&N);
    while(in.size()<N){
        scanf("%s",&s);
        if(s[1]=='u'){
            scanf("%d",&a);
            pre.push_back(a);
            stack[top++]=a;
        }else{
            in.push_back(stack[--top]);
        }
    }
    Node* root=Create(0,N-1,0,N-1);
    PostOrder(root);
    for(i=0;i<N;i++){
        printf("%d",post[i]);
        if(i<N-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}
