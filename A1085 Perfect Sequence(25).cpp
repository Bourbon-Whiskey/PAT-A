#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010
int main(){
    int N,p,a[maxn];
    int ans;
    int i,j;
    scanf("%d%d",&N,&p);
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    ans=1;
    for(i=0;i<N;i++){
        j=upper_bound(a+i+1,a+N,(long long)a[i]*p)-a;
        ans=max(ans,j-i);
        if(j>N-i){
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
