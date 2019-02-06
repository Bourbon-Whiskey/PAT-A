#include<stdio.h>
int main(){
    int G1,G2,G3,S1,S2,S3,K1,K2,K3;
    scanf("%d.%d.%d %d.%d.%d",&G1,&S1,&K1,&G2,&S2,&K2);
    K3=(K1+K2)%29;
    S3=(K1+K2)/29;
    S3=S3+S1+S2;
    G3=S3/17;
    S3=S3%17;
    G3=G1+G2+G3;
    printf("%d.%d.%d\n",G3,S3,K3);
    return 0;
}
