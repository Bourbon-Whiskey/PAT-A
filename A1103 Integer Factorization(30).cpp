#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> vec,temp,ans;
int N,K,P,maxsum=-1;

void Init(){
    int i=1,num=0;
    scanf("%d%d%d",&N,&K,&P);
    while(num<=N){
        vec.push_back(num);
        num=pow(i,P);
        i++; 
    }
    temp.resize(K);
}

void DFS(int current,int sum,int depth,int facsum){
    int i;
    if(sum>N){
        return;
    }//超过范围，剪枝
    if(depth==K){
        if(sum==N&&facsum>maxsum){
            ans=temp;
            maxsum=facsum;
        }
        return;
    }
    for(i=current;i>0;i--){
        if(sum+vec[i]<=N){
            temp[depth]=i;
            DFS(i,sum+vec[i],depth+1,facsum+i);
        }
    }
}

void Print(){
    int i;
    if(maxsum<0){
        printf("Impossible\n");
    }else{
        printf("%d = ",N);
        for(i=0;i<K;i++){
            printf("%d^%d",ans[i],P);
            if(i<K-1){
                printf(" + ");
            }else{
                printf("\n");
            }
        }
    }
}

int main(){
    Init();
    DFS(vec.size()-1,0,0,0);
    Print();
    return 0;
}
