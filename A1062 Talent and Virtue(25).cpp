#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct Person{
    int id,rank,V,T,G;
};
bool cmp(Person a,Person b){
    if(a.rank!=b.rank){
        return a.rank<b.rank;
    }else if(a.G!=b.G){
        return a.G>b.G;
    }else if(a.V!=b.V){
        return a.V>b.V; 
    }else{
        return a.id<b.id;
    }
}

int main(){
    int N,L,H;
    int id,V,T;
    Person temp;
    vector<Person> P;
    P.clear();
    scanf("%d%d%d",&N,&L,&H);
    while(N--){
        scanf("%d%d%d",&id,&V,&T);
        if(V<L||T<L){
            continue;
        }
        temp.G=V+T;
        temp.T=T;
        temp.V=V;
        temp.id=id;
        if(V>=H&&T>=H){
            temp.rank=1;
        }else if(V>=H&&T<H){
            temp.rank=2;
        }else if(V<H&&T<H&&V>=T){
            temp.rank=3;
        }else{
            temp.rank=4;
        }
        P.push_back(temp);
    }
    printf("%d\n",P.size());
    sort(P.begin(),P.end(),cmp);
    for(N=0;N<P.size();N++){
        temp=P[N];
        printf("%08d %d %d\n",temp.id,temp.V,temp.T);
    }
    return 0;
}
