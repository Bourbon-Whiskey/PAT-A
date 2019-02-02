#include<stdio.h>

struct STU{
    int ID;
    int grade[4];//A,C,M,E;
    int vivid;
}stu[1000010];

char CH[6]="ACME";

int rank[4][110];//排名 
int num[4][110];//人数分段 ACME

void Init(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<110;j++){
            rank[i][j]=0;
            num[i][j]=0;
        }
    }
    return;
}

void GetGrade(int n){
    int i,temp,A,C,M,E;
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        stu[temp].vivid=1;//学号有效
        scanf("%d%d%d",&C,&M,&E);
        num[1][C]++;
        num[2][M]++;
        num[3][E]++;
        A=( C + M + E +1)/3;
        num[0][A]++;
        stu[temp].grade[0]=A;
        stu[temp].grade[1]=C;
        stu[temp].grade[2]=M;
        stu[temp].grade[3]=E;
    }
    return;
}

void DataOp(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=100;j>=0;j--){
            num[i][j]+=num[i][j+1];
            rank[i][j]=num[i][j+1]+1;
        }
    }
    return;
}

void print(int ID){
    int i,imax,grade,mgrade;
    if(stu[ID].vivid==0){
        printf("N/A\n");
    }else{
        mgrade=stu[ID].grade[0];
        imax=0;
        for(i=1;i<4;i++){
            if(rank[i][stu[ID].grade[i]]<rank[imax][mgrade]){
                imax=i;
                mgrade=stu[ID].grade[i];
            }
        }
        printf("%d %c\n",rank[imax][mgrade],CH[imax]);
    }
    return; 
}

int main(){
    int N,M,id;
    int i;
    scanf("%d%d",&N,&M);
    Init();
    GetGrade(N);
    DataOp();
    for(i=0;i<M;i++){
         scanf("%d",&id);
         print(id);
    }
    return 0;
}
