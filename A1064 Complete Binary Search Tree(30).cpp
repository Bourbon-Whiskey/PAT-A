#include<cstdio>
#include<algorithm>
#define maxn 1010
using namespace std;

int N,Seq[maxn],CBT[maxn],num=0;

void Inorder(int root){
    if(root>N){
        return;
    }
    Inorder(2*root);
    CBT[root]=Seq[num++];
    Inorder(2*root+1);
}

int main(){
    int i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&Seq[i]);
    }
    sort(Seq,Seq+N);
    Inorder(1);
    for(i=1;i<=N;i++){
        printf("%d",CBT[i]);
        if(i<N){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}
