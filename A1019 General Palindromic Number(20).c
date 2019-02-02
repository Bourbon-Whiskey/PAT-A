#include<stdio.h>
void check(int a[],int num){
    int i,j;
    i=0;j=num-1;
    while(i<j){
        if(a[i]!=a[j]){
            printf("No\n");
            return;
        }
        i++;
        j--;
    }
    printf("Yes\n");
    return;
}

int main(){
    int i,N,b;
    int sum[50],num=0;
    scanf("%d%d",&N,&b);
    do{
        sum[num++]=N%b;
        N/=b;
    }while(N);
    check(sum,num); 
    while(num){
        printf("%d",sum[--num]);
        if(num==0){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    return 0;
}
