#include<stdio.h>
int HashTable[45];
int main(){
    int N,i,ans;
    int seq=0,res[45];
    char temp[10];
    scanf("%d",&N);
    while(N--){
        scanf("%s",temp);
        ans=0;
        i=0;
        while(temp[i]){
            ans+=temp[i]-'0';
            i++;
        }
        HashTable[ans]=1;
    }
    for(i=0;i<45;i++){
        if(HashTable[i]==1){
            res[seq++]=i;
        }
    }
    printf("%d\n",seq);
    for(i=0;i<seq;i++){
        printf("%d",res[i]);
        if(i<seq-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}