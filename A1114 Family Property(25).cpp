#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 10010

int N;

int vis[maxn];
int father[maxn];

struct Data{
    int Set,area;
}P[maxn];

struct Family{
    int id,Set,area,num;
    int vivid;
}F[maxn];

struct Res{
    int num,id;
    double Set,area;
};

vector<int> R;
vector<Res> Result;

bool cmp(Res a,Res b){
    if(a.area!=b.area){
        return a.area>b.area;
    }else{
        return a.id<b.id;
    }
}

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
        if(faA<faB){
            father[faB]=faA;
        }else{
            father[faA]=faB;
        }
    } 
}

void Init(){
    int i;
    int N;
    int id,fid,mid,k,a,Set,area; 
    for(i=0;i<10000;i++){
        father[i]=i;
    }
    scanf("%d",&N);
    while(N--){
        scanf("%d%d%d%d",&id,&fid,&mid,&k);
        vis[id]=1;
        if(fid!=-1){
            vis[fid]=1;
            Union(id,fid);
        }
        if(mid!=-1){
            vis[mid]=1;
            Union(id,mid);
        }
        while(k--){
            scanf("%d",&a);
            vis[a]=1;
            Union(id,a);
        }
        scanf("%d%d",&P[id].Set,&P[id].area);
    }
}

void Op(){
    int i,k;
    Res temp;
    for(i=0;i<10000;i++){
        if(vis[i]){
            k=FindFather(i);
            if(F[k].vivid==0){
                F[k].vivid=1;
                F[k].id=i;
                R.push_back(k);
            }
            F[k].num++;
            F[k].Set+=P[i].Set;
            F[k].area+=P[i].area;
        }
    }
    for(i=0;i<R.size();i++){
        temp.id=F[R[i]].id;
        temp.num=F[R[i]].num;
        temp.Set=(1.0*F[R[i]].Set)/(1.0*temp.num);
        temp.area=(1.0*F[R[i]].area)/(1.0*temp.num);
        Result.push_back(temp);
        
    }
    sort(Result.begin(),Result.end(),cmp);
}

void Print(){
    int i;
    Res temp;
    printf("%d\n",Result.size());
    for(i=0;i<Result.size();i++){
        temp=Result[i];
        printf("%04d %d %.3f %.3f\n",temp.id,temp.num,temp.Set,temp.area);
    }
}

int main(){
    Init();
    Op();
    Print();
    return 0;
}
