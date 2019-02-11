#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010

struct Node{
    int id,next,seq,data,type;
    int vivid;
}node[maxn];

int seq=0,st,N,K;

bool cmp(Node a,Node b){
    if(a.vivid!=b.vivid){
        return a.vivid>b.vivid;
    }else if(a.type!=b.type){
        return a.type>b.type;
    }else{
        return a.seq<b.seq;
    }
}

void Init(){
    int id,data,next;
    scanf("%d%d%d",&st,&N,&K);
    while(N--){
        scanf("%d%d%d",&id,&data,&next);
        node[id].id=id;
        node[id].data=data;
        node[id].next=next;
        if(data<0){
            node[id].type=3;
        }else if(data<=K){
            node[id].type=2;
        }else{
            node[id].type=1;
        }
    }
}

void Op(){
    while(st!=-1){
        node[st].seq=seq++;
        node[st].vivid=1;
        st=node[st].next;
    }
    sort(node,node+maxn,cmp);
}

void Print(){
    int i;
    printf("%05d %d ",node[0].id,node[0].data);
    for(i=1;i<seq;i++){
        printf("%05d\n%05d %d ",node[i].id,node[i].id,node[i].data);
    }
    printf("-1\n");
}

int main(){
    Init();
    Op();
    Print();
    return 0;
}
