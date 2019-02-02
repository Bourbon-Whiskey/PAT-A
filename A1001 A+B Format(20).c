#include<stdio.h>
int main(){
    int a,b,ans;
    int num[5]={0,0,0,0,0};
    int k=0;//标记几段开始 
    scanf("%d%d",&a,&b);
    ans=a+b;
    if(ans<0){
        printf("-");
        ans=-ans; 
    }
    do{
        num[k++]=ans%1000;
        ans/=1000;
    }while(ans);
    printf("%d",num[--k]);
    while(k>0){
        printf(",%03d",num[--k]);
    }
    printf("\n");
    return 0;
} 
