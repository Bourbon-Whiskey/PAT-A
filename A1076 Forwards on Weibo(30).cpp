#include<cstdio>
#include<vector>
using namespace std;

#define maxn 1010

vector<int> Adj[maxn]; 
int inq[maxn];
int N,L;

void Init(){
    int num,a,i;
    scanf("%d%d",&N,&L);
    for(i=1;i<=N;i++){
        scanf("%d",&num);
        while(num--){
            scanf("%d",&a);
            Adj[a].push_back(i);
        }
    }
}

int BFS(int s){
    int Queue[maxn*6];
    int front=0,rear=0;
    int now,level=0,cnt=-1,i;
    for(i=1;i<=N;i++){
        inq[i]=0;
    }
    Queue[rear++]=s;
    inq[s]=1;
    Queue[rear++]=-1;
    while(rear>front){
        now=Queue[front++];
        if(now==-1){
            Queue[rear++]=-1;
            level++;
            if(level<=L){
                continue;
            }else{
                break;
            }
        }
        cnt++;
        for(i=0;i<Adj[now].size();i++){
            if(inq[Adj[now][i]]==0){
                Queue[rear++]=Adj[now][i];
                inq[Adj[now][i]]=1;
            }
        }
    }
    return cnt;
}

int main(){
    int K,Query;
    Init();
    scanf("%d",&K);
    while(K--){
        scanf("%d",&Query);
        printf("%d\n",BFS(Query));
    }
    return 0;
}
