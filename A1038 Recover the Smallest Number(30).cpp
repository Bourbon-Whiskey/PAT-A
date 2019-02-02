#include<iostream>
#include<algorithm>
#include<string>
#define maxn 10010
using namespace std;
bool cmp(string a,string b){
    return a+b<b+a;
}

int main(){
    int i,N;
    string a[maxn],sum;
    cin>>N;
    sum.clear();
    for(i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N,cmp);
    for(i=0;i<N;i++){
        sum+=a[i];
    }
    while(sum.size()!=0&&sum[0]=='0'){
        sum.erase(sum.begin());
    }
    if(sum.size()==0){
        cout<<"0"<<endl;
    }else{
        cout<<sum<<endl;
    }
    return 0;
}
