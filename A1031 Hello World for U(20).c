#include<stdio.h>
#include<string.h>

int main(){
    char ch[90];
    int len,i,j,k;
    int n1,n2;
    scanf("%s",ch);
    len=strlen(ch);
    i=0;
    j=len-1;
    n1=(len+2)/3;//高度 
    n2=len-2*n1+2;//宽度 
    while(--n1){
        k=n2-2;
        printf("%c",ch[i]);
        i++;
        while(k--){
            printf(" ");
        }
        printf("%c\n",ch[j]);
        j--;
    }
    while(i<=j){
        printf("%c",ch[i++]);
    }
    printf("\n");
    return 0;
}
