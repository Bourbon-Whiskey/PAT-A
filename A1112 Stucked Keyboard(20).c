#include<stdio.h>
#define maxn 1110
int NotBroken[128];
int HashTable[128];
int k,num=0,num1=0;
char str[maxn],res[maxn],stuck[maxn];

int main(){
    int i=0,j;
    scanf("%d",&k);
    scanf("%s",str);
    while(str[i]!=0){//找坏键 
        for(j=i+1;j<i+k;j++){
            if(str[j]!=str[i]){
                break;
            }
        }
        if(j<i+k){
            NotBroken[str[i]]=1;
            i++;
        }else{
            i=j;
        }
    }
    i=0;
    while(str[i]!=0){//输出 
        res[num++]=str[i];
        if(NotBroken[str[i]]){
            i++;
        }else{
            if(HashTable[str[i]]==0){
                stuck[num1++]=str[i];
                HashTable[str[i]]=1;
            }
            i+=k;
        }
    }
    printf("%s\n%s\n",stuck,res); 
    return 0;
}
