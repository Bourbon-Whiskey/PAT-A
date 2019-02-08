#include<stdio.h>

#define maxn 100010

int seq[maxn];//序列 
int left[maxn];//左侧最大值
int right[maxn];//右侧最小值
int N;
int res[maxn],num;

int main(){
    int i,temp; 
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&seq[i]);
    }
    temp=-1;
    for(i=0;i<N;i++){
        if(seq[i]>temp){
            temp=seq[i];
        }
        left[i]=temp;
    }
    temp=2000000000;
    for(i=N-1;i>=0;i--){
        if(seq[i]<temp){
            temp=seq[i];
        }
        right[i]=temp;
    }
    for(i=0;i<N;i++){
        if((left[i]==seq[i])&&(right[i]==seq[i])){
            res[num++]=seq[i];
        }
    }
    printf("%d\n",num);
    for(i=0;i<num;i++){
        printf("%d",res[i]);
        if(i<num-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
} 
