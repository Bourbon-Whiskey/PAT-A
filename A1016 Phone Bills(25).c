#include<stdio.h>
#include<string.h>

#define MAXN 1010

struct Record{
    char name[25];
    int time;
    int d,h,m;
    int status;
}rec[MAXN];

int Sort[MAXN];
int Fee[24];
int Fee_Date,Fee_Hour[24];
int N,mo,minute;

void Swap(int i,int j){
    int t;
    t=Sort[i];
    Sort[i]=Sort[j];
    Sort[j]=t;
    return;
}

void Init(){
    int i;
    for(i=0;i<24;i++){
        scanf("%d",&Fee[i]);
        Fee_Hour[i]=60*Fee[i];
        Fee_Date+=Fee_Hour[i];
    }//初始化费用数组 
    scanf("%d",&N);//读入N
    getchar(); 
    for(i=0;i<N;i++){
        rec[i].status=-1;
        Sort[i]=-1;
    }//数组准备 
    return;
}

void Get_Record(){
    int i,j;
    char temp[10];
    int d,h,m;
    int c;
    for(i=0;i<N;i++){
        scanf("%s %d:%d:%d:%d %s",&rec[i].name,&mo,&d,&h,&m,&temp);
        getchar();
        rec[i].d=d;
        rec[i].h=h;
        rec[i].m=m;
        rec[i].time=(d*24+h)*60+m;//标化分钟数
        if(temp[1]=='n'){
            rec[i].status=1;
        }else{
            rec[i].status=0;
        }
        Sort[i]=i;
        //读入数据
        for(j=i;j>0;j--){
            c=strcmp(rec[Sort[j]].name,rec[Sort[j-1]].name);
            if(c<0){
                Swap(j,j-1);
            }else if(c==0){
                if(rec[Sort[j]].time<rec[Sort[j-1]].time){
                    Swap(j,j-1);
                }else{
                    break;
                }
            }else{
                break;
            }
        }//冒泡排序 
    }
}

double Get_Mon(int begin,int end){
    int d,h,m;
    int i;
    double money=0.0;
    minute=0;
    minute+=(rec[end].d-rec[begin].d-1)*1440;
    money+=(rec[end].d-rec[begin].d-1)*Fee_Date;
    for(i=rec[begin].h+1;i<24;i++){
        minute+=60;
        money+=Fee_Hour[i];
    }//按小时 （开始） 
    for(i=0;i<rec[end].h;i++){
        minute+=60;
        money+=Fee_Hour[i];
    }//按小时 （结束） 
    for(i=rec[begin].m;i<60;i++){
        minute++;
        money+=Fee[rec[begin].h];
    }//按分钟 （开始） 
    for(i=0;i<rec[end].m;i++){
        minute++;
        money+=Fee[rec[end].h];
    }//按小时 （结束）
    return money/100.0;
} 

void Print(){
    int i=0;
    int begin=-1,end=-1;
    int flag,P;
    double sum,mon;
    while(i<N){
        flag=0;
        P=0;
        sum=0.0;
        while(1){
            if(flag==0){//需要begin,end扔掉 
                if(rec[Sort[i]].status==1){
                    begin=Sort[i];
                    flag=1;//需要end 
                }//
            }else{//需要end，但拿到begin更新 
                if(rec[Sort[i]].status==0){
                    end=Sort[i];
                    flag=0;//需要begin
                }else{
                    begin=Sort[i]; 
                } 
            }
            if(begin!=-1&&end!=-1){
                if(P==0){
                    printf("%s %02d\n",rec[Sort[i]].name,mo);
                    P++;
                }
                mon=Get_Mon(begin,end);
                sum+=mon;
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",rec[begin].d,rec[begin].h,rec[begin].m,rec[end].d,rec[end].h,rec[end].m,minute,mon);
                begin=-1;
                end=-1;
            }
            i++;
            if(strcmp(rec[Sort[i]].name,rec[Sort[i-1]].name)!=0||i>=N){//不一样了 
                if(P==1){
                    printf("Total amount: $%.2lf\n",sum);
                }
                break; 
            }
        }
    }
    return;
}

int main(){
    Init();
    Get_Record();
    Print();
    return 0;
}
