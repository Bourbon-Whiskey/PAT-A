#include<cstdio>
#include<vector>
#define maxn 1010
using namespace std;
 
struct mouse{
    int weight;
    int rank;
}mice[maxn]; 

int main(){
    int NP,NG;
    int Rat,Group;
    int i,j,k,front,current,u,max;
    vector<int> Seq,temp;
    scanf("%d%d",&NP,&NG);
    for(i=0;i<NP;i++){
        scanf("%d",&mice[i].weight);
    }
    for(i=0;i<NP;i++){
        scanf("%d",&j);
        Seq.push_back(j);
    }
    Rat=NP;
    while(1){
        Group=(Rat+NG-1)/NG;//组数
        front=0;
        temp.clear();
        for(i=0;i<Group;i++){
            u=-1,max=-1;
            for(j=0;j<NG;j++){
                current=Seq[front++];
                mice[current].rank=Group+1;
                if(mice[current].weight>max){
                    max=mice[current].weight;
                    u=current;
                }
                if(front==Rat){
                    break;
                }
            }
            temp.push_back(u);
        }
        Rat=Group;
        Seq=temp;
        if(Rat==1){
            mice[Seq[0]].rank=1;
            break;
        }
    }
    for(i=0;i<NP;i++){
        printf("%d",mice[i].rank);
        if(i<NP-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
}
