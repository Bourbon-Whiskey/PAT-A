#include<stdio.h>

int main(){
    int N;
    int i;
    int current=0,goal,time=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&goal);
        while(current>goal){
            current--;
            time+=4;
        }
        while(current<goal){
            current++;
            time+=6;
        }
        time+=5;//wait 
    }
    printf("%d\n",time);
    return 0;
}
