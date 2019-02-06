#include<stdio.h>
#define maxn 1010
int main(){
    int N,M,K;
    int i;
    int stack[maxn],top,current,flag,num;
    scanf("%d%d%d",&M,&N,&K);
    stack[M]=-1;
    while(K--){
        top=-1;
        flag=1;
        num=1;
        if(M>0){
            stack[++top]=1;
        }else{
            printf("NO\n");
        }
        for(i=0;i<N;i++){
            scanf("%d",&current);
            if(flag){
                while(top<M-1&&num<N&&(stack[top]<current||top==-1)){
                    stack[++top]=++num;
                }
                if(stack[top]==current){
                    top--;
                }else{
                    flag=0;
                }
            }
        }
        if(flag==0){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}

