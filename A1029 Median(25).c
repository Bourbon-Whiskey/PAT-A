#include<stdio.h>
#define maxn 200010

int main(){
    int n1,n2,mid;
    int a[maxn],b;
    int i,j,INF=0x7fffffff;
    scanf("%d",&n1);
    for(i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    a[i]=INF;
    scanf("%d",&n2);
    mid=(n1+n2+1)/2;
    n2--;
    i=0,j=0;
    scanf("%d",&b);
    while(--mid){
        if(a[i]<b){
            i++;
        }else{
            if(j<n2){
                scanf("%d",&b);
                j++;
            }else{
                b=INF;
            } 
        }
    }
    printf("%d\n",a[i]<b?a[i]:b);
    return 0;
}
