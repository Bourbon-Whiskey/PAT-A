#include<stdio.h>
#define maxn 1010

int trace[15];
int Max,Flag;
int seq[maxn],N;

void Init(){
    int i;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&seq[i]);
    }
    if(seq[1]>seq[2]){
        Max=1;//大根堆 
    }else{
        Max=0;
    }
    Flag=1;
}

void DFS(int n,int depth){
    int i;
    if(n>N){
        return;
    }
    trace[depth]=seq[n];
    if(2*n>N){
        printf("%d",trace[0]);
        for(i=1;i<=depth;i++){
            if(Flag){
                if(Max){
                    if(trace[i]>trace[i-1]){
                        Flag=0;
                    }
                }else{
                    if(trace[i]<trace[i-1]){
                        Flag=0;
                    }
                }
            }
            printf(" %d",trace[i]); 
        }
        printf("\n");
        return;
    }
    DFS(2*n+1,depth+1);
    DFS(2*n,depth+1);
}

void Check(){
    if(Flag==0){
        printf("Not Heap\n");
    }else{
        if(Max==1){
            printf("Max Heap\n");
        }else{
            printf("Min Heap\n");
        }
    }
}

int main(){
    Init();
    DFS(1,0);
    Check();
    return 0;
}
