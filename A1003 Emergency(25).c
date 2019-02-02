#include<stdio.h>
#include<string.h>

#define INF 100000000
#define MAXN 510 

int vis[MAXN],d[MAXN],w[MAXN],G[MAXN][MAXN],weight[MAXN],num[MAXN]; 
//访问数组vis,距离d,边权w,图G

int N,M,C1,C2;//边数 路径数 起终点 

void init(){
    int i,j,u,v; 
    scanf("%d%d%d%d",&N,&M,&C1,&C2);//读取
    for(i=0;i<N;i++){
        scanf("%d",&weight[i]);
    }//读点权（救护车数量） 
    for(i=0;i<N;i++){
        vis[i]=0;
        d[i]=INF;
        w[i]=0;
        num[i]=0;
        for(j=0;j<N;j++){
            G[i][j]=INF;
        }
    }//初始化 
    for(i=0;i<M;i++){
        scanf("%d%d",&u,&v);
        scanf("%d",&G[u][v]);
        G[v][u]=G[u][v];//无向图 
    }
    return; 
}//初始化

void Dijkstra(int st){
    int i,j,MIN,u,v; 
    num[st]=1;//起点到起点至少一条路
    d[st]=0;//到自己距离为0
    w[st]=weight[st];//点权为自己
    for(i=0;i<N;i++){
        u=-1;//
        MIN=INF;
        for(j=0;j<N;j++){
            if((vis[j]==0)&&(d[j]<MIN)){
                u=j;
                MIN=d[u];
            }//寻找未被访问过的最小d 
        }
        if(u==-1){
            return;
        }//未找到联通结点退出
        vis[u]=1;//访问u
        for(v=0;v<N;v++){
            if(vis[v]==0&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){//发现更短路径
                    d[v]=d[u]+G[u][v];//更新距离
                    w[v]=w[u]+weight[v];//更新路径点权和
                    num[v]=num[u];//到达v的最短路径数与到达u的最短路径数相同
                }else if(d[u]+G[u][v]==d[v]){//发现新的最短路径
                    w[v]=(w[v]>w[u]+weight[v]?w[v]:w[u]+weight[v]);//更新最大路径点权和
                    num[v]+=num[u];//最大最短路径数相加
                }
            }
        }
        if(u==C2){
            break;
        } //到达终点，退出 
    }
}
 
int main(){
    init();
    Dijkstra(C1);
    printf("%d %d\n",num[C2],w[C2]);
    return 0;
}
