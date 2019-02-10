#include<stdio.h>
#define maxn 210

int G[maxn][maxn],N,M,K;

void Init(){
    int a,b;
    scanf("%d%d",&N,&M);
    while(M--){
        scanf("%d%d",&a,&b);
        G[a][b]=1;
        G[b][a]=1;
    }
    scanf("%d",&K);
}

void Check(){
    int n,i;
    int seq[maxn],vis[maxn];
    scanf("%d",&n);
    for(i=0;i<maxn;i++){
        vis[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    if(n!=N+1||seq[0]!=seq[n-1]){
        printf("NO\n");
        return;
    }
    for(i=0;i<n-1;i++){
        if(vis[seq[i]]==1){
            break;
        }else{
            vis[seq[i]]=1;
        }
        if(G[seq[i]][seq[i+1]]==0){
            break;
        }
    }
    if(i==n-1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}

int main(){
    Init();
    while(K--){
        Check();
    }
    return 0;
}
