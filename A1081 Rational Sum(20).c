#include<stdio.h>
long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}//最大公约数

struct Num{
    long long numerator,denominator;
}num,ans;

int main(){
    int i,N,flaga,flagn;
    long long pub,a,n,integer;
    scanf("%d",&N);
    scanf("%lld/%lld",&ans.numerator,&ans.denominator);
    if(ans.numerator>=0){
        flaga=1;
    }else{
        flaga=-1;
        ans.numerator=-ans.numerator;
    }
    for(i=1;i<N;i++){
        scanf("%lld/%lld",&num.numerator,&num.denominator);
        if(num.numerator>=0){
            flagn=1;
        }else{
            flagn=-1;
            num.numerator=-num.numerator;
        }
        pub=gcd(ans.denominator,num.denominator);
        a=ans.denominator/pub;
        n=num.denominator/pub;
        ans.denominator=a*n*pub;
        ans.numerator=flaga*ans.numerator*n+flagn*num.numerator*a;
        if(ans.numerator>=0){
            flaga=1;
        }else{
            flaga=-1;
            ans.numerator=-ans.numerator;
        }
        pub=gcd(ans.numerator,ans.denominator);
        ans.denominator/=pub;
        ans.numerator/=pub;
    }
    if(flaga==-1){
        printf("-");
    }
    integer=ans.numerator/ans.denominator;
    ans.numerator%=ans.denominator;
    if(integer){
        printf("%d",integer);
        if(ans.numerator){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    if(ans.numerator){
        printf("%d/%d\n",ans.numerator,ans.denominator);
    }
    if(integer==0&&ans.numerator==0){
        printf("0\n");
    }
    return 0;
}
