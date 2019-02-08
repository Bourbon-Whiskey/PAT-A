#include<cstdio>
#include<cmath>
#include<algorithm>
#define maxn 10010
using namespace std;

struct Node{
    int seq;
    int vivid;
}G[maxn][maxn];

bool cmp(int a,int b){
    return a>b;
}

int num[maxn];
int N;
int m,n;

void Init(){
    int i;
    scanf("%d",&N);
    n=(int)sqrt(1.0*N);
    for(i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+N,cmp);
    while(1){
        if(N%n==0){
            m=N/n;
            break;
        }
        n--;
    }
    for(i=0;i<=m;i++){
        G[i][n].vivid=1;
    }
    for(i=0;i<=n;i++){
        G[m][i].vivid=1;
    }
}

void Op(){
    int k=0;
    int i=0,j=0;
    while(k<N){
        while(G[i][j].vivid==0){
            //右移
            G[i][j].vivid=1;
            G[i][j].seq=k++;
            j++;
        };
        //撞墙退出；
        i++,j--;
        while(G[i][j].vivid==0){
            //下移
            G[i][j].vivid=1;
            G[i][j].seq=k++;
            i++;
        };
        //撞墙退出
        i--,j--;
        while(j>=0&&G[i][j].vivid==0){
            //左移
            G[i][j].vivid=1;
            G[i][j].seq=k++;
            j--;
        };
        //撞墙或出界退出
        i--,j++;
        while(i>=0&&G[i][j].vivid==0){
            //上移
            G[i][j].vivid=1;
            G[i][j].seq=k++;
            i--;
        };
        //撞墙或出界退出
        i++,j++;
    }
}

void Print(){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",num[G[i][j].seq]);
            if(j<n-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
}

int main(){
    Init();
    Op();
    Print();
    return 0;
}
