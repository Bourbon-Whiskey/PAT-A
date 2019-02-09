#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010

int N;
int num[maxn];
bool cmp(int a,int b){
    return a>b;
}

int main(){
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&num[i]); 
    }
    sort(num,num+N,cmp);
    for(i=0;1;i++){
        if(num[i]<=i+1){
            break;
        }
    }
    printf("%d\n",i);
    return 0;
}
