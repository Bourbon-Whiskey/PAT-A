#include<stdio.h>

struct SEQ{
    int begin;
    int end;
    int sum;
}temp,max;

void init(){
    max.sum=-1;
    temp.begin=-1;
    temp.sum=-1;
    return;
}
 
int main(){
    int K,num;
    int i;
    int first,last;
    scanf("%d",&K);//读入K 
    init();
    for(i=0;i<K;i++){
        scanf("%d",&num);
        if(i==0){
            first=num;
        }
        if(i==(K-1)){
            last=num;
        }
        if(temp.sum>=0){//到目前部分和仍大于0 
            temp.end=num;
            temp.sum+=num;
            if(temp.sum>max.sum){
                max=temp;
            }
        }else{
            temp.begin=num;
            temp.end=num;
            temp.sum=num;
            if(temp.sum>max.sum){
                max=temp;
            }
        }
    }
    if(max.sum==-1){
        max.begin=first;
        max.end=last;
        max.sum=0;
    }
    printf("%d %d %d\n",max.sum,max.begin,max.end);
    return 0;
}
