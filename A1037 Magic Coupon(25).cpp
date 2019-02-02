#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;

bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    int NC,NP;
    int i,j;
    long long C[maxn],P[maxn],fee=0;
    scanf("%d",&NC);
    for(i=0;i<NC;i++){
        scanf("%lld",&C[i]);
    }
    sort(C,C+NC,cmp);
    scanf("%d",&NP);
    for(i=0;i<NP;i++){
        scanf("%lld",&P[i]);
    }
    sort(P,P+NP,cmp);
    i=0;
    while(C[i]>0&&P[i]>0){
        fee+=C[i]*P[i];
        i++;
    }
    i=NC-1;
    j=NP-1;
    while(C[i]<0&&P[j]<0){
        fee+=C[i]*P[j];
        i--;
        j--;
    }
    printf("%lld\n",fee);
    return 0;
} 
