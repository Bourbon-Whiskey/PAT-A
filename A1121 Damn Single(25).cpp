#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 100010

int N,M,vis[maxn],couple[maxn],vivid[maxn],seq[maxn],num;
vector<int> Single;

void Init(){
    int a,b;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d",&a,&b);
        couple[a]=b;
        couple[b]=a;
        vivid[a]=1;
        vivid[b]=1;
    }
    scanf("%d",&M);
    while(M--){
        scanf("%d",&a);
        vis[a]=1;
        seq[num++]=a;
    }
}

void Check(int v){
    if(vivid[v]==0){
        Single.push_back(v);
        return;
    }//单身
    if(vis[couple[v]]==0){
        Single.push_back(v);
        return;
    }//独身前来 
}

int main(){
    int i;
    Init();
    for(i=0;i<num;i++){
        Check(seq[i]);
    }
    sort(Single.begin(),Single.end());
    num=Single.size();
    printf("%d\n",num);
    for(i=0;i<num;i++){
        printf("%05d",Single[i]);
        if(i<num-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
} 
