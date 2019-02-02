#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 100010
struct Student{
    int id,grade;
    char name[10];
}stu[maxn];

bool cmp1(Student a,Student b){
    return a.id<b.id;
}

bool cmp2(Student a,Student b){
    int i=strcmp(a.name,b.name);
    if(i!=0){
        return i<0;
    }else{
        return a.id<b.id;
    }
}

bool cmp3(Student a,Student b){
    if(a.grade!=b.grade){
        return a.grade<b.grade;
    }else{
        return a.id<b.id;
    }
}


int main(){
    int N,C;
    int i;
    scanf("%d%d",&N,&C);
    for(i=0;i<N;i++){
        scanf("%d %s %d",&stu[i].id,&stu[i].name,&stu[i].grade);
    }
    if(C==1){
        sort(stu,stu+N,cmp1);
    }else if(C==2){
        sort(stu,stu+N,cmp2);
    }else{
        sort(stu,stu+N,cmp3);
    }
    for(i=0;i<N;i++){
        printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
    }
    return 0;
}
