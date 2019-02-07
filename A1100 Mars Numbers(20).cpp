#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;

char one[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char dec[13][5]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> mp;

int N;
void Init(){
    mp["tret"]=0;
    mp["jan"]=1;
    mp["feb"]=2;
    mp["mar"]=3;
    mp["apr"]=4;
    mp["may"]=5;
    mp["jun"]=6;
    mp["jly"]=7;
    mp["aug"]=8;
    mp["sep"]=9;
    mp["oct"]=10;
    mp["nov"]=11;
    mp["dec"]=12;
    mp["tam"]=13;
    mp["hel"]=26;
    mp["maa"]=39;
    mp["huh"]=52;
    mp["tou"]=65;
    mp["kes"]=78;
    mp["hei"]=91;
    mp["elo"]=104;
    mp["syy"]=117;
    mp["lok"]=130;
    mp["mer"]=143;
    mp["jou"]=156;
    scanf("%d",&N);
    getchar();
}

void numtochar(char a[]){
    int i=0,n=0;
    int len=strlen(a);
    while(i<len){
        n=n*10+a[i]-'0';
        i++;
    }
    if(n==0){
        printf("tret\n");
        return;
    }
    if(n>12){
        printf("%s",dec[n/13]);
        n%=13;
        if(n>0){
            printf(" ");
        }else{
            printf("\n");
            return;
        }
    }
    if(n>0){
        printf("%s\n",one[n]);
    }
}

void chartonum(char a[]){
    int i,j=0;
    int sum=0;
    string c;
    int len=strlen(a);
    char b[10];
    if(len>6){
        i=0;
        while(a[j]!=' '){
            b[i++]=a[j];
            j++;
        }
        b[i]=0;
        c=b;
        sum+=mp[c];
        j++;
    }
    i=0;
    while(j<len){
        b[i++]=a[j];
        j++;
    }
    b[i]=0;
    c=b;
    sum+=mp[c];
    printf("%d\n",sum);
}

int main(){
    int i,len;
    char a[20];
    Init();
    for(i=0;i<N;i++){
        fgets(a,20,stdin);
        len=strlen(a);
        a[len-1]=0;
        if(a[0]>='0'&&a[0]<='9'){
            numtochar(a);
        }else{
            chartonum(a);
        }
    }
}
