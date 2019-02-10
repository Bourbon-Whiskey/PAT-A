#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 50010

struct Node{
    int data,frequency;
};

bool cmp(Node a,Node b){
    if(a.frequency!=b.frequency){
        return a.frequency>b.frequency;
    }else{
        return a.data<b.data;
    }
}
vector<Node> seq;
int N,K;
int book[maxn],inq[maxn];

void Insert(int v){
    int i,num=0;
    Node temp;
    printf("%d:",v);
    for(i=0;i<seq.size()&&i<K;i++){
        printf(" %d",seq[i].data);
    }
    printf("\n");
    //print
    book[v]++;
    if(inq[v]==0){//不在队内 
        temp.data=v;
        temp.frequency=book[v];
        seq.push_back(temp);
        inq[v]=1;
    }else{
        for(i=0;i<seq.size();i++){
            if(seq[i].data==v){
                seq[i].frequency=book[v];
            }
        }
    }
    sort(seq.begin(),seq.end(),cmp);
    if(seq.size()>K){
        inq[seq[K].data]=0;
        seq.pop_back();
    }
}

int main(){
    int a;
    Node temp;
    scanf("%d%d",&N,&K);
    N--;
    scanf("%d",&a);
    temp.data=a;
    book[a]++;
    temp.frequency=book[a];
    seq.push_back(temp);
    inq[a]=1;
    while(N--){
        scanf("%d",&a);
        Insert(a);
    }
    return 0;
}
