#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 10010
int N,M;
struct Person{
    char ID[15];
    int score;
};
struct Room{
    int ID,num;
};
vector<Person> B,A,T;
int num[maxn],sum[maxn];
map<int,int> mp;
int seq=0;
vector<int> Datesum[maxn];

bool cmp1(Person a,Person b){
    if(a.score!=b.score){
        return a.score>b.score;
    }else{
        return strcmp(a.ID,b.ID)<0;
    }
}

bool cmp2(Room a,Room b){
    if(a.num!=b.num){
        return a.num>b.num;
    }else{
        return a.ID<b.ID;
    }
}

void Init(){
    int i,j;
    int site,score,date;
    char str[15];
    Person temp;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++){
        scanf("%s%d",str,&score);
        //等级 
        strcpy(temp.ID,str);
        temp.score=score;
        switch(str[0]){
            case 'B':{
                B.push_back(temp); 
                break;
            }
            case 'A':{
                A.push_back(temp); 
                break;
            }
            case 'T':{
                T.push_back(temp); 
                break;
            }
            default:{
                break;
            }
        }
        //考场 
        site=0;
        for(j=0;j<3;j++){
            site=site*10+str[1+j]-'0';
        }
        num[site]++;
        sum[site]+=score;
        //日期 
        date=0;
        for(j=0;j<6;j++){
            date=date*10+str[4+j]-'0';
        }
        if(mp.find(date)!=mp.end()){
            j=mp[date];
        }else{
            j=seq;
            mp[date]=seq++;
        }
        Datesum[j].push_back(site);
    }
    sort(B.begin(),B.end(),cmp1); 
    sort(A.begin(),A.end(),cmp1); 
    sort(T.begin(),T.end(),cmp1);
}

void Print1(){
    char C;
    int i;
    getchar();
    scanf("%c",&C);
    printf("%c\n",C);
    switch(C){
        case 'B':{
            for(i=0;i<B.size();i++){
                printf("%s %d\n",B[i].ID,B[i].score);
            }
            if(i==0){
                printf("NA\n");
            }
            break;
        }
        case 'A':{
            for(i=0;i<A.size();i++){
                printf("%s %d\n",A[i].ID,A[i].score);
            }
            if(i==0){
                printf("NA\n");
            }
            break;
        }
        case 'T':{
            for(i=0;i<T.size();i++){
                printf("%s %d\n",T[i].ID,T[i].score);
            }
            if(i==0){
                printf("NA\n");
            }
            break;
        }
        default:{
            printf("NA\n");
            break;
        }
    }
    return; 
}

void Print2(){
    int data;
    scanf("%d",&data);
    printf("%d\n",data);
    if(num[data]==0){
        printf("NA\n");
    }else{
        printf("%d %d\n",num[data],sum[data]);
    }
    return;
}

void Print3(){
    int data,i;
    Room temp;
    vector<Room> R;
    scanf("%d",&data);
    printf("%06d\n",data);
    if(mp.find(data)!=mp.end()){
        data=mp[data];
        sort(Datesum[data].begin(),Datesum[data].end());
        R.clear();
        temp.ID=Datesum[data][0];
        temp.num=1;
        for(i=1;i<Datesum[data].size();i++){
            if(Datesum[data][i]==temp.ID){
                temp.num++;
            }else{
                R.push_back(temp);
                temp.ID=Datesum[data][i];
                temp.num=1;
            }
        }
        R.push_back(temp);
        sort(R.begin(),R.end(),cmp2);
        for(i=0;i<R.size();i++){
            printf("%03d %d\n",R[i].ID,R[i].num);
        }
    }else{
        printf("NA\n");
    }
    return;
}
int main(){
    int i,ty;
    Init();
    for(i=1;i<=M;i++){
        printf("Case %d: ",i);
        scanf("%d",&ty);
        printf("%d ",ty);
        switch(ty){
            case 1:{
                Print1();
                break;
            }
            case 2:{
                Print2();
                break;
            }
            case 3:{
                Print3();
                break;
            }
        }
    }
    return 0;
}

