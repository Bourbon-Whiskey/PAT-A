#include<stdio.h>
#define maxn 100010
int arr[maxn];

int main(){
    int i,N,a;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&a);
        if(a>=0&&a<maxn){
            arr[a]=1;
        }
    }
    for(i=1;1;i++){
        if(arr[i]==0){
            printf("%d\n",i);
            return 0;
        }
    }
}
