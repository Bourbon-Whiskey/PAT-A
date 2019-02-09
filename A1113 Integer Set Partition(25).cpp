#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int sum,sum1;

int main(){
    vector<int> seq;
    int i,a,N;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        sum+=a;
        seq.push_back(a);
    }
    sort(seq.begin(),seq.end());
    a=N%2;
    N/=2;
    for(i=0;i<N;i++){
        sum1+=seq[i];
    }
    printf("%d %d\n",a,sum-2*sum1);
    return 0;
}
