#include<stdio.h>
int main(){
    long long a,b,c;
    int T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        printf("Case #%d: ",i);
        scanf("%lld%lld%lld",&a,&b,&c);
        if(b>c-a){
            printf("true");
        }else{
            printf("false");
        }
        printf("\n");
    }
    return 0;
}
