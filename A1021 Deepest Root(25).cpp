#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 10010

int Deepest[maxn];
int numDeep,maxDeep=-1;

vector<int> Adj[maxn];
int father[maxn];
int isroot[maxn];
int isdeep[maxn];

int n;
int findFather(int x){
    int z,a;
    a=x;
    while(father[x]!=x){
        x=father[x];
    }
    while(a!=x){
        z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}

void Union(int a,int b){
    int fa,fb;
    fa=findFather(a);
    fb=findFather(b);
    if(fa!=fb){
        father[fa]=fb;
    }
}

void Init(){
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        father[i]=i;
        isroot[i]=0;
        isdeep[i]=0;
    }
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        Adj[a].push_back(b);
        Adj[b].push_back(a);
        Union(a,b);
    }
    return;
}

void DFS(int u,int depth,int pre){
    int i,v;
    if(depth>maxDeep){
        maxDeep=depth;
        numDeep=0;
        Deepest[numDeep++]=u;
    }else if(depth==maxDeep){
        Deepest[numDeep++]=u;
    }
    for(i=0;i<Adj[u].size();i++){
        v=Adj[u][i];
        if(v!=pre){
            DFS(v,depth+1,u);
        }
    }
    return;
}


int main(){
    int nnum=0,i; 
    Init();
    for(i=1;i<=n;i++){
        isroot[findFather(i)]=1;
    }
    for(i=1;i<=n;i++){
        nnum+=isroot[i];
    }
    if(nnum>1){
        printf("Error: %d components\n",nnum);
    }else{
        DFS(1,0,0);
        for(i=0;i<numDeep;i++){
            isdeep[Deepest[i]]=1;
        }
        DFS(Deepest[0],0,0);
        for(i=0;i<numDeep;i++){
            isdeep[Deepest[i]]=1;
        }
        for(i=1;i<=n;i++){
            if(isdeep[i]){
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
