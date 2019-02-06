#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 40010
#define INF 10000000 

struct Student{
    int Ge,Gi,sum;
    int apply[5];
    int rank;
    int id;
}stu[maxn];

struct School{
    int quota;
    int rank;
    vector<int> admit;
}sch[110];

int N,M,K; 

bool cmp(Student a,Student b){
    if(a.sum!=b.sum){
        return a.sum>b.sum;
    }else if(a.Ge!=b.Ge){
        return a.Ge>b.Ge;
    }else{
        return a.id<b.id;
    }
}

void Init(){
    int i,j;
    scanf("%d%d%d",&N,&M,&K);
    for(i=0;i<M;i++){
        scanf("%d",&sch[i].quota);
        sch[i].rank=INF; 
    }
    for(i=0;i<N;i++){
        stu[i].id=i;
        scanf("%d%d",&stu[i].Ge,&stu[i].Gi);
        stu[i].sum=stu[i].Ge+stu[i].Gi;
        for(j=0;j<K;j++){
            scanf("%d",&stu[i].apply[j]);
        }
    }
    sort(stu,stu+N,cmp);
    stu[0].rank=0;
    for(i=1;i<N;i++){
        if((stu[i].sum==stu[i-1].sum)&&(stu[i].Ge==stu[i-1].Ge)){
            stu[i].rank=stu[i-1].rank;
        }else{
            stu[i].rank=i;
        }
    }
}

void Apply(){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<K;j++){
            if(sch[stu[i].apply[j]].quota>0||sch[stu[i].apply[j]].rank==stu[i].rank){
                sch[stu[i].apply[j]].quota--;
                sch[stu[i].apply[j]].rank=stu[i].rank;
                sch[stu[i].apply[j]].admit.push_back(stu[i].id);
                break; 
            }
        }
    }
}

void Print(){
    int i,j;
    for(i=0;i<M;i++){
        sort(sch[i].admit.begin(),sch[i].admit.end());
        for(j=0;j<sch[i].admit.size();j++){
            printf("%d",sch[i].admit[j]);
            if(j<sch[i].admit.size()-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    Init();
    Apply();
    Print();
    return 0;
}
