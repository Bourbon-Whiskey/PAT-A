#include<cstdio>
#include<vector>
using namespace std;

vector<int>Look,Say;

void Op(){
    int now=Look[0],i=0,num=0;
    int n[50],k=0;
    Say.clear();
    while(i<Look.size()){
        Say.push_back(now);
        while(i<Look.size()&&Look[i]==now){
            i++,num++;
        }
        k=0;
        while(num){
            n[k++]=num%10;
            num/=10;
        }
        while(k--){
            Say.push_back(n[k]);
        }
        if(i<Look.size()){
            now=Look[i];
            num=0;
        }
    }
    Look=Say;
}

int main(){
    int i,a,N;
    scanf("%d%d",&a,&N);
    Look.push_back(a);
    while(--N){
        Op();
    }
    for(i=0;i<Look.size();i++){
        printf("%d",Look[i]);
    }
    printf("\n");
    return 0;
}
