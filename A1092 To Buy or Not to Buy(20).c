#include<stdio.h>
#include<string.h>
#define maxn 1010
int HashTable[2][128];
int main(){
    char str[maxn];
    int i,len1,len2,ans;
    scanf("%s",str);
    len1=strlen(str);
    for(i=0;i<len1;i++){
        HashTable[0][str[i]]++;
    }
    scanf("%s",str);
    len2=strlen(str);
    for(i=0;i<len2;i++){
        HashTable[1][str[i]]++;
    }
    for(i=0;i<128;i++){
        if(HashTable[1][i]>HashTable[0][i]){
            break;//不够 
        }
    }
    if(i<128){
        printf("No ");
        ans=0;
        for(i=0;i<128;i++){
            ans+=((HashTable[0][i]-HashTable[1][i])<0?HashTable[0][i]-HashTable[1][i]:0);
        }
        printf("%d\n",-ans);
    }else{
        printf("Yes %d\n",len1-len2);
    }
    return 0;
}
