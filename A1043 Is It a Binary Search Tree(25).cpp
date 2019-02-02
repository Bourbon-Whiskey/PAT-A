#include<cstdio>
#include<vector>
using namespace std;

vector<int> pre,post,Origin;

struct Node{
    int data;
    Node *lchild,*rchild;
};

void Insert(Node* &root,int v){
    if(root==NULL){
        root=new Node;
        root->data=v;
        root->lchild=NULL;
        root->rchild=NULL;
        return;
    }
    if(v<root->data){
        Insert(root->lchild,v);
    }else{
        Insert(root->rchild,v);
    }
    return;
}

void InsertM(Node* &root,int v){
    if(root==NULL){
        root=new Node;
        root->data=v;
        root->lchild=NULL;
        root->rchild=NULL;
        return;
    }
    if(v>=root->data){
        InsertM(root->lchild,v);
    }else{
        InsertM(root->rchild,v);
    }
    return;
}

void PreO(Node* root){
    if(root==NULL){
        return;
    }
    pre.push_back(root->data);
    PreO(root->lchild);
    PreO(root->rchild);
}

void PostO(Node* root){
    if(root==NULL){
        return;
    }
    PostO(root->lchild);
    PostO(root->rchild);
    post.push_back(root->data);
}

int main(){
    Node *root=NULL,*rootM=NULL;
    int N,i,a;
    scanf("%d",&N);
    Origin.clear();
    for(i=0;i<N;i++){
        scanf("%d",&a);
        Insert(root,a);
        Origin.push_back(a);
    }
    pre.clear();
    PreO(root);
    if(pre==Origin){
        printf("YES\n");
        post.clear();
        PostO(root);
        for(i=0;i<N;i++){
            printf("%d",post[i]);
            if(i<N-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }else{
        for(i=0;i<Origin.size();i++){
            InsertM(rootM,Origin[i]);
        }
        pre.clear();
        PreO(rootM);
        if(pre==Origin){
            printf("YES\n");
            post.clear();
            PostO(rootM);
            for(i=0;i<N;i++){
                printf("%d",post[i]);
                if(i<N-1){
                    printf(" ");
                }else{
                    printf("\n");
                }
            }
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
