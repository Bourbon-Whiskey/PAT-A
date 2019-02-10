#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

int M,N,S;
set<string> st;

int main(){
    int i;
    string temp;
    scanf("%d%d%d",&M,&N,&S);
    st.clear();
    for(i=1;i<=M;i++){
        cin>>temp;
        if(i==S){
            if(st.find(temp)!=st.end()){
                S++;
            }else{
                cout<<temp<<endl;
                st.insert(temp);
                S+=N;
            }
        }
    }
    if(st.size()==0){
        cout<<"Keep going..."<<endl;
    }
    return 0;
}
