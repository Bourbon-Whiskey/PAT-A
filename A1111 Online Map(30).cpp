#include<cstdio>
#include<vector>
using namespace std;
#define maxn 510
#define INF 1000000000

int N,M,sourse,destination;
int D[maxn],T[maxn],T1[maxn],Nnum[maxn];
int vis[maxn];
int preD[maxn],preT[maxn];
vector<int> TD,TT;

struct Node{
    int v;
    int l;
    int t;
};

vector<Node> G[maxn];

void Init(){
    int i;
    int V1,V2,flag,l,t;
    Node temp;
    scanf("%d%d",&N,&M);
    for(i=0;i<maxn;i++){
        D[i]=INF;
        T[i]=INF;
        T1[i]=INF;
        Nnum[i]=INF;
    }
    for(i=0;i<M;i++){
        scanf("%d%d%d%d%d",&V1,&V2,&flag,&l,&t);
        temp.v=V2;
        temp.l=l;
        temp.t=t;
        G[V1].push_back(temp);
        if(flag!=1){
            temp.v=V1;
            temp.l=l;
            temp.t=t;
            G[V2].push_back(temp);
        } 
    }
    scanf("%d%d",&sourse,&destination);
}

void DDFS(int now){
    TD.push_back(now);
    if(now==sourse){
        return;
    }
    DDFS(preD[now]);
}

void DDijkstra(){
    int i,j;
    int u,Min;
    Node temp;
    for(i=0;i<N;i++){
        vis[i]=0;
    }
    D[sourse]=0;
    T1[sourse]=0;
    for(i=0;i<N;i++){
        u=-1,Min=INF;
        for(j=0;j<N;j++){
            if(vis[j]==0&&D[j]<Min){
                u=j;
                Min=D[u];
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(j=0;j<G[u].size();j++){
            temp=G[u][j];
            if(vis[temp.v]==0){
                if(D[temp.v]>D[u]+temp.l){
                    D[temp.v]=D[u]+temp.l;
                    preD[temp.v]=u;
                    T1[temp.v]=T1[u]+temp.t;
                }else if(D[temp.v]==D[u]+temp.l&&T1[temp.v]>T1[u]+temp.t){
                    preD[temp.v]=u;
                    T1[temp.v]=T1[u]+temp.t;
                }
            }
            
        }
        if(u==destination){
            break;
        }
    }
    DDFS(destination);
}

void TDFS(int now){
    TT.push_back(now);
    if(now==sourse){
        return;
    }
    TDFS(preT[now]);
}

void TDijkstra(){
    int i,j;
    int u,Min;
    Node temp;
    for(i=0;i<N;i++){
        vis[i]=0;
    }
    T[sourse]=0;
    Nnum[sourse]=0;
    for(i=0;i<N;i++){
        u=-1,Min=INF;
        for(j=0;j<N;j++){
            if(vis[j]==0&&T[j]<Min){
                u=j;
                Min=T[u];
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(j=0;j<G[u].size();j++){
            temp=G[u][j];
            if(vis[temp.v]==0){
                if(T[temp.v]>T[u]+temp.t){
                    T[temp.v]=T[u]+temp.t;
                    preT[temp.v]=u;
                    Nnum[temp.v]=Nnum[u]+1;
                }else if(T[temp.v]==T[u]+temp.t&&Nnum[temp.v]>Nnum[u]+1){
                    preT[temp.v]=u;
                    Nnum[temp.v]=Nnum[u]+1;
                }
            }
            
        }
        if(u==destination){
            break;
        }
    }
    TDFS(destination);
}

void Print(){
    int i;
    if(TT==TD){
        printf("Distance = %d; Time = %d: ",D[destination],T[destination]);
        i=TD.size()-1;
        while(i>0){
            printf("%d -> ",TD[i]);
            i--;
        }
        printf("%d\n",destination);
    }else{
        printf("Distance = %d: ",D[destination]);
        i=TD.size()-1;;
        while(i>0){
            printf("%d -> ",TD[i]);
            i--;
        }
        printf("%d\n",destination);
        printf("Time = %d: ",T[destination]);
        i=TT.size()-1;;
        while(i>0){
            printf("%d -> ",TT[i]);
            i--;
        }
        printf("%d\n",destination);
    }
}

int main(){
    Init();
    DDijkstra();
    TDijkstra();
    Print();
    return 0;
}
