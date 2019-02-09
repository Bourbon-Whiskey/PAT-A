#include<stdio.h>
#include<math.h>
#define maxn 10010
int N,K;
struct S{
    int rank;
    int checked;
}stu[maxn];

void Init(){
    int i,a;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&a);
        stu[a].rank=i;
    }
    scanf("%d",&K);
}

int isPrime(int x){
    int i,sq=(int)sqrt(1.0*x);
    if(x==1){
        return 0;
    }
    for(i=2;i<=sq;i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

void Check(int v){
    if(stu[v].rank==0){
        printf("%04d: Are you kidding?\n",v);
        return;
    }
    if(stu[v].checked==1){
        printf("%04d: Checked\n",v);
        return;
    }else{
        stu[v].checked=1;
        if(stu[v].rank==1){
            printf("%04d: Mystery Award\n",v);
        }else if(isPrime(stu[v].rank)){
            printf("%04d: Minion\n",v);
        }else{
            printf("%04d: Chocolate\n",v);
        }
    }
}

int main(){
    int a;
    Init();
    while(K--){
        scanf("%d",&a);
        Check(a);
    }
    return 0;
}
