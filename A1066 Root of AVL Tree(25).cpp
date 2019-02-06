#include<cstdio>
struct Node{
    int data;
    int height;
    Node *lchild,*rchild;
};

Node* NewNode(int v){
    Node* root=new Node;
    root->data=v;
    root->lchild=root->rchild=NULL;
    root->height=1;
    return root;
}

int GetHeight(Node *root){
    if(root==NULL){
        return 0;
    }else{
        return root->height;
    }
}

int GetBF(Node *root){
    return GetHeight(root->lchild)-GetHeight(root->rchild);
}

int max(int a,int b){
    return (a>b)?a:b;
}
void updateHeight(Node *root){
    root->height=max(GetHeight(root->lchild),GetHeight(root->rchild))+1;
}

void L(Node* &root){
    Node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
    return;
}

void R(Node* &root){
    Node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
    return;
}

void Insert(Node* &root,int v){
    if(root==NULL){
        root=NewNode(v);
        return;
    }
    if(v<root->data){
        Insert(root->lchild,v);
        updateHeight(root);
        if(GetBF(root)==2){
            if(GetBF(root->lchild)==1){
                R(root);
            }else if(GetBF(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        Insert(root->rchild,v);
        updateHeight(root);
        if(GetBF(root)==-2){
            if(GetBF(root->rchild)==-1){
                L(root);
            }else if(GetBF(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
    return;
}

int main(){
    int N,v;
    Node* root=NULL;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&v);
        Insert(root,v);
    }
    printf("%d\n",root->data);
    return 0;
}
