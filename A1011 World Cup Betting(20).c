#include<stdio.h>

int main(){
    double sum=0.65;
    double max,temp;
    int i,j,r;
    char RES[5]="WTL";
    for(i=0;i<3;i++){
        r=-1;
        max=-0.1;
        for(j=0;j<3;j++){
            scanf("%lf",&temp);
            if(temp>max){
                max=temp;
                r=j;
            }
        }
        printf("%c ",RES[r]);
        sum*=max;
    }
    printf("%.2lf",(sum-1)*2);
    return 0;
} 
