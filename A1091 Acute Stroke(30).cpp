#include<cstdio>
#include<queue>
using namespace std;

int M,N,L,T;
int G[1288][130][62],inq[1288][130][62];
int X[6]={-1,1,0,0,0,0},Y[6]={0,0,-1,1,0,0},Z[6]={0,0,0,0,-1,1};
int sum;
struct Node{
    int x,y,z;
};

void Init(){
    int i,j,k;
    scanf("%d%d%d%d",&M,&N,&L,&T);
    for(k=0;k<L;k++){
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                scanf("%d",&G[i][j][k]);
            }
        }
    }
    sum=0;
}

int check(int x,int y,int z){
    if(x<0||x>=M||y<0||y>=N||z<0||z>=L){
        return 0;
    }
    if(G[x][y][z]==0||inq[x][y][z]==1){
        return 0;
    }
    return 1;
}

void BFS(int x,int y,int z){
    int count=0;
    int tx,ty,tz,i;
    Node temp,top;
    queue<Node> q;
    temp.x=x;
    temp.y=y;
    temp.z=z;
    inq[x][y][z]=1;
    q.push(temp);
    while(!q.empty()){
        top=q.front();
        q.pop();
        count++;
        for(i=0;i<6;i++){
            tx=top.x+X[i];
            ty=top.y+Y[i];
            tz=top.z+Z[i];
            if(check(tx,ty,tz)){
                temp.x=tx;
                temp.y=ty;
                temp.z=tz;
                inq[tx][ty][tz]=1;
                q.push(temp);
            }
        }
    }
    if(count>=T){
        sum+=count;
    }
}

void Op(){
    int i,j,k;
    for(k=0;k<L;k++){
        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                if(check(i,j,k)){
                    BFS(i,j,k);
                }
            }
        }
    }
    printf("%d\n",sum);
}

int main(){
    Init();
    Op();
    return 0;
}
