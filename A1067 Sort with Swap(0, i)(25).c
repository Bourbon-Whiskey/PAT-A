#include<stdio.h>
#define maxn 100010
int pos[maxn];
void Swap(int a,int b){
    int temp;
    temp=pos[a];
    pos[a]=pos[b];
    pos[b]=temp;
}

int main(){
    int N,left,count=0;
    int i,v,k=0;
    scanf("%d",&N);
    left=N-1;
    for(i=0;i<N;i++){
        scanf("%d",&v);
        pos[v]=i;
        if(pos[i]==i&&i!=0){
            left--;
        }
    }
    while(left>0){
        if(pos[0]==0){
            while(k<N){
                k++;
                if(pos[k]!=k){
                    Swap(0,k);
                    count++;
                    break;
                }
            }
        }else{
            Swap(0,pos[0]);
            count++;
            left--;
        }
    }
    printf("%d\n",count);
    return 0;
}
