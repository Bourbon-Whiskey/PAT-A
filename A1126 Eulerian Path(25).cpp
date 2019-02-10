#include<cstdio>
#include<vector>
using namespace std;
#define maxn 510

vector<int> Edge[maxn];
int N,M,num;
int vis[maxn];

void Init(){
    int a,b;
    scanf("%d%d",&N,&M);
    while(M--){
        scanf("%d%d",&a,&b);
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }
}

void DFS(int v){
    int i;
    vis[v]=1;
    num++;
    for(i=0;i<Edge[v].size();i++){
        if(vis[Edge[v][i]]==0){
            DFS(Edge[v][i]);
        }
    }
}

void Print(){
    int i,odd=0,temp;
    DFS(1);
    for(i=1;i<=N;i++){
        temp=Edge[i].size();
        if(temp%2){
            odd++;
        }
        printf("%d",temp);
        if(i==N){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    if(num==N&&odd==0){
        printf("Eulerian\n");
    }else if(num==N&&odd==2){
        printf("Semi-Eulerian\n");
    }else{
        printf("Non-Eulerian\n");
    }
}

int main(){
    Init();
    Print();
    return 0;
}
