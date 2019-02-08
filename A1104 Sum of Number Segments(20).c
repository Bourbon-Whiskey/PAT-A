#include<stdio.h>

int main(){
    double temp,sum=0.0;
    int i,N;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%lf",&temp);
        sum+=temp*i*(N+1-i);
    }
    printf("%.2f\n",sum);
    return 0;
} 
