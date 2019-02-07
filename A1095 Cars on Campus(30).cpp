#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int N,K;


struct Record{
    string plate_number;
    int time;
    int status;
    int vivid;
};

bool cmp1(Record a,Record b){
    if(a.plate_number!=b.plate_number){
        return a.plate_number<b.plate_number;
    }else{
        return a.time<b.time;
    }
}//记录排序 

bool cmp2(Record a,Record b){
    if(a.vivid!=b.vivid){
        return a.vivid>b.vivid;
    }else{
        return a.time<b.time;
    }
}//记录排序 

vector<Record> Seq;
map<string,int> mp;
vector<string> Max;
int M=-1; 

int main(){
    char PN[10],st[5];
    int h,m,s;
    int vivid=0,count=0;
    int i,j,time,current;
    Record temp;
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++){
        scanf("%s %d:%d:%d %s",PN,&h,&m,&s,st);
        temp.plate_number=PN;
        temp.time=3600*h+60*m+s;
        temp.vivid=0;
        if(st[0]=='i'){
            temp.status=0;//in
        }else{
            temp.status=1;//out
        }
        Seq.push_back(temp);
    }
    sort(Seq.begin(),Seq.end(),cmp1);
    for(i=0;i<N;){
        if(Seq[i].plate_number==Seq[i+1].plate_number&&Seq[i].status==0&&Seq[i+1].status==1){
            Seq[i].vivid=1;
            Seq[i+1].vivid=1;
            vivid+=2;
            if(mp.find(Seq[i].plate_number)==mp.end()){
                mp[Seq[i].plate_number]=Seq[i+1].time-Seq[i].time;
            }else{
                mp[Seq[i].plate_number]+=Seq[i+1].time-Seq[i].time;
            }
            if(mp[Seq[i].plate_number]>M){
                Max.clear();
                Max.push_back(Seq[i].plate_number);
                M=mp[Seq[i].plate_number];
            }else if(mp[Seq[i].plate_number]==M){
                Max.push_back(Seq[i].plate_number);
            }
            i+=2;
        }else{
            i+=1;
        }
    }
    sort(Seq.begin(),Seq.end(),cmp2);
    j=0,current=0;
    Seq.push_back(temp);
    Seq[vivid].time=100000000;
    for(i=0;i<K;i++){
        scanf("%d:%d:%d",&h,&m,&s);
        time=3600*h+60*m+s;
        if(current>time){
            printf("%d\n",count);
        }else{
            for(;j<vivid;){
                if(current>time){
                    break;
                }else{
                    if(Seq[j].status==0){
                        count++;
                    }else{
                        count--;
                    }
                    j++;
                    current=Seq[j].time;
                    if(current>time){
                        printf("%d\n",count);
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<Max.size();i++){
        cout<<Max[i]<<" ";
    }
    h=M/3600;
    m=M%3600;
    s=m%60;
    m=m/60;
    printf("%02d:%02d:%02d\n",h,m,s);
    return 0;
}
