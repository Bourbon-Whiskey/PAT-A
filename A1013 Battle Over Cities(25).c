#include<stdio.h>

#define MAXN 1010

char Graph[MAXN][MAXN];
int vis[MAXN];
int N,M,K;

void Init(){
    int i,j;
    int a,b;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            Graph[i][j]='0';
        }
    }
    scanf("%d%d",&M,&K);
    for(i=0;i<M;i++){
        scanf("%d%d",&a,&b);
        Graph[a][b]='1';
        Graph[b][a]='1';
    }
    return;
}

void DFS(int n){
    int i;
    vis[n]=1;
    for(i=1;i<=N;i++){
        if((Graph[n][i]=='1')&&(vis[i]==0)){
            DFS(i);
        }
    }
    return;
}

void check(int miss){
    int i,count=-1;
    for(i=1;i<=N;i++){
        vis[i]=0;
    }
    vis[miss]=1;
    for(i=1;i<=N;i++){
        if(vis[i]==0){
            count++;
            DFS(i);
        }
    }
    printf("%d\n",count);
    return;
}

int main(){
    int i;
    int temp;
    Init();
    for(i=0;i<K;i++){
        scanf("%d",&temp);
        check(temp);
    }
    return 0;
}
