#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    int Height;
    Node *lchild,*rchild;
};
struct P{
    int num;
    int seq;
};

bool cmp(P a,P b){
    return a.seq<b.seq;
}
int N,flag;
vector<P> res;

int GetH(Node* root){
    if(root==NULL){
        return 0;
    }else{
        return root->Height;
    }
}

void updateH(Node* root){
    root->Height=max(GetH(root->lchild),GetH(root->rchild))+1;
}

int GetBF(Node* root){
    return GetH(root->lchild)-GetH(root->rchild); 
}

Node* newNode(int v){
    Node* root=new(Node);
    root->lchild=NULL;
    root->rchild=NULL;
    root->Height=1;
    root->data=v;
    return root;
}

void L(Node* &root){
    Node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateH(root);
    updateH(temp);
    root=temp;
}

void R(Node* &root){
    Node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateH(root);
    updateH(temp);
    root=temp;
}

void Insert(Node* &root,int v){
    if(root==NULL){
        root=newNode(v);
        return;
    }
    if(v<root->data){
        Insert(root->lchild,v);
        updateH(root);
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
        updateH(root);
        if(GetBF(root)==-2){
            if(GetBF(root->rchild)==-1){
                L(root);
            }else if(GetBF(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

void PreOrder(Node* root,int seq){
    P temp;
    if(root==NULL){
        return;
    }
    if(seq>N){
        flag=1;
    }
    temp.num=root->data;
    temp.seq=seq;
    res.push_back(temp);
    PreOrder(root->lchild,seq*2);
    PreOrder(root->rchild,seq*2+1);
}

int main(){
    int i,a;
    Node* root=NULL;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        Insert(root,a);
    }
    PreOrder(root,1);
    sort(res.begin(),res.end(),cmp);
    for(i=0;i<N;i++){
        printf("%d",res[i].num);
        if(i<N-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    if(flag){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}
