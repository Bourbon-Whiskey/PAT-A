#include<string.h>
#include<stdio.h>
#define maxn 260

int main(){
    char Sen[110][maxn+1];
    int len[110];
    char same[maxn];
    int length=0;
    int N,i,j;
    scanf("%d",&N);
    getchar();
    fgets(Sen[0],maxn,stdin);
    len[0]=strlen(Sen[0])-2;
    fgets(Sen[1],maxn,stdin);
    len[1]=strlen(Sen[1])-2;
    while((len[1]-length>=0)&&(len[0]-length>=0)&&(Sen[0][len[0]-length]==Sen[1][len[1]-length])){
        same[length]=Sen[0][len[0]-length];
        length++;
    }
    for(i=2;i<N;i++){
        fgets(Sen[i],maxn,stdin);
        len[i]=strlen(Sen[i])-2;
        for(j=0;j<length;j++){
            if(same[j]!=Sen[i][len[i]-j]){
                break;
            }
        }
        length=j;
    }
    if(length<=0){
        printf("nai\n");
    }else{
        do{
            length--;
            printf("%c",same[length]);
        }while(length>0);
        printf("\n");
    }
    return 0;
}
