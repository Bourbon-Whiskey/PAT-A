#include<stdio.h>
#include<math.h>
#define maxn 1010
#define err 1E-7
int main(){
    double a[maxn]={0.0};
    int num=0,max=0;
    int k,i,exp;
    double coe;
    scanf("%d",&k);
    num=k;
    for(i=0;i<k;i++){
        scanf("%d%lf",&exp,&coe);
        a[exp]=coe;
        max=(exp>max?exp:max);
    }
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d%lf",&exp,&coe);
        if(fabs(a[exp])<err){
            max=(exp>max?exp:max);
            num++; 
        }
        a[exp]=a[exp]+coe;
        if(fabs(a[exp])<err){
            num--;
        }
    }
    printf("%d",num);
    while(max>=0){
        if(fabs(a[max])>=err){
            printf(" %d %.1f",max,a[max]);
            num--;
        }
        if(num<=0){
            break;
        }
        max--;
    }
    printf("\n");
    return 0;
}
