#include<stdio.h>
int main(){
    int N,a=1,ans=0;
    int left,now,right;
    scanf("%d",&N);
    while(N/a){
        left=N/(a*10);
        now=N/a%10;
        right=N%a;
        if(now==0){
            ans+=left*a;
        }else if(now==1){
            ans+=left*a+right+1;
        }else{
            ans+=(left+1)*a;
        }
        a*=10;
    }
    printf("%d\n",ans);
    return 0;
}
