#include<stdio.h>
struct People{
    char ID[20];
    int begin;
    int end;
}unlock,lock,temp;

int gettime(int hour,int min,int second){
    return 3600*hour+60*min+second;
}
void init(){
    unlock.begin=gettime(23,59,59)+1;
    lock.end=-1;
}

int main(){
    int M;
    int i;
    int hour,minute,second;
    init();
    scanf("%d",&M);
    getchar();
    for(i=0;i<M;i++){
        scanf("%s",&temp.ID);
        scanf(" %d:%d:%d",&hour,&minute,&second);
        temp.begin=gettime(hour,minute,second);
        scanf(" %d:%d:%d",&hour,&minute,&second);
        temp.end=gettime(hour,minute,second);
        getchar();
        if(temp.begin<unlock.begin){
            unlock=temp;
        }
        if(temp.end>lock.end){
            lock=temp;
        }
    }
    printf("%s %s\n",unlock.ID,lock.ID);
    return 0;
}
