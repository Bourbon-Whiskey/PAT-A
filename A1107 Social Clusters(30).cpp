#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1010

int father[maxn],isRoot[maxn];
int course[maxn],N,cnt=0;

bool cmp(int a,int b){
    return a>b;
}

int FindFather(int x) {
    int a=x,z;
    while(x!=father[x]){
        x=father[x];
    }
    while(a!=father[a]){
        z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
void Union(int a, int b) {
    int faA=FindFather(a);
    int faB=FindFather(b);
    if(faA!=faB){
        father[faA]=faB;
    }
}

int main(){
    int i,j,k,a;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        father[i]=i;
        scanf("%d:",&k);
        for(j=0;j<k;j++){
            scanf("%d",&a);
            if(course[a]==0){
                course[a]=i;
            }
            Union(i,FindFather(course[a]));
        }
    }
    for(i=1;i<=N;i++){
        isRoot[FindFather(i)]++;
    }
    for(i=1;i<=N;i++){
        if(isRoot[i]!=0){
            cnt++;
        }
    }
    sort(isRoot,isRoot+N+1,cmp);
    printf("%d\n",cnt);
    for(i=0;i<cnt;i++){
        printf("%d",isRoot[i]);
        if(i<cnt-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}
