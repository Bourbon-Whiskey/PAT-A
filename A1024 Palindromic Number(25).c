#include<stdio.h>
#include<string.h>
#define maxn 10000
char num[maxn];
void add(){
    char temp[maxn];
    int i=0,j,k=0;
    int c=0,sum;
    for(j=strlen(num)-1;j>=0;){
        sum=num[i]+num[j]+c-96;
        c=sum/10;
        sum=sum%10;
        temp[k++]=sum+'0';
        j--;
        i++;
    }
    if(c==1){
        temp[k++]='1';
    }
    for(i=0,j=k-1;j>=0;){
        num[i]=temp[j];
        i++;
        j--;
    }
    num[k]=0;
    return;
}

int check(){
    int i=0,j;
    j=strlen(num)-1;
    while(i<j){
        if(num[i]!=num[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int main(){
    int n,i=0;
    scanf("%s %d",&num,&n);
    while(i<n){
        if(check()){
            break;
        }else{
            i++;
            add();
        }
    }
    printf("%s\n%d\n",num,i);
}
