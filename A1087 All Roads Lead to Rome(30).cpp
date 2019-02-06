#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 210
#define INF 10000000

map<int,string> inttostr;
map<string,int> strtoint;
int num=0;
int N,K;
string start;
int End;


struct Node{
    int v;
    int d;
};

int happiness[maxn];//快乐值 
vector<Node> G[maxn];//邻接表
int vis[maxn],d[maxn];//访问距离
vector<Node> pre[maxn];//前序表 

int trace[maxn];

struct Route{
    int depth;
    int trace[maxn];
    int happy;
    int average;
};

vector<Route> P;

void change(string a){
    strtoint[a]=num;
    inttostr[num]=a;
    num++;
}

void Init(){
    int i;
    string str1,str2;
    int a,b;
    int H;
    Node temp;
    cin>>N>>K>>start;
    for(i=1;i<N;i++){
        d[i]=INF;
    }
    change(start);
    happiness[strtoint[start]]=0;
    for(i=1;i<N;i++){
        cin>>str1>>H;
        change(str1);
        happiness[strtoint[str1]]=H;
    }
    for(i=0;i<K;i++){
        cin>>str1>>str2>>temp.d;
        a=strtoint[str1];
        b=strtoint[str2];
        temp.v=a;
        G[b].push_back(temp);
        temp.v=b;
        G[a].push_back(temp);
    }
    End=strtoint["ROM"];
}

void Dijkstra(){
    int i,j,Min;
    int u,v,dis;
    Node temp;
    for(i=0;i<N;i++){
        u=-1,Min=INF;
        for(j=0;j<N;j++){
            if(vis[j]==0&&d[j]<Min){
                u=j;
                Min=d[u];
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(j=0;j<G[u].size();j++){
            v=G[u][j].v;
            if(vis[v]==0){
                dis=G[u][j].d;
                if(d[v]>d[u]+dis){
                    d[v]=d[u]+dis;
                    temp.d=dis;
                    temp.v=u;
                    pre[v].clear();
                    pre[v].push_back(temp);
                }else if(d[v]==d[u]+dis){
                    temp.d=dis;
                    temp.v=u;
                    pre[v].push_back(temp);
                }
            } 
        }
        if(u==End){
            break;
        }
    }
}

void DFS(int u,int depth,int d){
    int i;
    Route temp;
    trace[depth]=u;
    if(d<0){
        return;//舍弃 
    }
    if(d==0){
        if(u==0){
            temp.depth=depth;
            temp.happy=0;
            for(i=0;i<=depth;i++){
                temp.trace[i]=trace[i];
                temp.happy+=happiness[trace[i]];
            }
            temp.average=temp.happy/(depth);
            P.push_back(temp);
        }
        return;//到达路径终点，或舍弃 
    }
    for(i=0;i<pre[u].size();i++){
        DFS(pre[u][i].v,depth+1,d-pre[u][i].d);
    } 
}

bool cmp(Route a,Route b){
    if(a.happy!=b.happy){
        return a.happy>b.happy;
    }else{
        return a.average>b.average;
    }
}

int main(){
    int i;
    Route temp;
    Init();
    Dijkstra();
    DFS(End,0,d[End]);
    sort(P.begin(),P.end(),cmp);
    temp=P[0];
    cout<<P.size()<<" "<<d[End]<<" "<<temp.happy<<" "<<temp.average<<endl;
    for(i=temp.depth;i>=0;i--){
        cout<<inttostr[temp.trace[i]];
        if(i>0){
            cout<<"->";
        }else{
            cout<<endl;
        }
    }
    return 0;
}
