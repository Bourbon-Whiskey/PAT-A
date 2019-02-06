#include<stdio.h>
int main(){
    int i,j,num,ans=-1,count=0;
    int M,N;
    scanf("%d%d",&M,&N);
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%d",&num);
            if(ans==num){
                count++;
            }else{
                count--;
                if(count<0){
                    ans=num;
                    count=1;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
