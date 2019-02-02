#include<cstdio>
#include<algorithm>
#define maxn 10010
#define INF 100000000
#define Begin_time 28800 //大于等于 
#define End_time 75600//小于 
using namespace std;
//每叫到一名顾客
//如果已服务，叫下一个 
//如为vip：
//先查找空闲的vip桌，如没有，查找空闲的普桌，如没有，
//查找最小等待时间的桌子并加入
//如为普客：
//查找最小的空闲桌，加入；
//如无空闲桌则查找等待时间最短的桌，如为普桌，加入，如为vip桌，查看是否有vip排队，
//有则请vip使用，并从1开始找等待时间最短的桌 
struct Player{
    int arrive_time;//s到达时间 
    int seriving_time;//s，接收服务时间
    int wait_time;//s,等待时间 
    int service_time;//s,服务时间 
    int Player_type;//1vip,0普通 
    int served;//0未服务，1服务过 
}player[maxn];

struct Table{
    int serve_num;//服务数量
    int end_time;//当前服务结束时间 
    int table_type;//1vip，0普通 
}table[110];

int TQueuevip[110];//记录vip桌号 
int TQueueord[110];//记录普桌号
int vtnum=0,otnum=0;

int Vplayer[maxn];//vip编号 
int vipnum=0;//vip数量
int pfront=0,vfront=0;//当前队列进行情况，首客，首个vip 

int current_time;//记录当前时间 

int N,K,M;//玩家数，桌子数，vip桌数 

bool cmp1(Player a,Player b){
    return a.arrive_time<b.arrive_time;
}

bool cmp2(Player a,Player b){
    if(a.served!=b.served){
        return a.served>b.served;
    }else{
        return a.seriving_time<b.seriving_time;
    }
}

void Init(){
    int i;
    int h,m,s,st,vipno;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d:%d:%d %d %d",&h,&m,&s,&st,&player[i].Player_type);
        player[i].arrive_time=h*3600+m*60+s;
        player[i].served=0;
        player[i].service_time=(st>120?120:st)*60;
    }
    sort(player,player+N,cmp1);
    for(i=0;i<N;i++){
        if(player[i].Player_type==1){
            Vplayer[vipnum++]=i;
        }//记录vip位置 
    }
    scanf("%d%d",&K,&M);
    for(i=0;i<M;i++){
        scanf("%d",&vipno);
        table[vipno].table_type=1;
    }
    for(i=1;i<=K;i++){
        table[i].end_time=Begin_time;
        table[i].serve_num=0;
        if(table[i].table_type==1){
            TQueuevip[vtnum++]=i;//插入vip桌 
        }else{
            TQueueord[otnum++]=i;//插入普桌 
        }
    }
}


void Sit_down(int cus,int no){//第cus号球员入座no号桌子 
//    pfront++;//队列标记移动
    if(player[cus].arrive_time>=table[no].end_time){
        player[cus].seriving_time=player[cus].arrive_time;//来时立即服务
    }else{
        player[cus].seriving_time=table[no].end_time;//等待后加入 
    }
    current_time=player[cus].seriving_time;//更新当前时间 
    if(current_time>=End_time){
        return;//如到达服务时到达关店时间，不执行后续活动 
    }
    //更新球员情况 
    player[cus].wait_time=player[cus].seriving_time-player[cus].arrive_time;
    //等待时间
    player[cus].served=1;//服务已接受过
    //更新桌子情况
    table[no].end_time=player[cus].seriving_time+player[cus].service_time;
    table[no].serve_num++;
    return;
} 
void Find_TtoV(int cus){//给cus号vip找桌子 
    int no=-1,min=INF;
    int i;
    pfront++;
    vfront++;//vip队列位置移动
    //找空vip 
    for(i=0;i<vtnum;i++){
        no=TQueuevip[i];
        if(table[no].end_time<=player[cus].arrive_time){
            //来得巧，有空vip桌
            Sit_down(cus,no);//该顾客坐在no号位置 
            return;
        } 
    }
    //找空普桌
    for(i=0;i<otnum;i++){
        no=TQueueord[i];
        if(table[no].end_time<=player[cus].arrive_time){
            //来得巧，有空普桌
            Sit_down(cus,no);//该顾客坐在no号位置 
            return;
        }
    }
    //找最小号桌 
    for(i=1;i<=K;i++){
        if(table[i].end_time<min){
            no=i;
            min=table[no].end_time;
        }
    }//找最小桌
    Sit_down(cus,no);//该顾客坐在no号位置
    return; 
}

void Find_TtoO(int cus){//给cus号普客找桌子 
    int i;
    int no,min,vipID;
    //找空位，它排第一位，如找到空位立即入座，队中定无等待中vip 
    pfront++;
    for(i=1;i<=K;i++){
        if(table[i].end_time<=player[cus].arrive_time){
            Sit_down(cus,i);//该顾客坐在i号位置
            return;
        }
    }
    while(1){
        no=-1,min=INF;
        for(i=1;i<=K;i++){
            if(table[i].end_time<min){
                no=i;
                min=table[no].end_time;
            }
        }//找最小桌
        if(table[no].table_type==1){//找到vip桌 
            if(vfront<vipnum){//仍有vip 
                vipID=Vplayer[vfront];//排在最前的vip 
                if(table[no].end_time>player[vipID].arrive_time){//有vip排队 
                    Sit_down(vipID,no);//队首VIP入座
                    vfront++;
                    continue;//继续循环 
                } 
            }    
        }
        Sit_down(cus,no);//该顾客坐在no号位置
        break; 
    }
    return;
}

void Print(){
    int i;
    int arr,ser,wai;
    int h1,m1,s1,h2,m2,s2;
    sort(player,player+N,cmp2);
    for(i=0;i<N;i++){
        if(player[i].served==0){
            break;
        }//未服务过
        arr=player[i].arrive_time;
        ser=player[i].seriving_time;
        wai=player[i].wait_time;
        h1=arr/3600;
        h2=ser/3600;
        m1=(arr%3600)/60;
        m2=(ser%3600)/60;
        s1=arr%60;
        s2=ser%60;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",h1,m1,s1,h2,m2,s2,(wai+30)/60);
    }
    for(i=1;i<=K;i++){
        printf("%d",table[i].serve_num);
        if(i==K){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    return;
}

int main(){
    Init();
    while(pfront<N){
        if(player[pfront].served==1){
            pfront++;
            continue;//读到已入座的vip 
        }
        if(player[pfront].Player_type==1){//排头pfront 
            Find_TtoV(pfront);//读入排头 
        }else{
            Find_TtoO(pfront);//读入排头 
        }
        if(current_time>=End_time){
            break;
        }
    }
    Print();
}
