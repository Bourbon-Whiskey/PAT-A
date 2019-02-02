#include<stdio.h>

#define MAXN 110

char num[MAXN];
int sum=0;

void print(int n){
    char out[][7]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int res[MAXN];
    int end;
    do{
        res[end++]=n%10;
        n/=10;
    }while(n);
    while(end>0){
        printf("%s",out[res[--end]]);
        if(end>0){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return;
} 
int main(){
    int i=0;
    fgets(num,MAXN,stdin);
    while(num[i]>='0'&&num[i]<='9'){
        sum+=(num[i]-'0');
        i++;
    }
    print(sum);
    return 0;
} 
