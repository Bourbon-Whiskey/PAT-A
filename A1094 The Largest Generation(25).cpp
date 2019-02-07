#include<cstdio>
#include<vector>
using namespace std;
#define maxn 110

int N,M;

vector<int> node[maxn];
vector<int> d[maxn];

void Init(){
    int i,j,k;
    int id,a;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d%d",&id,&k);
        for(j=0;j<k;j++){
            scanf("%d",&a);
            node[id].push_back(a);
        }
    }
}

void DFS(int id,int depth){
    int i;
    d[depth].push_back(id);
    for(i=0;i<node[id].size();i++){
        DFS(node[id][i],depth+1);
    }
    return;
}

int main(){
    int i,temp,u=-1,Max=-1;
    Init();
    DFS(1,1);
    for(i=1;i<maxn;i++){
        temp=d[i].size();
        if(temp>Max){
            u=i;
            Max=temp;
        }
    }
    printf("%d %d\n",Max,u);
    return 0;
}
