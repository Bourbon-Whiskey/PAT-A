#include<cstdio>
#include<set>
#include<vector>
using namespace std;

#define maxn 210
#define INF 100000000

int N,M,K,seq=0;
int E[maxn][maxn];
vector<int> sq;
set<int> st;
int Min=INF,Shortest;

void Init(){
    int i,j,a,b,D;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            E[i][j]=INF;
        }
    }
    while(M--){
        scanf("%d%d%d",&a,&b,&D);
        E[a][b]=D;
        E[b][a]=D;
    }
    scanf("%d",&K);
}

void Check(){
    int num,i,a,flag=0,Dist=0;
    seq++;
    sq.clear();
    st.clear();
    scanf("%d",&num);
    while(num--){
        scanf("%d",&a);
        st.insert(a);
        sq.push_back(a);
    }
    if(st.size()<N||sq[0]!=sq[sq.size()-1]){
        flag=2;//Not cycle or didn't visit everycity;
    }else if(sq.size()>(N+1)){
        flag=1;//Not simple circle;
    }
    for(i=1;i<sq.size();i++){
        if(E[sq[i-1]][sq[i]]!=INF){
            Dist+=E[sq[i-1]][sq[i]];
        }else{
            printf("Path %d: NA (Not a TS cycle)\n",seq);
            return;//can't pass
        }
    }
    if(flag==0||flag==1){
        if(Dist<Min){
            Min=Dist;
            Shortest=seq;
        }
        if(flag==0){
            printf("Path %d: %d (TS simple cycle)\n",seq,Dist);
        }else{
            printf("Path %d: %d (TS cycle)\n",seq,Dist);
        }
    }else{
        printf("Path %d: %d (Not a TS cycle)\n",seq,Dist);
    }
}

int main(){
    Init();
    while(K--){
        Check();
    }
    printf("Shortest Dist(%d) = %d\n",Shortest,Min);
    return 0;
}
