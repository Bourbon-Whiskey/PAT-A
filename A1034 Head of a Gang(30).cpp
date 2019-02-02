#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

#define maxn 2010

using namespace std;

struct Gang{
    string head;
    int num;
};

map<string,int> Nametonum;
map<int,string> Numtoname;
vector<int> Adj[maxn];
vector<Gang> G;
int N,K;
int PersonNum=0;
int inq[maxn];
int w[maxn];

int Change(string s){
    if(Nametonum.find(s)!=Nametonum.end()){
        return Nametonum[s];
    }else{
        Nametonum[s]=PersonNum;
        Numtoname[PersonNum]=s;
        return PersonNum++;
    }
}

void Init(){
    int i;
    string a,b;
    int t;
    int Na,Nb;
    cin>>N>>K;
    for(i=0;i<N;i++){
        cin>>a>>b>>t;
        Na=Change(a);
        Nb=Change(b);
        Adj[Na].push_back(Nb);
        Adj[Nb].push_back(Na);
        w[Na]+=t;
        w[Nb]+=t;
    }
    return;
}

void BFS(int Person){
    int Queue[maxn];
    Gang temp;
    int front=0,rear=0,now;
    int head,hweight=-1,sum=0;
    int i;
    Queue[rear++]=Person;
    inq[Person]=1;
    while(rear>front){
        now=Queue[front++];
        sum+=w[now];
        if(w[now]>hweight){
            head=now;
            hweight=w[head];
        }
        for(i=0;i<Adj[now].size();i++){
            if(inq[Adj[now][i]]==0){
                Queue[rear++]=Adj[now][i];
                inq[Adj[now][i]]=1;
            }
        }
    }
    if(rear>2&&sum/2>K){
        temp.head=Numtoname[head];
        temp.num=rear;
        G.push_back(temp);
    }
    return;
}

bool cmp(Gang a,Gang b){
    return a.head<b.head;
}

int main(){
    int i;
    Gang temp;
    Init();
    for(i=0;i<PersonNum;i++){
        if(inq[i]==0){
            BFS(i);
        }
    }
    sort(G.begin(),G.end(),cmp);
    cout<<G.size()<<endl;
    for(i=0;i<G.size();i++){
        temp=G[i];
        cout<<temp.head<<" "<<temp.num<<endl;
    }
    return 0;
}
