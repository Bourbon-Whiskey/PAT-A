#include<stdio.h>
#include<math.h>
#define maxn 1010

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

int main(){
    int L,K;
    int i,j,num,base=1;
    char str[maxn];
    scanf("%d%d",&L,&K);
    scanf("%s",str);
    num=str[0]-'0';
    for(i=1;i<K;i++){
        num=num*10+str[i]-'0';
        base*=10;
    }
    for(i=0;i<=L-K;i++){
        if(IsPrime(num)){
            for(j=0;j<K;j++){
                printf("%c",str[i+j]);
            }
            printf("\n");
            return 0;
        }
        num=(num%base)*10+str[i+K]-'0';
    }
    printf("404\n");
    return 0;
}
