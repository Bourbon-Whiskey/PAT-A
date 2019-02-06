#include<stdio.h>

int flag=0,flag1=0;//表明是否开始输出
char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

void print(int n){
    if(flag){
        printf(" ");
    }
    if(n/1000){//n>1000,输出千位 
        printf("%s Qian",num[n/1000]);
        flag=1;
        flag1=0;
        n%=1000;
        if(n){
            printf(" ");
        }else{
            return;
        }
    }else{
        if(flag&&flag1==0){
            printf("%s ",num[0]);
            flag1=1;
        }
    }
    if(n/100){//n>100,输出百位 
        printf("%s Bai",num[n/100]);
        flag=1;
        flag1=0;
        n%=100;
        if(n){
            printf(" ");
        }else{
            return;
        }
    }else{
        if(flag&&flag1==0){
            printf("%s ",num[0]);
            flag1=1;
        }
    }
    if(n/10){//n>10,输出十位 
        printf("%s Shi",num[n/10]);
        flag=1;
        flag1=0;
        n%=10;
        if(n){
            printf(" ");
        }else{
            return;
        }
    }else{
        if(flag&&flag1==0){
            printf("%s ",num[0]);
            flag1=1;
        }
    }
    if(n){//输出个位 
        printf("%s",num[n]);
        flag=1;
        flag1=0;
        return; 
    }    
}

int main(){
    int N;
    scanf("%d",&N);
    if(N==0){
        printf("ling\n");
        return 0;
    }
    if(N<0){
        printf("Fu ");
        N=-N;
    }
    //亿 
    if(N/100000000){
        printf("%s Yi",num[N/100000000]);
        N%=100000000;
        flag=1;
    }
    if(N==0){//N>0
        printf("\n");
        return 0;
    }
    //万 
    if(N/10000){
        print(N/10000);
        N%=10000;
        printf(" Wan");
    }
    if(N==0){//N>0
        printf("\n");
        return 0;
    }
    print(N);
    printf("\n");
    return 0;
}
