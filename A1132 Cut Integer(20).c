#include<stdio.h>
#include<string.h>
char num[20];

int Change(int left,int right){
    int i,ans=0;
    for(i=left;i<right;i++){
        ans=ans*10+num[i]-'0';
    }
    return ans;
}

int main(){
    int N,len,a,b,c;
    scanf("%d",&N);
    while(N--){
        scanf("%s",num);
        len=strlen(num);
        a=Change(0,len/2);
        b=Change(len/2,len);
        c=Change(0,len);
        if((a*b)!=0&&c%(a*b)==0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}
