#include<stdio.h>
#include<string.h>
#define maxn 100010
int Pnum[maxn],Tnum[maxn];
int sum;
int main(){
    int i,len,count;
    char str[maxn];
    scanf("%s",str);
    len=strlen(str);
    count=0;
    for(i=0;i<len;i++){
        Pnum[i]=count;
        if(str[i]=='P'){
            count++;
        }
    }
    count=0;
    for(i=len-1;i>=0;i--){
        Tnum[i]=count;
        if(str[i]=='T'){
            count++;
        }
    }
    for(i=0;i<len;i++){
        if(str[i]=='A'){
            sum+=Pnum[i]*Tnum[i];
            sum%=1000000007;
        }
    }
    printf("%d\n",sum);
}
