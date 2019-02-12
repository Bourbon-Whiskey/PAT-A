#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define maxn 100010

map<string,int> mp;
int num=0;

struct Node{
    string name;
    int TWS,Ns;
    double T;
}S[maxn];

bool cmp(Node a,Node b){
    if(a.TWS!=b.TWS){
        return a.TWS>b.TWS;
    }else if(a.Ns!=b.Ns){
        return a.Ns<b.Ns;
    }else{
        return a.name<b.name;
    }
}

int main(){
    int N,G,t;
    int i=0,now=-1,nowR=1;
    string ID,school;
    cin>>N;
    while(N--){
        cin>>ID>>G>>school;
        for(i=0;i<school.length();i++){
            if(school[i]>='A'&&school[i]<='Z'){
                school[i]=school[i]-'A'+'a';
            }
        }
        if(mp.find(school)==mp.end()){
            t=num;
            S[t].name=school;
            mp[school]=num++;
        }else{
            t=mp[school];
        }
        if(ID[0]=='T'){
            S[t].T+=1.5*G;
        }else if(ID[0]=='B'){
            S[t].T+=2.0*G/3.0;
        }else{
            S[t].T+=1.0*G;
        }
        S[t].Ns++;
    }
    for(i=0;i<num;i++){
        S[i].TWS=(int)S[i].T;
    } 
    sort(S,S+num,cmp);
    cout<<num<<endl;
    for(i=0;i<num;i++){
        if(S[i].TWS==now){
            cout<<nowR;
        }else{
            cout<<i+1;
            now=S[i].TWS;
            nowR=i+1;
        }
        cout<<" "<<S[i].name<<" "<<(int)S[i].TWS<<" "<<S[i].Ns<<endl;
    }
    return 0;
}
