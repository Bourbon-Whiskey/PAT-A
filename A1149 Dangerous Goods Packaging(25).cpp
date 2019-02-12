#include<cstdio>
#include<vector>
using namespace std;
#define maxn 100010
int N,M;
vector<int> Im[maxn];
vector<int> req;
vector<int> vis;

void Init(){
    int a,b;
    scanf("%d%d",&N,&M);
    while(N--){
        scanf("%d%d",&a,&b);
        Im[a].push_back(b);
        Im[b].push_back(a);
    }
}

void check(){
    int K,a,i,j;
    vector<int> temp;
    req.clear();
    vis.clear();
    vis.resize(maxn);
    scanf("%d",&K);
    while(K--){
        scanf("%d",&a);
        vis[a]=1;
        req.push_back(a);
    }
    for(i=0;i<req.size();i++){
        temp=Im[req[i]];
        for(j=0;j<temp.size();j++){
            if(vis[temp[j]]==1){
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int main(){
    Init();
    while(M--){
        check();
    }
    return 0;
}
