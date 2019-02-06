#include<cstdio>
#include<algorithm>
#include<vector> 
using namespace std;
struct Student{
    char name[12],id[12];
    int grade;
    int vivid;
};

bool cmp(Student a,Student b){
    if(a.vivid!=b.vivid){
        return a.vivid>b.vivid;
    }else{
        return a.grade>b.grade;
    }
}

int main(){
    int N,low,high;
    int i,cnt=0;
    Student temp;
    vector<Student> stu;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s %s %d",&temp.name,&temp.id,&temp.grade);
        stu.push_back(temp);
    }
    scanf("%d%d",&low,&high);
    for(i=0;i<N;i++){
        if(stu[i].grade>=low&&stu[i].grade<=high){
            cnt++;
            stu[i].vivid=1;
        }
    }
    sort(stu.begin(),stu.end(),cmp);
    if(cnt==0){
        printf("NONE\n");
    }
    for(i=0;i<cnt;i++){
        printf("%s %s\n",stu[i].name,stu[i].id);
    }
    return 0;
}
