#include<stdio.h>
#include<string.h>

int main(){
    char week[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    char A[70],B[70];
    int i,lenA,lenB;
    scanf("%s",&A);
    scanf("%s",&B);
    for(i=0;;i++){
        if(A[i]==B[i]){
            if(A[i]>='A'&&A[i]<='G'){
                printf("%s ",week[A[i]-'A']);
                break;
            }
        }
    }
    for(i++;;i++){
        if(A[i]==B[i]){
            if(A[i]>='0'&&A[i]<='9'){
                printf("%02d:",A[i]-'0');
                break;
            }
            if(A[i]>='A'&&A[i]<='N'){
                printf("%02d:",A[i]-'A'+10);
                break;
            }
        }
    }
    scanf("%s",&A);
    scanf("%s",&B);
    for(i=0;;i++){
        if(A[i]==B[i]){
            if(A[i]>='A'&&A[i]<='Z'||A[i]>='a'&&A[i]<='z'){
                printf("%02d\n",i);
                break;
            }
        }
    }
    return 0;
}
