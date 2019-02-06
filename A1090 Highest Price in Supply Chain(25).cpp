#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define maxn 100010

double P,r;
int N,root;
vector<int> children[maxn];

int maxdepth,count;

void Init(){
    int i,a;
    scanf("%d%lf%lf",&N,&P,&r);
    r=r/100.0+1.0;
    for(i=0;i<N;i++){
        scanf("%d",&a);
        if(a<0){
            root=i;
        }else{
            children[a].push_back(i);
        }
    }
    maxdepth=-1;
}

void DFS(int r,int depth){
    int i;
    if(depth>maxdepth){
        maxdepth=depth;
        count=1;
    }else if(depth==maxdepth){
        count++;
    }
    for(i=0;i<children[r].size();i++){
        DFS(children[r][i],depth+1);
    } 
}

int main(){
    Init();
    DFS(root,0);
    r=pow(r,maxdepth);
    printf("%.2f %d\n",P*r,count);
    return 0; 
} 
