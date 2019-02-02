#include<stdio.h>
#include<math.h>

#define err 1E-7
#define MAXN 1005

struct POLY{
    int K;
    double cof[MAXN];
    int exp[MAXN];
}a,b;

int main(){
    int i,j,num=0,max;
    double cof,res[2*MAXN];
    int exp;
    scanf("%d",&a.K);
    for(i=0;i<a.K;i++){
        scanf("%d%lf",&a.exp[i],&a.cof[i]);
    }
    scanf("%d",&b.K);
    for(i=0;i<b.K;i++){
        scanf("%d%lf",&b.exp[i],&b.cof[i]);
    }
    max=a.exp[0]+b.exp[0];
    for(i=0;i<=max;i++){
        res[i]=0.0;
    }
    for(i=0;i<a.K;i++){
        for(j=0;j<b.K;j++){
            exp=a.exp[i]+b.exp[j];
            cof=a.cof[i]*b.cof[j];
            if(fabs(res[exp])<err){
                res[exp]=cof;
                num++;
            }else{
                res[exp]+=cof;
                if(fabs(res[exp])<err){
                    num--;
                }
            }
        } 
    }
    printf("%d ",num);
    for(i=max;i>=0;i--){
        if(fabs(res[i])>err){
            printf("%d %.1lf",i,res[i]);
            num--;
            if(num>0){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    return 0;
}
