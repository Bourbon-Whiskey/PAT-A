#include<stdio.h>
#include<math.h>
#define maxn 10010

int HashTable[maxn];

int IsPrime(int n){
    int i;
    if(n<=1){
        return 0;
    }
    int sqr=(int)sqrt(1.0*n);
    for(i=2;i<=sqr;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int FindPrime(int n){
    for(;;n++){
        if(IsPrime(n)){
            return n;
        }
    }
}

int main(){
    int M,N,num,res,i;
    scanf("%d%d",&M,&N);
    M=FindPrime(M);
    while(N--){
        scanf("%d",&num);
        res=num%M;
        for(i=0;i<M;i++){
            res=(num+i*i)%M;
            if(HashTable[res]==0){
                HashTable[res]=1;
                printf("%d",res);
                break;
            }
        }
        if(i==M){
            printf("-");
        }
        if(N>0){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}
