#include<cstdio>
#include<vector>
#define maxn 100010
#define INF 100000010
using namespace std;

struct Node{
    int left,right;
};
int chain[maxn];
int find_J(int L,int R,int goal){
    int Left=L,Right=R,mid;
    while(Left<Right){
        mid=(Left+Right)/2;
        if(chain[mid]>goal){
            Right=mid;
        }else{
            Left=mid+1;
        }
    }
    return Left;
}

int main(){
    int N,M,currentlow,sum,a;
    int i,j;
    vector<Node> C;
    Node temp;
    currentlow=INF;
    scanf("%d%d",&N,&M);
    sum=0;
    chain[0]=0;
    for(i=1;i<=N;i++){
        scanf("%d",&a);
        sum+=a;
        chain[i]=sum;
    }
    for(i=1;i<=N;i++){
        j=find_J(i,N,chain[i-1]+M);
        if(chain[j-1]-chain[i-1]>=M){
            sum=chain[j-1]-chain[i-1];
            if(sum<currentlow){
                currentlow=sum;
                C.clear();
                temp.left=i;
                temp.right=j-1;
                C.push_back(temp);
            }else if(sum==currentlow){
                temp.left=i;
                temp.right=j-1;
                C.push_back(temp);
            }
        }else if(j<=N&&chain[j]-chain[i-1]>=M){
            sum=chain[j]-chain[i-1];
            if(sum<currentlow){
                currentlow=sum;
                C.clear();
                temp.left=i;
                temp.right=j;
                C.push_back(temp);
            }else if(sum==currentlow){
                temp.left=i;
                temp.right=j;
                C.push_back(temp);
            }
        }
    }
    for(i=0;i<C.size();i++){
        temp=C[i];
        printf("%d-%d\n",temp.left,temp.right);
    }
    return 0;
}
