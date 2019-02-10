#include<cstdio>
#define maxn 100

int in[maxn],post[maxn],N,seq;
int temp[maxn],leveln;

struct Node{
    int data;
    Node *lchild,*rchild;
};

void Init(){
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&in[i]);
    }
    for(i=0;i<N;i++){
        scanf("%d",&post[i]);
    }
}

Node* newNode(int v){
    Node* root=new(Node);
    root->data=v;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}

Node* Create(int inL,int inR,int postL,int postR){
    Node* root;
    int k,numL=0;
    if(inL>inR){
        return NULL;
    }
    root=newNode(post[postR]);
    for(k=inL;k<=inR;k++){
        if(in[k]==post[postR]){
            break;
        }
        numL++;
    }
    root->lchild=Create(inL,k-1,postL,postL+numL-1);
    root->rchild=Create(k+1,inR,postL+numL,postR-1);
    return root;
}

void Print(){
    int i;
    for(i=0;i<leveln;i++){
        printf("%d",temp[i]);
        seq++;
        if(seq<N){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

void Reverse(int n){
    int left=0,right=n-1,t;
    while(left<right){
        t=temp[left];
        temp[left]=temp[right];
        temp[right]=t;
        left++;
        right--;
    }
}

void LayerOrder(Node* root){
    Node *Queue[maxn];
    Node *now;
    int level=0;
    int front=0,rear=0;
    Queue[rear++]=root;
    Queue[rear++]=NULL;
    while(front<rear){
        now=Queue[front++];
        if(now==NULL){
            level++;
            if(level%2){
                Reverse(leveln);
            }
            Print();
            leveln=0;
            if(front==rear){
                break;
            }
            Queue[rear++]=NULL;
        }else{
            temp[leveln++]=now->data;
            if(now->lchild!=NULL){
                Queue[rear++]=now->lchild;
            }
            if(now->rchild!=NULL){
                Queue[rear++]=now->rchild;
            }
        }
    }
}

int main(){
    Node* root=NULL;
    Init();
    root=Create(0,N-1,0,N-1);
    LayerOrder(root);
    return 0;
}
