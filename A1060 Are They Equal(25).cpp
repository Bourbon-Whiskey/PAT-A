#include<iostream>
#include<string>
using namespace std;
int N,e;

string Deal(string a){
    int k=0;
    int num=0;
    string res;
    e=0;
    while(a.length()>0&&a[0]=='0'){
        a.erase(a.begin());
    }
    if(a[0]=='.'){
        a.erase(a.begin());
        while(a.length()>0&&a[0]=='0'){
            a.erase(a.begin());
            e--;
        }
    }else{
        while(k<a.length()&&a[k]!='.'){
            k++;
            e++;
        }
        if(k<a.length()){
            a.erase(a.begin()+k);
        }
    }
    if(a.length()==0){
        e=0;
    }
    while(num<N){
        if(num<a.length()){
            res+=a[num];
        }else{
            res+='0';
        }
        num++;
    }
    return res;
}


int main(){
    string A,B;
    int e1;
    cin>>N>>A>>B;
    A=Deal(A);
    e1=e;
    B=Deal(B);
    if(A==B&&e1==e){
        cout<<"YES 0."<<A<<"*10^"<<e<<endl;
    }else{
        cout<<"NO 0."<<A<<"*10^"<<e1<<" 0."<<B<<"*10^"<<e<<endl;
    }
    return 0;
}
