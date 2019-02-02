#include<stdio.h>
#include<string.h>
#define maxn 1010
char ch[maxn];
void init(){
    int i; 
    for(i=0;i<maxn;i++){
        ch[i]=0;
    }
    return;
} 

int issym(int left,int right){
    while(1){
        if(left>=right){
            return 1;
        }
        if(ch[left]!=ch[right]){
            return 0;
        }
        left++;
        right--;
    }
}
int main(){
    int len,l,i;
    int flag=0;
    init();
    fgets(ch,maxn,stdin);
    len=strlen(ch)-1;
    for(l=len;;l--){
        for(i=0;(i+l)<=len;i++){
            if(issym(i,i+l-1)){
                flag=1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    printf("%d\n",l);
    return 0;
}
