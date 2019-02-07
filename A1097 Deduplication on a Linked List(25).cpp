#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010

struct Node{
    int address,data,seq,next;
    int vivid;
}node[maxn];

int HashTable[10010],first,N;
int count1=0,count2=0,p;

bool cmp(Node a,Node b){
    if(a.vivid!=b.vivid){
        return a.vivid>b.vivid;
    }else{
        return a.seq<b.seq;
    }
}

void Init(){
    int i;
    int address;
    scanf("%d%d",&first,&N);
    for(i=0;i<N;i++){
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address=address;
    }
    p=first;
    i=0;
    while(p!=-1){
        node[p].seq=i++;
        if(HashTable[abs(node[p].data)]==0){
            node[p].vivid=2;
            count1++;
            HashTable[abs(node[p].data)]=1;
        }else{
            node[p].vivid=1;
            count2++;
        }
        p=node[p].next;
    }
    sort(node,node+maxn,cmp);
}

void Print(){
    int i=0;
    if(count1>0){
        printf("%05d %d ",node[0].address,node[0].data);
        i=1;
        while(i<count1){
            printf("%05d\n%05d %d ",node[i].address,node[i].address,node[i].data);
            i++;
        }
        printf("-1\n");
    }
    if(count2>0){
        printf("%05d %d ",node[count1].address,node[count1].data);
        i=count1+1;
        count2+=count1;
        while(i<count2){
            printf("%05d\n%05d %d ",node[i].address,node[i].address,node[i].data);
            i++;
        }
        printf("-1\n");
    }
}

int main(){
    Init();
    Print();
    return 0;
}
