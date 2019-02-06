#include<stdio.h>
#include<string.h>
#define maxn 1050
#define INF 100000000
struct Node{
    int v;
    int d;
}Adj[maxn][maxn];
int Num[maxn];
int vis[maxn];
int d[maxn];
double sum[maxn];
int dmin[maxn]={INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF};
int Impossible[maxn];//为1时不可达 

int N,M,P,K,Dm;

void Init(){
    char s[2][7];
    int p[2],Dist;
    int i,j;
    scanf("%d%d%d%d",&N,&M,&K,&Dm);
    P=N+M;//总结点数，前N为房 
    for(i=1;i<=P;i++){
        Num[i]=0;
    } 
    while(K--){
        scanf("%s %s %d",&s[0],&s[1],&Dist);
        for(i=0;i<2;i++){
            p[i]=0;
            for(j=0;j<7;j++){
                if(s[i][j]=='G'){
                    continue;
                }else if(s[i][j]==0){
                    break;
                }else{
                    p[i]=p[i]*10+s[i][j]-'0';
                }
            }
            if(s[i][0]=='G'){
                p[i]+=N;//加油站从N+1开始编号 
            }
        }
        Adj[p[0]][Num[p[0]]].v=p[1];
        Adj[p[0]][Num[p[0]]].d=Dist;
        Num[p[0]]++;
        Adj[p[1]][Num[p[1]]].v=p[0];
        Adj[p[1]][Num[p[1]]].d=Dist;
        Num[p[1]]++;
    }
}

void Dijkstra(int S){
    int i,j,u,v,min,k;
    for(i=1;i<=P;i++){
        vis[i]=0;
        d[i]=INF;
    }
    d[S]=0;
    k=S-N;
    //初始化
    for(i=1;i<=P;i++){
        u=0,min=INF;
        for(j=1;j<=P;j++){
            if(vis[j]==0&&d[j]<min){
                u=j;
                min=d[u];
            }
        }
        if(u==0){
            Impossible[k]=1;
            return;
        }
        vis[u]=1;
        if(u>0&&u<=N){
            if(d[u]>Dm){
                Impossible[k]=1;
                return;
            }
            if(d[u]<dmin[k]){
                dmin[k]=d[u];
            }
            sum[k]+=d[u];
        }
        for(j=0;j<Num[u];j++){
            v=Adj[u][j].v;
            if(vis[v]==0&&d[v]>d[u]+Adj[u][j].d){
                d[v]=d[u]+Adj[u][j].d;
            }
        }
    }
    return;
}

int main(){
    int i;
    int u,min;
    Init();
    for(i=1;i<=M;i++){
        Dijkstra(i+N);
        if(Impossible[i]){
            sum[i]=INF;
            continue;
        }else{
            sum[i]/=(N*1.0);
        }
    }
    sum[0]=INF;
    u=0;
    min=-1;
    for(i=1;i<=M;i++){
        if(Impossible[i]==0&&dmin[i]>min){
            u=i;
            min=dmin[u];
        }else if(Impossible[i]==0&&dmin[i]==min){
            if(sum[i]<sum[u]){
                u=i;
            }
        }
    }
    if(u==0){
        printf("No Solution\n");
    }else{
        printf("G%d\n%.1f %.1f\n",u,1.0*dmin[u],sum[u]);
    }
    return 0;
}
