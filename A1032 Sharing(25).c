#include<stdio.h>
#define maxn 100010

struct Node{
    int vis;
    int next;
}node[maxn];

int main(){
    int S1,S2,N;
    int a,c;
    char b;
    scanf("%d%d%d",&S1,&S2,&N);
    while(N--){
        scanf("%d %c %d",&a,&b,&c);
        node[a].vis=0;
        node[a].next=c;
    }
    while(S1!=-1){
        node[S1].vis=1;
        S1=node[S1].next;
    }
    while(S2!=-1&&node[S2].vis==0){
        S2=node[S2].next;
    }
    if(S2==-1){
        printf("-1\n");
    }else{
        printf("%05d\n",S2);
    }
    return 0;
}
