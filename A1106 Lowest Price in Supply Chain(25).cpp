#include<cstdio>
#include<cmath>
#include<vector>
#define maxn 200010
using namespace std;

vector<int> children[maxn];
int N;
double P,r;

void Init(){
    int i,k,a;
    scanf("%d%lf%lf",&N,&P,&r);
    r=1.0+r/100;
    for(i=0;i<N;i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&a);
            children[i].push_back(a);
        }
    }
}

void BFS(){
    int Queue[maxn];
    int rear=0,front=0,top;
    int level=-1,count=0;
    int i;
    Queue[rear++]=0;
    Queue[rear++]=-1;//层尾标记
    while(rear>front){
        top=Queue[front++];
        if(top==-1){
            level++;
            if(count>0){
                break;
            }else{
                Queue[rear++]=-1;
            }
        }else if(children[top].size()==0){
            count++;
        }else{
            for(i=0;i<children[top].size();i++){
                Queue[rear++]=children[top][i];
            }
        }
    }
    r=pow(r,level);
    printf("%.4lf %d\n",P*r,count);
}

int main(){
    Init();
    BFS();
    return 0;
}
