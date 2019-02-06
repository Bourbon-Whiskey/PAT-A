#include<stdio.h>
#define maxn 10010
char num[maxn],frac[maxn];

int main(){
    int i,fnum;
    int exp=0,zf;
    fgets(num,maxn,stdin);
    fnum=0;
    if(num[0]=='-'){
        printf("-");
    }
    for(i=1;i<maxn;i++){
        if(num[i]=='.'){
            continue;
        }
        if(num[i]=='E'){
            break;
        }
        frac[fnum++]=num[i];
    }
    i++;
    if(num[i]=='+'){
        zf=1;
    }else{
        zf=-1;
    }
    i++;
    while(num[i]>='0'&&num[i]<='9'){
        exp=exp*10+num[i]-'0';
        i++;
    }
    exp*=zf;
    if(exp<0){
        exp++;
        printf("0.");
        while(exp<0){
            printf("0");
            exp++;
        }
        printf("%s\n",frac);
    }else{
        i=0;
        while(i<=exp){
            if(i>=fnum){
                printf("0");
            }else{
                printf("%c",frac[i]);
            }
            i++;
        }
        if(i<=fnum-1){
            printf(".");
        }
        while(i<fnum){
            printf("%c",frac[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
