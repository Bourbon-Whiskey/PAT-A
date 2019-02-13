#include<cstdio>
#include<map>
using namespace std;
#define maxn 10010

int preOrder[maxn];

map<int,int> mp;
int M,N;

void Init(){
    int i,a;
    scanf("%d%d",&M,&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        mp[a]=i;
    }
    for(i=0;i<N;i++){
        scanf("%d",&preOrder[i]);
    }
}

void Check(){
    int i,a,b,flag1=0,flag2=0;
    int sa,sb,sc;
    scanf("%d%d",&a,&b);
    if(mp.find(a)==mp.end()){
        flag1++;
    }
    if(mp.find(b)==mp.end()){
        flag2++;
    }
    if(flag1||flag2){
        if(flag1&&flag2){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(flag1){
            printf("ERROR: %d is not found.\n",a);
        }else{
            printf("ERROR: %d is not found.\n",b);
        }
        return;
    }
    sa=mp[a];
    sb=mp[b];
    for(i=0;i<N;i++){
        sc=mp[preOrder[i]];
        if(((sa<sc)&&(sb>sc))||((sa>sc)&&(sb<sc))){
            printf("LCA of %d and %d is %d.\n",a,b,preOrder[i]);
            return;
        }else if(sa==sc){
            printf("%d is an ancestor of %d.\n",a,b);
            return;
        }else if(sb==sc){
            printf("%d is an ancestor of %d.\n",b,a);
            return;
        }
    }
}

int main(){
    Init();
    while(M--){
        Check();
    }
    return 0;
}

