#include<cstdio>
#include<algorithm>
#define maxn 100010
using namespace std;

struct Node{
    int address,data,flag,next;
}node[maxn];

bool cmp(Node a,Node b){
    if(a.flag!=b.flag){
        return a.flag>b.flag;
    }else{
        return a.data<b.data;
    }
}

int main(){
    int num=0;
    int N,head;
    int id,data,next;
    int i;
    scanf("%d%d",&N,&head);
    for(i=0;i<N;i++){
        scanf("%d%d%d",&id,&data,&next);
        node[id].address=id;
        node[id].data=data;
        node[id].next=next;
    }
    while(head!=-1){
        num++;
        node[head].flag=1;
        head=node[head].next;
    }
    sort(node,node+maxn,cmp);
    head=node[0].address;
    if(num==0){
        printf("0 -1\n");
    }else{
        printf("%d %05d\n",num,head);
    }
    for(i=0;i<num;i++){
        printf("%05d %d ",node[i].address,node[i].data);
        if(i==num-1){
            printf("-1\n");
        }else{
            printf("%05d\n",node[i+1].address);
        }
    }
    return 0;
}
