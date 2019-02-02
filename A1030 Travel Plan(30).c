#include<stdio.h>
#define maxn 510
#define INF 10000000

struct Node{
    int v;
    int dis;
    int cost;
};

struct Node Adj[maxn][maxn];//距离 
int num[maxn];//邻接表
int d[maxn];//距离 
int vis[maxn];//遍历数组 
int N,M,S,D;

int pre[maxn][maxn];//前置数组
int prenum[maxn];

int temp[maxn];
int shortest[maxn];
int mindepth,mincost=INF;

void Init(){
    int i;
    int a1,a2,a3,a4;
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for(i=0;i<N;i++){
        num[i]=0;
        prenum[i]=0;
        d[i]=INF;
        vis[i]=0;
    }
    for(i=0;i<M;i++){
        scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
        Adj[a1][num[a1]].v=a2;
        Adj[a1][num[a1]].dis=a3;
        Adj[a1][num[a1]++].cost=a4;
        Adj[a2][num[a2]].v=a1;
        Adj[a2][num[a2]].dis=a3;
        Adj[a2][num[a2]++].cost=a4;
    }
}

void Dijkstra(){
    int i,j;
    int u,v,min;
    d[S]=0;
    for(i=0;i<N;i++){
        u=-1;min=INF;
        for(j=0;j<N;j++){
            if(vis[j]==0&&d[j]<min){
                u=j;
                min=d[u];
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(j=0;j<num[u];j++){
            v=Adj[u][j].v;
            if(vis[v]==0){
                if(d[u]+Adj[u][j].dis<d[v]){
                    prenum[v]=0;
                    pre[v][prenum[v]++]=u;
                    d[v]=d[u]+Adj[u][j].dis;
                }else if(d[v]==d[u]+Adj[u][j].dis){
                    pre[v][prenum[v]++]=u;
                }
            }
        }
        if(u==D){
            break;
        }
    }
    return;
}

void DFS(int u,int depth,int cost){
    int i,j;
    int v,c;
    temp[depth]=u;
    if(u==S){
        if(cost<mincost){
            mindepth=depth;
            mincost=cost;
            for(j=0;j<=mindepth;j++){
                shortest[j]=temp[j];
            }
        }
        return;
    }else{
        for(i=0;i<prenum[u];i++){
            v=pre[u][i];
            for(j=0;j<num[u];j++){
                if(v==Adj[u][j].v){
                    break;
                }
            }
            c=Adj[u][j].cost;
            DFS(v,depth+1,cost+c);
        } 
    }
    return;
}

int main(){
    int i;
    Init();
    Dijkstra();
    DFS(D,0,0);
    for(i=mindepth;i>=0;i--){
        printf("%d ",shortest[i]);
    }
    printf("%d %d\n",d[D],mincost);
    return 0;
}
