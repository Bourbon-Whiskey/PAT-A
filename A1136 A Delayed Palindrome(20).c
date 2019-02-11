#include<stdio.h>
#include<string.h>
#define maxn 1050
char ans[maxn],re[maxn],sum[maxn];

int check (char a[]){
    int left=0,right=strlen(a)-1;
    while(left<right){
        if(a[left]!=a[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
} //1对称

void Reverse(char a[],char b[]){
    int i=0,len=strlen(a)-1;
    while(len>=0){
        b[i++]=a[len];
        len--;
    }
    b[i]=0;
    return;
}

void Add(){
    int i=0,c=0,num;
    Reverse(ans,re);
    while(ans[i]!=0){
        num=re[i]+ans[i]-2*'0'+c;
        c=num/10;
        sum[i++]=num%10+'0';
    }
    if(c){
        sum[i++]='1';
    }
    sum[i]=0;
    printf("%s + %s = ",ans,re);
    Reverse(sum,ans);
    printf("%s\n",ans);
}

int main(){
    int N=0;
    scanf("%s",ans);
    while(1){
        if(check(ans)){
            printf("%s is a palindromic number.\n",ans);
            return 0;
        }
        Add();
        N++;
        if(N>=10){
            break;
        }
    }
    printf("Not found in 10 iterations.\n");
    return 0;
}
