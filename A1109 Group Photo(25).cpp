#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N,K;
int first,rest;
struct Person{
    char name[20];
    int height;
}P[20010];

int G[12][10010];

bool cmp(Person a,Person b){
    if(a.height!=b.height){
        return a.height>b.height;
    }else{
        return strcmp(a.name,b.name)<0;
    }
}

void Init(){
    int i;
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++){
        scanf("%s %d",P[i].name,&P[i].height);
    }
    sort(P,P+N,cmp);
    rest=N/K;
    first=N-rest*(K-1);
}

void Op(){
    int i,j;
    int seq=0;
    int left,right;
    left=first/2,right=first/2;
    if(seq<N){
        G[0][left]=seq++;
    }
    for(j=1;j<first;j++){
        if(j%2){
            G[0][--left]=seq++;
        }else{
            G[0][++right]=seq++;
        }
    }
    for(i=1;i<K;i++){
        left=rest/2,right=rest/2;
        if(seq<N){
            G[i][left]=seq++;
        }   
        for(j=1;j<rest;j++){
            if(j%2){
                G[i][--left]=seq++;
            }else{
                G[i][++right]=seq++;
            }
        }
    }
}

void Print(){
    int i,j;
    for(j=0;j<first;j++){
        printf("%s",P[G[0][j]].name);
        if(j<first-1){
            printf(" ");
        }
    }
    printf("\n");
    for(i=1;i<K;i++){
        for(j=0;j<rest;j++){
            printf("%s",P[G[i][j]].name);
            if(j<rest-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(){
    Init();
    Op();
    Print();
    return 0;
}
