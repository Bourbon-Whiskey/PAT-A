#include<stdio.h>
#define maxn 1010
int Heap[maxn];
int M,N,seq;
void Check1(){//Max;
    int i,j;
    for(i=N/2;i>=1;i--){
        j=2*i;
        if(j<=N&&Heap[j]>Heap[i]){
            printf("Not Heap\n");
            return;
        }
        j=2*i+1;
        if(j<=N&&Heap[j]>Heap[i]){
            printf("Not Heap\n");
            return;
        }
    }
    printf("Max Heap\n");
}

void Check2(){//Min;
    int i,j;
    for(i=N/2;i>=1;i--){
        j=2*i;
        if(j<=N&&Heap[j]<Heap[i]){
            printf("Not Heap\n");
            return;
        }
        j=2*i+1;
        if(j<=N&&Heap[j]<Heap[i]){
            printf("Not Heap\n");
            return;
        }
    }
    printf("Min Heap\n");
}

void PostOrder(int root){
    if(root>N){
        return;
    }
    PostOrder(2*root);
    PostOrder(2*root+1);
    printf("%d",Heap[root]);
    seq++;
    if(seq==N){
        printf("\n");
    }else{
        printf(" ");
    }
}


void Init(){
    int i;
    seq=0;
    for(i=1;i<=N;i++){
        scanf("%d",&Heap[i]);
    }
    if(Heap[1]>Heap[2]){
        Check1();//Max
    }else{
        Check2();
    }
    PostOrder(1);
}

int main(){
    scanf("%d%d",&M,&N);
    while(M--){
        Init();
    }
    return 0;
}
