#include<stdio.h>
#include<math.h>
#define maxn 1010
int Queen[maxn];
void check(){
    int N;
    int i,j;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&Queen[i]);
    }
    for(i=1;i<=N;i++){
        for(j=i+1;j<=N;j++){
            if(Queen[i]==Queen[j]||abs(Queen[i]-Queen[j])==(j-i)){
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main(){
    int K;
    scanf("%d",&K);
    while(K--){
        check();
    }
    return 0;
}

