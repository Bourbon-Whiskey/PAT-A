#include<stdio.h>
#include<math.h>

#define MAXN 20

int num[MAXN];
int isPrime(int n){
    int sqr,i;
    if(n<=1){
        return 0;
    }else{
        sqr=(int)sqrt(1.0*n);
        for(i=2;i<=sqr;i++){
            if(n%i==0){
                return 0;
            }
        }
    }
    return 1;
}

int Reverse(int n,int radix){
    int k=0,i=0,sum=0;
    do{
        num[k++]=n%radix;
        n/=radix;
    }while(n);
    while(i<k){
        sum=sum*radix+num[i++];
    }
    return sum;
}

int main(){
    int n,rad;
    while(1){
        scanf("%d",&n);
        if(n<0){
            break;
        }
        scanf("%d",&rad);
        if(isPrime(n)&&isPrime(Reverse(n,rad))){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
