#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define maxn 10010

struct Student{
    string name;
    int Gp,Gmt,Gf,G;
    int vividmt,vividf,vivid;
}stu[maxn];

map<string,int> mp;
int P,M,N,num=0;

bool cmp(Student a,Student b){
    if(a.vivid!=b.vivid){
        return a.vivid>b.vivid;
    }else if(a.G!=b.G){
        return a.G>b.G;
    }else{
        return a.name<b.name;
    }
}

int main(){
    int i,b,c,vnum=0;
    string a;
    cin>>P>>M>>N;
    while(P--){
        cin>>a>>b;
        if(b<200){
            continue;
        }
        if(mp.find(a)==mp.end()){
            mp[a]=num;
            stu[num].Gp=b;
            stu[num].name=a;
            num++;
        }
    }
    while(M--){
        cin>>a>>b;
        if(mp.find(a)!=mp.end()){
            c=mp[a];
            stu[c].Gmt=b;
            stu[c].vividmt=1;
        }
    }
    while(N--){
        cin>>a>>b;
        if(mp.find(a)!=mp.end()){
            c=mp[a];
            stu[c].Gf=b;
            stu[c].vividf=1;
        }
    }
    for(i=0;i<num;i++){
        if(stu[i].vividf){
            if(stu[i].vividmt&&(stu[i].Gmt>stu[i].Gf)){
                stu[i].G=(int)(0.4*stu[i].Gmt+0.6*stu[i].Gf+0.5);
            }else{
                stu[i].G=stu[i].Gf;
            }
            if(stu[i].G>=60){
                stu[i].vivid=1;
                vnum++;
            }
        }
    }
    sort(stu,stu+num,cmp);
    for(i=0;i<vnum;i++){
        a=stu[i].name;
        cout<<a<<" "<<stu[i].Gp<<" ";
        if(stu[i].vividmt){
            cout<<stu[i].Gmt;
        }else{
            cout<<"-1";
        }
        cout<<" "<<stu[i].Gf<<" "<<stu[i].G<<endl;
    }
    return 0;
}
