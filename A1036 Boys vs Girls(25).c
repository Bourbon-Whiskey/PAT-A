#include<stdio.h>
#define maxn 1010

struct stu{
    char name[15];
    char id[15];
    int grade;
}stu[maxn];

int main(){
    int N;
    char c;
    int i;
    int maxF=-1,GF=-1;
    int minM=-1,BF=200; 
    scanf("%d",&N);
    for(i=0;i<N;i++){
        getchar();
        scanf("%s %c %s %d",&stu[i].name,&c,&stu[i].id,&stu[i].grade);
        if(c=='M'){//找最低 
            if(stu[i].grade<BF){
                BF=stu[i].grade;
                minM=i;
            } 
        }else{
            if(stu[i].grade>GF){
                GF=stu[i].grade;
                maxF=i;
            } 
        }
    }
    if(maxF==-1){
        printf("Absent\n");
    }else{
        printf("%s %s\n",stu[maxF].name,stu[maxF].id);
    }
    if(minM==-1){
        printf("Absent\n");
    }else{
        printf("%s %s\n",stu[minM].name,stu[minM].id);
    }
    if(maxF==-1||minM==-1){
        printf("NA\n");
    }else{
        printf("%d\n",GF-BF);
    }
    return 0;
}

