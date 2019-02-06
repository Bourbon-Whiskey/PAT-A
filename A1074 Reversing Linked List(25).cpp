#include<cstdio>
#include<algorithm>
using namespace std;

#define maxn 100010
#define INF 100000000

struct Node{
    int id;
    int data;
    int next;
    int seq;
    int vis;
}node[maxn];

int FN,N,K;
int num=0,current;

bool cmp(Node a,Node b){
    if(a.vis!=b.vis){
        return a.vis>b.vis;
    }else{
        return a.seq<b.seq;
    }
}
void Init(){
    int i; 
    int ad;
    scanf("%d%d%d",&FN,&N,&K);
    for(i=0;i<N;i++){
        scanf("%d",&ad);
        node[ad].id=ad;
        scanf("%d%d",&node[ad].data,&node[ad].next);
    }
}

int main(){
    int group; 
    int i,j;
    Init();
    current=FN;
    while(current!=-1){
        node[current].vis=1;
        node[current].seq=num++;
        current=node[current].next;
    }//编号从0开始 
    group=num/K;
    current=FN;
    for(i=0;i<group;i++){
        for(j=K-1;j>=0;j--){
            node[current].seq=i*K+j;
            current=node[current].next;
        }
    }
    sort(node,node+maxn,cmp);
    printf("%05d %d ",node[0].id,node[0].data);
    for(i=1;i<num;i++){
        printf("%05d\n%05d %d ",node[i].id,node[i].id,node[i].data);
    }
    printf("-1\n");
    return 0;
}
