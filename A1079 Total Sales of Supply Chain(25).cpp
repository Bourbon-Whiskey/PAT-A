#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

#define maxn 100010

int N;
double P,r,sum=0.0;

struct Shop{
    int isLeaf;
    int store;
    vector<int> children;
}shop[maxn];

void Init(){
    int i,num,a;
    scanf("%d%lf%lf",&N,&P,&r);
    r=1.0+r/100;
    for(i=0;i<N;i++){
        scanf("%d",&num);
        if(num==0){
            shop[i].isLeaf=1;
            scanf("%d",&shop[i].store);
        }else{
            shop[i].isLeaf=0;
            while(num--){
                scanf("%d",&a);
                shop[i].children.push_back(a);
            }
        }
    }
}

void DFS(int u,int depth){
    int i;
    if(shop[u].isLeaf){
        sum+=shop[u].store*pow(r,depth);//r^depth
        return;
    }else{
        for(i=0;i<shop[u].children.size();i++){
            DFS(shop[u].children[i],depth+1);
        }
    }
}

int main(){
    Init();
    DFS(0,0);
    printf("%.1lf\n",sum*P);
    return 0;
}
