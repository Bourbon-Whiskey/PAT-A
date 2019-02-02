#include<stdio.h>
#define maxn 100010
int main(){
    int N,M;
    int a,b,c,sum;
    int i;
    int dis[maxn]={0};
    int end[maxn]={0,0};
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&dis[i]);//i-i+1
        end[i]=end[i-1]+dis[i-1];
    }
    sum=end[N]+dis[N];
    scanf("%d",&M);
    for(i=0;i<M;i++){
        scanf("%d%d",&a,&b);
        if(a>b){
            c=b;
            b=a;
            a=c;
        }
        c=end[b]-end[a];
        printf("%d\n",(sum-c)<c?(sum-c):c);
    }
    return 0;
} 
