#include<stdio.h>
#define maxc 210
#define maxn 10010

int Max(int a,int b){
    return a>b?a:b;
}

int A[maxc],B[maxn],dp[maxc][maxn];

int main(){
    int N,M,L;
    int i,j,MAX;
    scanf("%d%d",&N,&M);
    for(i=1;i<=M;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&L);
    for(i=1;i<=L;i++){
        scanf("%d",&B[i]);
    }
    //边界
    for(i=0;i<=M;i++){
        dp[i][0]=0;
    }
    for(j=0;j<=L;j++){
        dp[0][j]=0;
    }
    //状态转移方程
    for(i=1;i<=M;i++){
        for(j=1;j<=L;j++){
            MAX=Max(dp[i-1][j],dp[i][j-1]);
            if(A[i]==B[j]){
                dp[i][j]=MAX+1;
            }else{
                dp[i][j]=MAX;
            }
        }
    }
    printf("%d\n",dp[M][L]);
    return 0;
}
