#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> seq;

int main(){
    int i,N,a;
    int res;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        seq.push_back(a);
    }
    sort(seq.begin(),seq.end());
    res=seq[0];
    for(i=1;i<N;i++){
        res=(res+seq[i])/2;
    }
    printf("%d\n",res);
    return 0;
}
