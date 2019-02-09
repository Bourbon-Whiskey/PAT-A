#include<cstdio>
#define maxn 1010
int level[maxn],maxheight=-1;

struct Node{
    int data;
    Node *lchild,*rchild;
};

Node* Create(int v){
    Node* root=new(Node);
    root->data=v;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}

void Insert(Node* &root,int v){
    if(root==NULL){
        root=Create(v);
    }else{
        if(v>root->data){
            Insert(root->rchild,v);
        }else{
            Insert(root->lchild,v);
        }
    }
    return;
}

void PreOrder(Node* root,int depth){
    if(root==NULL){
        return;
    }
    level[depth]++;
    if(depth>maxheight){
        maxheight=depth;
    }
    PreOrder(root->lchild,depth+1);
    PreOrder(root->rchild,depth+1);
}

int main(){
    int N,a;
    Node* root=NULL;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&a);
        Insert(root,a);
    }
    PreOrder(root,0);
    printf("%d + %d = %d\n",level[maxheight],level[maxheight-1],level[maxheight]+level[maxheight-1]);
    return 0;
}
