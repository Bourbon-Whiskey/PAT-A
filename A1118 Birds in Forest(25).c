#include<stdio.h>
#define maxn 10010

int father[maxn],vis[maxn],isRoot[maxn];
int N,Q,cnt;

int FindFather(int x){
    int z=x,a;
    while(x!=father[x]){
        x=father[x];
    }
    while(z!=x){
        a=z;
        z=father[z];
        father[a]=x;
    }
    return x;
}

void Union(int a,int b){
    int faA=FindFather(a);
    int faB=FindFather(b);
    if(faA!=faB){
        father[faB]=faA;
    }
}

void Check(int a,int b){
    int faA=FindFather(a);
    int faB=FindFather(b);
    if(faA!=faB){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
}

int main(){
    int k,a,b;
    int i=0;
    scanf("%d",&N);
    for(i=1;i<10000;i++){
        father[i]=i;
    }
    while(N--){
        scanf("%d",&k);
        k--;
        scanf("%d",&a);
        vis[a]=1;
        while(k--){
            scanf("%d",&b);
            vis[b]=1;
            Union(a,b);
        }
    }
    N=1;
    while(vis[N]){
        k=FindFather(N);
        isRoot[k]=1;
        N++;
    }
    for(i=1;i<N;i++){
        cnt+=isRoot[i];
    }
    printf("%d %d\n",cnt,N-1);
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&a,&b);
        Check(a,b);
    }
    return 0;
}