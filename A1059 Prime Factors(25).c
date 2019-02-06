#include<stdio.h>
#include<math.h>
#define maxn 1000010
#define int long
int Prime[maxn]={2,3},pnum=2;
int Factor[maxn],fnum=0;

int isPrime(int x){
    int sq,i;
    if(x==1){
        return 0;
    }
    if(x==2||x==3){
        return 1;
    }
    sq=(int)sqrt(1.0*x);
    for(i=0;i<pnum&&Prime[i]<=sq;i++){
        if(x%Prime[i]==0){
            return 0;
        }
    }
    Prime[pnum++]=x;
    return 1;
}

int main(){
    int N,i=0,flag,num;
    int F,sq;
    scanf("%d",&N);
    printf("%d=",N);
    if(N==1){
        printf("1\n");
        return 0;
    }
    while(N>1){
        flag=0;
        for(;i<pnum;){
            if(N%Prime[i]==0){
                Factor[fnum++]=Prime[i];
                N/=Prime[i];
                flag=1;
                break;
            }else{
                i++;
            }
        }
        if(flag){
            continue;
        }else{
            sq=(int)sqrt(1.0*N);
            while(flag==0){
                //找下一个质数 
                for(num=Prime[pnum-1]+1;;num++){
                    if(isPrime(num)){
                        break;
                    }
                }
                
                if(N%Prime[i]==0){
                    Factor[fnum++]=Prime[i];
                    N/=Prime[i];
                    flag=1;
                    break;
                }else{
                    i++;
                }
                if(Prime[i-1]>=sq){
                    Factor[fnum++]=N;
                    N=1;
                    flag=1;
                } 
            }
        }
    }
    i=0;
    while(i<fnum){
        F=Factor[i++];
        num=1;
        while(i<fnum&&Factor[i]==F){
            i++;
            num++;
        }
        if(num>1){
            printf("%d^%d",F,num);
        }else{
            printf("%d",F);
        }
        if(i<fnum){
            printf("*");
        }else{
            printf("\n");
        }
    }
    return 0;
}
