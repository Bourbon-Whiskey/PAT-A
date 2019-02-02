#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
char name[40010][5];
vector<int> course[2510];

bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;
}

int main(){
    int N,K,C,courseID;
    int i,j;
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++){
        scanf("%s %d",name[i],&C);
        for(j=0;j<C;j++){
            scanf("%d",&courseID);
            course[courseID].push_back(i);
        }
    }
    for(i=1;i<=K;i++){
        printf("%d %d\n",i,course[i].size());
        sort(course[i].begin(),course[i].end(),cmp);
        for(j=0;j<course[i].size();j++){
            printf("%s\n",name[course[i][j]]);
        }
    }
    return 0;
}
