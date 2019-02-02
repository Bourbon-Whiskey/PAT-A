#include<stdio.h>

#define MAXN 10010
#define INF 100000000
#define OP 8*3600
#define CL 17*3600

struct Custom{
    int arrive,service;//到达时间，服务时间
}cus[MAXN];//顾客

int Sort[MAXN]; 

int win[110];//窗口结束时间 

int N,K;//顾客数，窗口数
int num=0;//有效数 
int T=0;//时间 

void Swap(int i,int j){
    int t;
    t=Sort[i];
    Sort[i]=Sort[j];
    Sort[j]=t;
    return;
}//交换 

void Init(){
    int i;
    int h,m,s,work,arr;
    scanf("%d%d",&N,&K);
    while(N--){
        scanf("%d:%d:%d %d",&h,&m,&s,&work);
        arr=(h*60+m)*60+s;
        if(arr>CL){
            continue;
        }//到达时间晚于关门时间，不被记录，直接略过 
        cus[num].arrive=arr;
        cus[num].service=work*60;
        //读入 
        Sort[num]=num;
        for(i=num;i>0;i--){
            if(cus[Sort[i]].arrive<cus[Sort[i-1]].arrive){
                Swap(i,i-1);
            }else{
                break;
            }
        }//冒泡排序 
        num++;
    }
    for(i=0;i<K;i++){
        win[i]=OP;
    }
    return;
}

void Print(){
    int i,j,Wait=0;
    int jm,Min_Time; 
    for(i=0;i<num;i++){
        jm=-1;
        Min_Time=INF;
        for(j=0;j<K;j++){
            if(win[j]<Min_Time){
                jm=j;
                Min_Time=win[j];
            }
        }
        if(win[jm]>cus[Sort[i]].arrive){//来得早 
            Wait+=win[jm]-cus[Sort[i]].arrive;//等待时间 
            win[jm]+=cus[Sort[i]].service;//更新窗口 
        }else{
            win[jm]=cus[Sort[i]].arrive+cus[Sort[i]].service;//窗口时间更新为服务完i； 
        } 
    } 
    printf("%.1lf\n",(1.0*Wait)/(60.0*num));
    return;
}

int main(){
    int i; 
    Init();
    Print();
    return 0;
}
