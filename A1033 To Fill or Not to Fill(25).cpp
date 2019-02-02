#include<cstdio>
#include<algorithm>
#define maxn 510
#define INF 100000000
using namespace std;

struct St{
    double dis,price;
}Sat[maxn];

bool cmp(St a,St b){
    return a.dis<b.dis;
}

int N;
double C,D,Da;

int main(){
    int i,j,k;//k为当前站点 
    double remain=0,Max,fee,minprice,need;
    scanf("%lf%lf%lf%d",&C,&D,&Da,&N);
    for(i=0;i<N;i++){
        scanf("%lf%lf",&Sat[i].price,&Sat[i].dis);
    }
    Sat[N].dis=D;
    Sat[N].price=0.0;
    sort(Sat,Sat+N,cmp);
    if(Sat[0].dis!=0){
        printf("The maximum travel distance = 0.00\n");
    }else{
        k=0,fee=0.0,Max=C*Da,remain=0.0;
        while(k<N){
            i=-1,minprice=INF;
            for(j=k+1;j<=N&&Sat[j].dis-Sat[k].dis<=Max;j++){
                if(Sat[j].price<minprice){
                    i=j;
                    minprice=Sat[i].price;
                    if(minprice<Sat[k].price){
                        break;
                    }
                }
            }
            if(i==-1){
                break;
            }
            need=Sat[i].dis-Sat[k].dis;
            if(minprice<Sat[k].price){
                //只购买恰好的的油
                if(remain<need){
                    fee+=(need-remain)*Sat[k].price;
                    remain=0;
                }else{
                    remain-=need;
                }
            }else{
                fee+=(Max-remain)*Sat[k].price;
                remain=Max-need;
            }
            k=i;
        }
        if(k==N){
            printf("%.2lf\n",fee/Da);
        }else{
            printf("The maximum travel distance = %.2lf\n",Sat[k].dis+Max);
        } 
    }
    return 0;
}

