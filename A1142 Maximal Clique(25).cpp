#include<cstdio>
#include<vector>
using namespace std;
#define maxn 210

int E[maxn][maxn];
vector<int> Adj[maxn];
vector<int> vis;
int Nv,Ne,M;

void Init(){
    int a,b;
    scanf("%d%d",&Nv,&Ne);
    while(Ne--){
        scanf("%d%d",&a,&b);
        E[a][b]=1;
        E[b][a]=1;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    scanf("%d",&M);
}

void Check(){
    int i,j,K,a,b;
    vector<int> seq;
    scanf("%d",&K);
    for(i=0;i<K;i++){
        scanf("%d",&a);
        seq.push_back(a);
    }
    for(i=0;i<K;i++){
        a=seq[i];
        for(j=i+1;j<K;j++){
            b=seq[j];
            if(E[a][b]==0){
                printf("Not a Clique\n");
                return;
            }
        }
    }
    vis.clear();
    vis.resize(Nv+1);
    for(i=0;i<seq.size();i++){
        a=seq[i];
        for(j=0;j<Adj[a].size();j++){
            vis[Adj[a][j]]++;
        }
    }
    for(i=0;i<seq.size();i++){
        vis[seq[i]]=0;
    }
    for(i=0;i<=Nv;i++){
        if(vis[i]==K){
            printf("Not Maximal\n");
            return;
        }
    }
    printf("Yes\n");
}

int main(){
    Init();
    while(M--){
        Check();
    }
    return 0;
}
