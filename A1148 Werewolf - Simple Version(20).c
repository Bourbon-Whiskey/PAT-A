#include<stdio.h>
#define maxn 110
int wolf[maxn],st[maxn];
int N;

int main(){
    int i,j,k;
    int w,lair;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        scanf("%d",&st[i]);
    }
    for(i=1;i<N;i++){
        wolf[i]=1;
        for(j=i+1;j<=N;j++){
            wolf[j]=1;
            w=0;
            lair=0;
            for(k=1;k<=N;k++){
                if(st[k]>0&&wolf[st[k]]==1){//lie
                    lair++;
                    if(k==i||k==j){
                        w++;
                    }
                }else if(st[k]<0&&wolf[-st[k]]==0){
                    lair++;
                    if(k==i||k==j){
                        w++;
                    }
                }
            }
            if(lair==2&&w==1){
                printf("%d %d\n",i,j);
                return 0;
            }
            wolf[j]=0;
        }
        wolf[i]=0;
    }
    printf("No Solution\n");
    return 0;
}
