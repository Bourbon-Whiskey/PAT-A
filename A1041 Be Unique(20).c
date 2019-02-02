#include<stdio.h>
#define maxn 100010
int hash[10010];
int bet[maxn];

int main(){
    int N;
    int i,a;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        bet[i]=a;
        hash[a]++;
    }
    for(i=0;i<N;i++){
        if(hash[bet[i]]==1){
            break;
        }
    }
    if(i<N){
        printf("%d\n",bet[i]);
    }else{
        printf("None\n");
    }
    return 0;
}
