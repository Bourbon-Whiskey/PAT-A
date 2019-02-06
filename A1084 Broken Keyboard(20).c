#include<stdio.h>

#define maxn 128

int HashTable[maxn];
char res[maxn];

int main(){
    char s1[maxn],s2[maxn];
    int num=0;
    int i=0,j=0;
    scanf("%s%s",&s1,&s2);
    while(s1[i]!=0){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }else{
            if(s1[i]>='a'&&s1[i]<='z'){
                if(HashTable[s1[i]]==0){
                    res[num++]=s1[i]-32;
                    HashTable[s1[i]]=1;
                    HashTable[s1[i]-32]=1;
                }
            }else if(s1[i]>='A'&&s1[i]<='Z'){
                if(HashTable[s1[i]]==0){
                    res[num++]=s1[i];
                    HashTable[s1[i]]=1;
                    HashTable[s1[i]+32]=1;
                }
            }else if(s1[i]>='0'&&s1[i]<='9'){
                if(HashTable[s1[i]]==0){
                    res[num++]=s1[i];
                    HashTable[s1[i]]=1;
                }
            }else if(s1[i]=='_'){
                if(HashTable[s1[i]]==0){
                    res[num++]=s1[i];
                    HashTable[s1[i]]=1;
                }
            }
            i++;
        }
    }
    printf("%s\n",res);
    return 0;
}
