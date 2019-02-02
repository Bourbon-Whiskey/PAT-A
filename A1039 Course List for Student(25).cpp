#include<vector>
#include<cstdio>
#include<algorithm>
#define maxn 180000
using namespace std;
vector<int> L[maxn];

bool cmp(int a,int b){
    return a<b;
}

int main(){
    int N,K;
    int ca,num;
    int id;
    char na[5];
    int i,j;
    scanf("%d%d",&N,&K);
    for(i=0;i<K;i++){
        scanf("%d%d",&ca,&num);
        for(j=0;j<num;j++){
            getchar();
            scanf("%s",na);
            id=(na[3]-'0')*17576+(na[0]-'A')*676+(na[1]-'A')*26+na[2]-'A';
            L[id].push_back(ca);
        }
    }
    for(i=0;i<N;i++){
        getchar();
        scanf("%s",&na);
        printf("%s ",na);
        id=(na[3]-'0')*17576+(na[0]-'A')*676+(na[1]-'A')*26+na[2]-'A';
        printf("%d",L[id].size());
        sort(L[id].begin(),L[id].end(),cmp);
        for(j=0;j<L[id].size();j++){
            printf(" %d",L[id][j]);
        }
        printf("\n");
    }
    return 0;
}
