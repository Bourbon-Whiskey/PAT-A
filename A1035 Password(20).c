#include<stdio.h>
#include<string.h>
#define maxn 1010

struct Password{
    char id[15],pass[15];
}PW[maxn];

int main(){
    int c[maxn];
    int cnum=0;
    int len,i,j,flag;
    int N;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        getchar();
        scanf("%s %s",&PW[i].id,&PW[i].pass);
        flag=0;
        len=strlen(PW[i].pass);
        for(j=0;j<len;j++){
            switch(PW[i].pass[j]){
                case '1':{
                    PW[i].pass[j]='@';
                    flag=1;
                    break;
                }
                case '0':{
                    PW[i].pass[j]='%';
                    flag=1;
                    break;
                }
                case 'l':{
                    PW[i].pass[j]='L';
                    flag=1;
                    break;
                }
                case 'O':{
                    PW[i].pass[j]='o';
                    flag=1;
                    break;
                }
            }
        }
        if(flag){
            c[cnum++]=i;
        }
    }
    if(cnum==0){
        if(N==1){
            printf("There is 1 account and no account is modified\n");
        }else{
            printf("There are %d accounts and no account is modified\n",N);
        }
    }else{
        printf("%d\n",cnum);
        for(i=0;i<cnum;i++){
            printf("%s %s\n",PW[c[i]].id,PW[c[i]].pass);
        }
    }
    return 0;
}
