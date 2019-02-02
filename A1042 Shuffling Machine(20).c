#include<stdio.h>
int exchange[55];
int temp[2][55];
void init(){
    int i;
    for(i=1;i<=54;i++){
        temp[0][i]=i;
        temp[1][i]=0;//
    }
    return;
}

void repeat(int n){
    int i;
    for(i=1;i<=54;i++){
        temp[n%2][exchange[i]]=temp[(n+1)%2][i];
    }
    return;
}

void print(int n){
    int i;
    int num,c,d;
    char ch[5]="SHCDJ";
    for(i=1;i<=54;i++){
        num=temp[n%2][i];
        c=(num-1)/13;
        d=num-13*c;
        printf("%c%d",ch[c],d);
        if(i<54){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return;
}
int main(){
    int N,i;
    init();
    scanf("%d",&N);
    for(i=1;i<=54;i++){
        scanf("%d",&exchange[i]);
    }
    for(i=1;i<=N;++i){
        repeat(i);
    }
    print(N);
    return 0;
} 
