#include<iostream>
#include<string>
#include<map>
using namespace std;

bool check(char c){
    if(c>='0'&&c<='9'){
        return true;
    }
    if(c>='A'&&c<='Z'){
        return true;
    }
    if(c>='a'&&c<='z'){
        return true;
    }
    return false;
}

int main(){
    int i,max=0;
    map<string,int>count;
    string str,word,fre;
    map<string,int>::iterator it;
    getline(cin,str);
    i=0;
    while(i<str.length()){
        word.clear();
        while(i<str.length()&&check(str[i])==true){
            if(str[i]>='A'&&str[i]<='Z'){
                str[i]+=32;
            }
            word+=str[i];
            i++;
        }
        if(word!=""){
            if(count.find(word)==count.end()){
                count[word]=1;
            }else{
                count[word]++;
            }
        }
        while(i<str.length()&&check(str[i])==false){
            i++;
        }
    }
    for(it=count.begin();it!=count.end();it++){
        if(it->second>max){
            max=it->second;
            fre=it->first;
        }
    }
    cout<<fre<<' '<<max<<endl;
    return 0; 
}
