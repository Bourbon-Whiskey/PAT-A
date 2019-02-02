#include<stdio.h>
#include<string.h>
#define maxn 10010

char str1[maxn],str2[maxn],str3[maxn];
int hash[128];

int main(){
    int len,i,k=0;
    fgets(str1,maxn,stdin);
    fgets(str2,maxn,stdin);
    len=strlen(str2);
    for(i=0;i<len;i++){
        hash[str2[i]]=1;
    }
    len=strlen(str1);
    for(i=0;i<len;i++){
        if(hash[str1[i]]!=1){
            str3[k++]=str1[i];
        }
    }
    printf("%s\n",str3);
    return 0;
}
