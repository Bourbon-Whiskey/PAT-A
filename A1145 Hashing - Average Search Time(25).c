#include<stdio.h>
#include<math.h>
#define maxn 11000
int Hash[maxn],num=0;

int isPrime(int a){
    int i,sq;
    if(a<=1){
        return 0;
    }
    sq=(int)sqrt(1.0*a);
    for(i=2;i<=sq;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}

int MSize,N,M;

void Insert(int a){
    int i,pos;
    for(i=0;i<MSize;i++){
        pos=(a+i*i)%MSize;
        if(Hash[pos]==0){
            Hash[pos]=a;
            return;
        }
    }
    printf("%d cannot be inserted.\n",a);
}

void Find(int a){
    int i,pos;
    for(i=0;i<=MSize;i++){
        num++;
        pos=pos=(a+i*i)%MSize;
        if(Hash[pos]==a||Hash[pos]==0){
            return;
        }
    }
}

int main(){
    int i,a;
    scanf("%d%d%d",&MSize,&N,&M);
    while(1){
        if(isPrime(MSize)){
            break;
        }
        MSize++;
    }
    while(N--){
        scanf("%d",&a);
        Insert(a);
    }
    for(i=0;i<M;i++){
        scanf("%d",&a);
        Find(a);
    }
    printf("%.1lf\n",1.0*num/M);
    return 0;
}

