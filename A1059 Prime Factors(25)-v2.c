#include<stdio.h>
#include<math.h>
int isPrime(int x)
{
    if(x<=1){
        return 0;
    }
    int i,sqr=sqrt(1.0*x);
    for(i=2;i<=sqr;++i){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    printf("%d=",n);
    if(n==1){
        printf("1\n");
    }else{
        for(i=2;1;++i){
            j=0;
            if(isPrime(i)){
                for(;n%i==0;){
                    n/=i;
                    ++j;
                }
            }
            if(j>1){
                printf("%d^%d",i,j);
            }else if(j==1){
                printf("%d",i);
            }if(n>1&&j>0){
                printf("*");
            }if(n==1){
                break;
            }
        }
    }
    return 0;
}

