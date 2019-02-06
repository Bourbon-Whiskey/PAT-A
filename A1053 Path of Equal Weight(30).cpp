#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    vector<int> children;
}node[110];
int N,M,S;
int temp[110];

bool cmp(int i,int j){
    return node[i].data>node[j].data;
}

void DFS(int root,int depth,int sum){
    int i;
    temp[depth]=node[root].data;
    sum+=node[root].data;
    if(sum>S){
        return;
    }
    if(sum==S){
        if(node[root].children.size()!=0){
            return;
        }
        for(i=0;i<=depth;i++){
            printf("%d",temp[i]);
            if(i<depth){
                printf(" "); 
            }else{
                printf("\n");
            }
        }
        return;
    }
    for(i=0;i<node[root].children.size();i++){
        DFS(node[root].children[i],depth+1,sum);
    }
}

int main(){
    int i;
    int id,num,k;
    scanf("%d%d%d",&N,&M,&S);
    for(i=0;i<N;i++){
        scanf("%d",&node[i].data);
    }
    for(i=0;i<M;i++){
        scanf("%d%d",&id,&num);
        while(num--){
            scanf("%d",&k);
            node[id].children.push_back(k);
        }
        sort(node[id].children.begin(),node[id].children.end(),cmp);
    }
    DFS(0,0,0);
    return 0;
}
