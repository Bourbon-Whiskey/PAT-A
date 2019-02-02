#include<stdio.h>
int main(){
    int i=3,n;
    char a[15]="0123456789ABC";
    printf("#");
    while(i--){
        scanf("%d",&n);
        printf("%c%c",a[n/13],a[n%13]);
    }
    printf("\n");
    return 0;
}
