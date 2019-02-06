#include<cstdio>
#include<algorithm>
#define maxn 1010
using namespace std;

struct Cake{
    double price,amounts,ave;
}c[maxn];

bool cmp(Cake a,Cake b){
    return a.ave>b.ave;
}

int main(){
    int N,i;
    double D,sum=0.0;
    scanf("%d%lf",&N,&D);
    for(i=0;i<N;i++){
        scanf("%lf",&c[i].amounts);
    }
    for(i=0;i<N;i++){
        scanf("%lf",&c[i].price);
        c[i].ave=c[i].price/c[i].amounts;
    }
    sort(c,c+N,cmp);
    for(i=0;i<N;i++){
        if(D>=c[i].amounts){
            sum+=c[i].price;
            D-=c[i].amounts;
        }else{
            sum+=D*c[i].ave;
            break;
        }
    }
    printf("%.2f\n",sum);
    return 0;
}
