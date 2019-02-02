#include<stdio.h>

#define MAXN 1010
#define last 540//结束时间,不包括 

struct Custom{
    int start;
    int dur;
    int end;
}cus[MAXN];//顾客 

struct Window{
    int queue[10];//队列 
    int front,rear;//队首出队，队尾入队 
    int nexttime;//下次队列处理时间 
    int num;//队中元素 
}win[25];

int M,N,K,Q;
int current;//当前进队顾客 
int T;//时间。 

void Init(){
    int i;
    scanf("%d%d",&N,&M);//N窗口数，M窗口排队数
    for(i=0;i<N;i++){
        win[i].nexttime=0;
        win[i].front=0;
        win[i].rear=0;
        win[i].num=0;
    }
    scanf("%d%d",&K,&Q);//K顾客数，Q询问数 
    for(i=1;i<=K;i++){
        scanf("%d",&cus[i].dur);
        cus[i].start=-1;
        cus[i].end=-1;//表明未服务
    }
    return;
}//初始化 

void Push(int L,int C){
    win[L].queue[win[L].rear]=C;
    win[L].rear=(win[L].rear+1)%M;
    win[L].num++;
    return;
}//加队 

void Op(int L){
    win[L].queue[win[L].front]=0;
    win[L].front=(win[L].front+1)%M;//队头元素指向改变 
    win[L].num--;//队列数减一 
    win[L].nexttime+=cus[win[L].queue[win[L].front]].dur;//队列L的下一次执行过程时间 
    cus[win[L].queue[win[L].front]].start=T;//更新顾客开始时间 
    cus[win[L].queue[win[L].front]].end=win[L].nexttime;//更新顾客结束时间
    if(current<K){
        current++;
        Push(L,current);
    }//若仍有未排队顾客则使其进队
    if(win[L].num==0){
        win[L].nexttime=last;
    }//队空，则将其置于结束位置。 
    
    return;
}

void Init_0(){
    int i,j;
    current=0;
    for(i=0;i<M;i++){//轮次 
        for(j=0;j<N;j++){//队名 
            Push(j,++current);//初始时一次压入
            if(i==0){//第一轮 
                win[j].nexttime+=cus[current].dur;//队列下一次执行时间 
                cus[current].start=T;//顾客服务开始时间 
                cus[current].end=win[j].nexttime;//顾客服务结束时间 
            }
            if(current>=K){
                return; 
            }
        }
    }
}//初始加队 

void print(int num){
    int t;
    if(cus[num].end==-1){
        printf("Sorry\n");
    }else{
        t=cus[num].end;
        printf("%02d:%02d\n",((t/60)+8),(t%60));
    }
}

int main(){
    int i,query;
    Init();
    Init_0();
    for(T=0;T<last;T++){
        for(i=0;i<N;i++){
            if(T>=win[i].nexttime){
                Op(i);//对队列进行操作 
            }
        }
    }
    for(i=0;i<Q;i++){
        scanf("%d",&query);
        print(query);
    } 
    return 0;
} 
