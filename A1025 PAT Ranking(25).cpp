#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 30010

struct Student{
    char id[15];
    int grade,rank,lrank,room;
}stu[maxn];
int R[110];
int lrank[110][110];
int N,K,num=0;
void Init(){
    int i,j,grade;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&K);
        for(j=0;j<K;j++){
            scanf("%s %d",&stu[num].id,&grade);
            stu[num].grade=grade;
            stu[num].room=i;
            lrank[i][grade]++;
            R[grade]++;
            num++;
        } 
    }
    for(i=100;i>=0;i--){
        R[i]+=R[i+1];//大于等于i分的人数 
        for(j=1;j<=N;j++){
            lrank[j][i]+=lrank[j][i+1];
        }
    }
    for(i=0;i<num;i++){
        grade=stu[i].grade;
        stu[i].rank=R[grade+1]+1;
        stu[i].lrank=lrank[stu[i].room][grade+1]+1;
    } 
}

bool cmp(Student a,Student b){
    if(a.rank!=b.rank){
        return a.rank<b.rank;
    }else{
        return strcmp(a.id,b.id)<0;
    }
}

int main(){
    int i;
    Init();
    sort(stu,stu+num,cmp);
    printf("%d\n",num);
    for(i=0;i<num;i++){
        printf("%s %d %d %d\n",stu[i].id,stu[i].rank,stu[i].room,stu[i].lrank);
    }
    return 0;
}
