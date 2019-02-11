#include<cstdio>
#include<cmath>
int Max(int a,int b){
    return a>b?a:b;
}

int Abs(int a){
    return a>0?a:-a;
}

struct Node{
    int v;
    int Black;
    Node *lchild,*rchild;
};

void Insert(Node* &root,int v){
    if(root==NULL){
        root=new(Node);
        if(v>0){
            root->v=v;
            root->Black=1;
        }else{
            root->v=-v;
            root->Black=0;
        }
        root->lchild=NULL;
        root->rchild=NULL;
        return;
    }
    if(Abs(v)<root->v){
        Insert(root->lchild,v);
    }else{
        Insert(root->rchild,v);
    }
}

bool PreOrder(Node* root){
    if(root==NULL){
        return true;
    }
    if(root->Black==0){
        if(root->lchild!=NULL&&root->lchild->Black==0){
            return false;
        }
        if(root->rchild!=NULL&&root->rchild->Black==0){
            return false;
        }
    }
    return PreOrder(root->lchild)&&PreOrder(root->rchild);
}
int Getnum(Node* root){
    if(root==NULL){
        return 0;
    }
    int lnum=Getnum(root->lchild);
    int rnum=Getnum(root->rchild);
    return Max(lnum,rnum)+root->Black;
}

bool Check(Node* root){
    bool tmp;
    if(root==NULL){
        return true;
    }
    int l=Getnum(root->lchild);
    int r=Getnum(root->rchild);
    if(l==r){
        tmp=Check(root->lchild)&&Check(root->rchild);
        return tmp;
    }else{
        return false;
    }
}

int main(){
    int K,N,a;
    Node* root;
    scanf("%d",&K);
    while(K--){
        root=NULL;
        scanf("%d",&N);
        while(N--){
            scanf("%d",&a);
            Insert(root,a);
        }
        if(root->Black&&PreOrder(root)&&Check(root)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

