#include<stdio.h>
int hash[510];
int main(){
    int N,M;
    int i,a;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        hash[a]++;
    }
    i=(M-500)>0?(M-500):0;
    for(;i<=500;i++){
        if((hash[i]--)&&hash[M-i]){
            printf("%d %d\n",i,M-i);
            break;
        }else{
            hash[i]++;
        }
    }
    if(i>500){
        printf("No Solution\n");
    }
    return 0;
} 
