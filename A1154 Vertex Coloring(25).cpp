#include<cstdio>
#include<set>
using namespace std;
#define maxn 10010

int test1[maxn],test2[maxn],seq[maxn];
set<int> st;
int N,M,K;


void Init(){
    int i;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++){
        scanf("%d%d",&test1[i],&test2[i]);
    }
    scanf("%d",&K);
}

void Check(){
    int i;
    st.clear();
    for(i=0;i<N;i++){
        scanf("%d",&seq[i]);
        st.insert(seq[i]);
    }
    for(i=0;i<M;i++){
        if(seq[test1[i]]==seq[test2[i]]){
            printf("No\n");
            return;
        }
    }
    printf("%d-coloring\n",st.size());
    return;
}

int main(){
    Init();
    while(K--){
        Check();
    }
    return 0;
}
