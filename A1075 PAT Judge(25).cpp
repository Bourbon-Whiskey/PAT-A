#include<cstdio>
#include<algorithm>
using namespace std;
 
#define maxn 10010
struct Student{
    int id;
    int score[10];
    int score_v[10];
    int totalscore;
    int vivid;
    int rank;
    int perfect_solved;
}stu[maxn];
 
int N,K,M;
int p[10];

bool cmp(Student a,Student b){
    if(a.vivid!=b.vivid){
        return a.vivid>b.vivid;
    }else if(a.totalscore!=b.totalscore){
        return a.totalscore>b.totalscore;
    }else if(a.perfect_solved!=b.perfect_solved){
        return a.perfect_solved>b.perfect_solved;
    }else{
        return a.id<b.id;
    }
}

void Init(){
    int i,j;
    int id,p_id,score;
    scanf("%d%d%d",&N,&K,&M);
    for(i=1;i<=N;i++){
        stu[i].id=i;
        stu[i].perfect_solved=0;
        stu[i].totalscore=0;
    }
    for(i=1;i<=K;i++){
        scanf("%d",&p[i]);
    }
    for(i=0;i<M;i++){
        scanf("%d%d%d",&id,&p_id,&score);
        stu[id].score_v[p_id]=1;
        if(score>=0){
            stu[id].vivid=1;
            if(score>stu[id].score[p_id]){
                stu[id].score[p_id]=score;
            }
        }
    }
    for(i=1;i<=N;i++){
        for(j=1;j<=K;j++){
            stu[i].totalscore+=stu[i].score[j];
            if(stu[i].score[j]==p[j]){
                stu[i].perfect_solved++;
            }
        }
    }
    return;
}

int main(){
    int i,j,num=1;
    Init();
    sort(stu+1,stu+N+1,cmp);
    stu[1].rank=1;
    for(i=2;i<=N;i++){
        if(stu[i].vivid==0){
            break;
        }
        num++;
        if(stu[i].totalscore==stu[i-1].totalscore){
            stu[i].rank=stu[i-1].rank;
        }else{
            stu[i].rank=i;
        }
    }
    for(i=1;i<=num;i++){
        printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].totalscore);
        for(j=1;j<=K;j++){
            if(stu[i].score_v[j]==1){
                printf(" %d",stu[i].score[j]);
            }else{
                printf(" -");
            }
        }
        printf("\n");
    }
    return 0;
}
