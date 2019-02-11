#include<cstdio>
#include<map>
#include<vector>
using namespace std;

vector<int> pre,inO;
map<int,int> in;

int main(){
    int i,a,N;
    int left,right,root;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        pre.push_back(a);
    }
    for(i=0;i<N;i++){
        scanf("%d",&a);
        in[a]=i;
        inO.push_back(a);
    }
    left=0,right=N-1,i=0;
    while(left!=right){
        a=pre[i++];
        root=in[a];
        if(root>left){
            right=root-1;
        }else{
            left=root+1;
        }
    }
    printf("%d\n",inO[left]);
    return 0;
}
