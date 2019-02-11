#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define maxn 10010

char g[maxn];//male-1;female-0;
set<int> st;
int N,M,K;
vector<int> Friend[maxn];//friend with same gender

struct Pair{
    int n1,n2;
};

vector<Pair> Pa;

bool cmp(Pair a,Pair b){
    if(a.n1!=b.n1){
        return a.n1<b.n1;
    }else{
        return a.n2<b.n2;
    }
}
int Tonum(char a[]){
    int num;
    if(a[0]=='-'){
        num=(a[1]-'0')*1000+(a[2]-'0')*100+(a[3]-'0')*10+(a[4]-'0');
    }else{
        num=(a[0]-'0')*1000+(a[1]-'0')*100+(a[2]-'0')*10+(a[3]-'0');
        g[num]=1;
    }
    return num;
}

void Init(){
    char a[10],b[10];
    int A,B;
    scanf("%d%d",&N,&M);
    while(M--){
        scanf("%s%s",a,b);
        A=Tonum(a);
        B=Tonum(b);
        st.insert(10000*A+B);
        st.insert(10000*B+A); 
        if(g[A]==g[B]){
            Friend[A].push_back(B);
            Friend[B].push_back(A);
        }
    }
    scanf("%d",&K);
}

int Abs(int a){
    return a<0?-a:a;
}

void Check(){
    int A,B;
    int i,j,m,n;
    Pair temp;
    scanf("%d%d",&A,&B);
    A=Abs(A);
    B=Abs(B);
    Pa.clear();
    for(i=0;i<Friend[A].size();i++){
        m=Friend[A][i];
        for(j=0;j<Friend[B].size();j++){
            n=Friend[B][j];
            if(m==B||n==A){
                continue;
            }
            if(st.find(10000*m+n)!=st.end()){
                temp.n1=m;
                temp.n2=n;
                Pa.push_back(temp);
            }
        }
    }
    printf("%d\n",Pa.size());
    sort(Pa.begin(),Pa.end(),cmp);
    for(i=0;i<Pa.size();i++){
        printf("%04d %04d\n",Pa[i].n1,Pa[i].n2);
    }
}

int main(){
    Init();
    while(K--){
        Check();
    }
    return 0;
}
