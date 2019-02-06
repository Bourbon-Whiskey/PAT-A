#include<cstdio>
#include<set>
using namespace std;

set<int> St[60];

void check(int a,int b){
    int c=St[b].size(),s=0;
    set<int>::iterator it;
    for(it=St[a].begin();it!=St[a].end();it++){
        if(St[b].find(*it)!=St[b].end()){
            s++;
        }else{
            c++;
        }
    }
    printf("%.1lf%\n",(100.0*s)/c);
}

int main(){
    int N,M,K;
    int v,a,b;
    int i,j;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&M);
        for(j=0;j<M;j++){
            scanf("%d",&v);
            St[i].insert(v);
        }
    }
    scanf("%d",&K);
    for(i=0;i<K;i++){
        scanf("%d%d",&a,&b);
        check(a,b);
    }
    return 0;
}
