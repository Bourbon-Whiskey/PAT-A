#include<stdio.h>
struct Node{
    int lchild,rchild;
}node[30];

int flag=0;
int N,root,Max,isroot[30];

void Init(){
    int i,j,num;
    char a[3],b[3];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s%s",a,b);
        if(a[0]=='-'){
            node[i].lchild=-1;
        }else{
            j=0,num=0;
            while(a[j]!=0){
                num=num*10+a[j]-'0';
                j++;
            }
            node[i].lchild=num;
            isroot[num]=1;
        }
        if(b[0]=='-'){
            node[i].rchild=-1;
        }else{
            j=0,num=0;
            while(b[j]!=0){
                num=num*10+b[j]-'0';
                j++;
            }
            node[i].rchild=num;
            isroot[num]=1;
        }
    }
    for(i=0;i<N;i++){
        if(isroot[i]==0){
            root=i;
            break;
        }
    }
}

void PreOrder(int now,int seq){
    if(flag||now==-1){
        return;
    }
    if(seq>N){
        flag=1;
        return;
    }else if(seq==N){
        Max=now;
    }
    PreOrder(node[now].lchild,seq*2);
    PreOrder(node[now].rchild,seq*2+1);
}

int main(){
    Init();
    PreOrder(root,1);
    if(flag){
        printf("NO %d\n",root);
    }else{
        printf("YES %d\n",Max);
    }
}
