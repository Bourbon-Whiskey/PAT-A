#include<cstdio>
#include<vector>
using namespace std;
#define maxn 1010

int N,M,K;
int flag=1;
vector<int> In,Test;
vector<int> Out[maxn];

void Init(){
    int a,b;
    scanf("%d%d",&N,&M);
    In.resize(N+1);
    while(M--){
        scanf("%d%d",&a,&b);
        Out[a].push_back(b);
        In[b]++;
    }
    scanf("%d",&K);
}

void Check(int num){
    int j,i,a;
    vector<int> seq;
    for(i=0;i<N;i++){
        scanf("%d",&a);
        seq.push_back(a);
    }
    Test=In;
    for(i=0;i<N;i++){
        if(Test[seq[i]]==0){
            for(j=0;j<Out[seq[i]].size();j++){
                Test[Out[seq[i]][j]]--;
            }
        }else{
            if(flag){
                flag=0;
                printf("%d",num);
            }else{
                printf(" %d",num);
            }
            return;
        }
    }
}

int main(){
    int i;
    Init();
    for(i=0;i<K;i++){
        Check(i);
    }
    printf("\n");
    return 0;
}
