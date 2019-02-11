#include<cstdio>
#include<vector>
using namespace std;
#define maxn 10010

struct Way{
    int des;
    int line;
};

vector<Way> G[maxn];//地铁图
int vis[maxn];
int inq[15][maxn];//是否入队 
vector<Way> temp,trace;
int Change;
int depth,st,End;

int N,M,K;

void Init(){
    int i,a,b;
    Way tmp;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&M);
        M--;
        scanf("%d",&a);
        while(M--){
            scanf("%d",&b);
            tmp.line=i;
            tmp.des=b;
            G[a].push_back(tmp);
            tmp.des=a;
            G[b].push_back(tmp);
            a=b;
        }
    }
    scanf("%d",&K);
}

int BFS(int i){
    int Queue[2*maxn];
    int front=0,rear=0;
    int now,level=0;
    int j;
    Queue[rear++]=st;
    inq[i][st]=1;
    Queue[rear++]=-1;
    while(rear>front){
        now=Queue[front++];
        if(now==-1){
            level++;
            Queue[rear++]=-1;
            continue;
        }
        if(now==End){
            break;
        }
        for(j=0;j<G[now].size();j++){
            if(inq[i][G[now][j].des]==0){
                inq[i][G[now][j].des]=1;
                Queue[rear++]=G[now][j].des;
            }
        }
    }
    return level;
}

void DFS(int now,int dep){
    int i,c;
    vis[now]=1;
    if(dep==depth){
        if(now==End){
            c=0;
            for(i=1;i<temp.size();i++){
                if(temp[i-1].line!=temp[i].line){
                    c++;
                }
            }
            if(c<Change){
                Change=c;
                trace=temp;
            }
            vis[now]=0;
            return;
        }else{
            vis[now]=0;
            return;
        }
    }else{
        for(i=0;i<G[now].size();i++){
            if(vis[G[now][i].des]==0){
                temp[dep]=G[now][i];
                DFS(G[now][i].des,dep+1);
            }
        }
    }
    vis[now]=0;
}

void Print(){
    int begin=st,i=0;
    int cline=trace[0].line;
    while(1){
        if(trace[i].des==End){
            printf("Take Line#%d from %04d to %04d.\n",cline,begin,trace[i].des);
            break;
        }
        if(trace[i+1].line!=cline){
            printf("Take Line#%d from %04d to %04d.\n",cline,begin,trace[i].des);
            cline=trace[i+1].line;
            begin=trace[i].des;
        }
        i++;
    }
}

void Op(int i){
    scanf("%d%d",&st,&End);
    depth=BFS(i);
    printf("%d\n",depth);
    temp.clear();
    temp.resize(depth);
    Change=maxn;
    DFS(st,0);
    Print();
}

int main(){
    int i;
    Init();
    for(i=0;i<K;i++){
        Op(i);
    }
    return 0;
}
