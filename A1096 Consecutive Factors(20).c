#include<stdio.h>
#include<math.h>

int main(){
    int i,j,temp;
    int n,first=0,len=0,sq;
    scanf("%d",&n);
    sq=(int)sqrt(1.0*n);
    for(i=2;i<=sq;i++){
        temp=1;
        for(j=i;j<=sq;j++){
            temp*=j;
            if(n%temp!=0){
                break;
            }
        }
        if(j-i>len){
            len=j-i;
            first=i;
        }
    }
    if(first==0){
        printf("1\n%d\n",n);
    }else{
        printf("%d\n",len);
        for(j=0;j<len;j++){
            printf("%d",first++);
            if(j<len-1){
                printf("*");
            }else{
                printf("\n");
            }
        }
    }
    return 0;
}
