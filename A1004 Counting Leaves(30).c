#include<stdio.h>

#define MAXN 110
struct Node{
    int height;
    int num;
    int children[MAXN];
}node[MAXN];

int N,M;
int H[MAXN],max=-1; 
 
void DFS(int root,int height){
    int i;
    node[root].height=height;
    for(i=0;i<node[root].num;i++){
        DFS(node[root].children[i],height+1);
    }
    return;
}

void init(){
    int i,j,temp;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d",&temp);
        scanf("%d",&node[temp].num);
        for(j=0;j<node[temp].num;j++){
            scanf("%d",&node[temp].children[j]);
        }
    }
    for(i=0;i<MAXN;i++){
        H[i]=0;
    }
    return;
}

void print(){
    int i;
    for(i=1;i<=N;i++){
        if(node[i].num==0){
            H[node[i].height]++;
            if(max<node[i].height){
                max=node[i].height;
            }
        }
    }
    for(i=0;i<=max;i++){
        printf("%d",H[i]);
        if(i<max){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return;
}

int main(){
    init();
    DFS(1,0);
    print();
    return 0;
}
