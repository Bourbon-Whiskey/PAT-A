#include<stdio.h>
int Tobig(int a[]){
    int i,j,sum=0;
    for(i=9;i>=0;i--){
        for(j=0;j<a[i];j++){
            sum=sum*10+i;
        }
    }
    return sum;
}
int Tosmall(int a[]){
    int i,j,sum=0;
    for(i=0;i<=9;i++){
        for(j=0;j<a[i];j++){
            sum=sum*10+i;
        }
    }
    return sum;
}

int main(){
    int num,a[10],i;
    int big,small;
    scanf("%d",&num);
    do{
        for(i=0;i<10;i++){
            a[i]=0;
        }
        for(i=0;i<4;i++){
            a[num%10]++;
            num/=10;
        }
        big=Tobig(a);
        small=Tosmall(a);
        num=big-small;
        printf("%04d - %04d = %04d\n",big,small,num);
    }while(num!=6174&&num!=0);
    return 0;
}
