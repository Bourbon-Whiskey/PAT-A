#include<stdio.h>
void check(char a[],char b[]){
    int i=0,num[10]={0,0,0,0,0,0,0,0,0,0};
    while(a[i]){
        num[a[i++]-'0']++;
    }
    if(b[i]){
        printf("No\n");
        return;
    }
    while(i){
        num[b[--i]-'0']--;
        if(num[b[i]-'0']<0){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    return;
}

int main(){
    char n1[30],n2[30];
    int len=0,sum,i,k=0,c=0;
    scanf("%s",&n1);
    while(n1[len]){
        len++;
    }
    for(i=len-1;i>=0;i--){
        sum=(n1[i]-'0')*2+c;
        c=sum/10;
        sum=sum%10;
        n2[k++]=sum+'0';
    }
    if(c==1){
        n2[k++]='1';
    }
    n2[k]=0;
    check(n1,n2);
    while(k){
        printf("%c",n2[--k]);
    }
    printf("\n");
    return 0;
}
