#include<stdio.h>

#define maxn 510
#define INF 100000000

int G[maxn][maxn];//邻接矩阵
int d[maxn];//距离数组
int vis[maxn];//访问数组 
int needs[maxn];//需求的数量
int C,N,S,M;//最大数量C，站点数N,目标站点S，路数M
int temp[maxn]={0},path[maxn]={0};//临时路径,最短路径 
int mindis,mintake=INF,minremain=INF;//最小距离
int pre[maxn][maxn];
int prenum[maxn];

void Init(){
    int i,j;
    int a,b,v;
    scanf("%d%d%d%d",&C,&N,&S,&M);
    C=C/2;
    for(i=1;i<=N;i++){
        scanf("%d",&needs[i]);
        needs[i]=C-needs[i];
    }//初始化needs数组
    for(i=0;i<=N;i++){
        d[i]=INF;
        vis[i]=0;
        for(j=0;j<=N;j++){
            G[i][j]=INF;
        }
        G[i][i]=0;
    }
    for(i=0;i<M;i++){
        scanf("%d%d%d",&a,&b,&v);
        G[a][b]=G[b][a]=v;
    }
    return;
}

void Dijkstra(int end){
    int i,j;
    int u,min,v;
    d[0]=0;
    for(i=0;i<=N;i++){
        u=-1,min=INF;
        for(j=0;j<=N;j++){
            if(vis[j]==0&&d[j]<min){
                u=j;
                min=d[u];
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(v=0;v<=N;v++){
            if(vis[v]==0&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    prenum[v]=0;
                    pre[v][prenum[v]++]=u;
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v][prenum[v]++]=u;
                }
            }
        }
        if(u==end){
            mindis=d[end];
            return;
        }
    }
}

void DFS(int u,int depth){
    int i,j=0;
    int take,remain,v;
    temp[depth]=u;//记录临时路径 
    if(u==0){//到达边界 
        take=0,remain=0;
        for(i=depth-1;i>=0;i--){
            v=temp[i];
            if(remain>=needs[v]){//剩余数量可以满足 
                remain=remain-needs[v];//更新剩余数量 
            }else{//不够数 
                take+=needs[v]-remain;//不够数，remain清零，剩余部分打白条 
                remain=0;
            }
        } 
        if(take<mintake){
            mintake=take;//记录一路上打了多少白条
            minremain=remain;//记录带回数 
            for(i=depth;i>=0;i--){
                path[j++]=temp[i];//将temp记录于path 
            }
        }else if(take==mintake&&remain<minremain){//需带回数量更少 
            mintake=take;//记录一路上打了多少白条
            minremain=remain;//记录带回数 
            for(i=depth;i>=0;i--){
                path[j++]=temp[i];//将temp记录于path 
            }
        }
        return;
    }
    for(i=0;i<prenum[u];i++){
        v=pre[u][i];
        DFS(v,depth+1);
    }
}

int main(){
    int i;
    Init();
    Dijkstra(S);
    DFS(S,0);
    printf("%d 0",mintake);
    for(i=1;;i++){
        printf("->%d",path[i]);
        if(path[i]==S){
            break;
        }
    }
    printf(" %d\n",minremain);
    return 0;
}
