#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10010], w[10010];
bool choice[10010][110];
bool cmp(int a,int b){
    return a>b;
}
int main() {
    int N,M;
    int i,j;
    int v,index;
    vector<int> pick;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++){
        scanf("%d", &w[i]);
    }
    sort(w,w+N,cmp);
    for(i=0;i<N;i++) {
        for(j=M;j>=w[i];j--) {
            if(dp[j]<= dp[j-w[i]]+w[i]){
                choice[i][j]=1;
                dp[j]=dp[j-w[i]]+w[i];
            }
        }
    }
    if(dp[M]!=M){
        printf("No Solution\n");
    }else{
        v=M,index=N;
        while(v>0){
            if(choice[index][v]==1){
                pick.push_back(w[index]);
                v-=w[index];
            }
            index--;
        }
        for(i=0;i<pick.size();i++){
            if(i!=0){
                printf(" ");
            }
            printf("%d",pick[i]);
        }
        printf("\n");
    }
    return 0;
}
