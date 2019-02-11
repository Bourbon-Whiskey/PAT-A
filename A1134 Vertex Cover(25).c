#include<stdio.h>
#define maxn 10010

int N,M,K;
int E[maxn];
struct Node{
    int a,b;
}node[maxn];
void Init(){
    int i;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d%d",&node[i].a,&node[i].b);
    }
    scanf("%d",&K);
}
void Check(){
    int i,nv,a;
    for(i=0;i<N;i++){
        E[i]=0;
    }
    scanf("%d",&nv);
    while(nv--){
        scanf("%d",&a);
        E[a]=1;
    }
    for(i=0;i<M;i++){
        if(E[node[i].a]==0&&E[node[i].b]==0){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}

int main(){
    Init();
    while(K--){
        Check();
    }
    return 0;
}
