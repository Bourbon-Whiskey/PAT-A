#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Origin,Sorted,Test;
int N;
int Turn;

void Init(){
    int i,a;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        Origin.push_back(a);
        Test.push_back(a);
    }
    sort(Test.begin(),Test.end());
    for(i=0;i<N;i++){
        scanf("%d",&a);
        Sorted.push_back(a);
    }
}

void downadjust(int low,int high){
    int i=low,j=2*i;
    while(j<=high){
        if(j+1<=high&&Sorted[j-1]<Sorted[j]){
            j++;
        }
        if(Sorted[i-1]<Sorted[j-1]){
            swap(Sorted[i-1],Sorted[j-1]);
            i=j;
            j=2*i;
        }else{
            break;
        }
    }
    
}

void HeapSort(){
    printf("Heap Sort\n");
    swap(Sorted[0],Sorted[N-Turn-1]);
    downadjust(1,N-Turn-1);
}

void InsertationSort(){
    printf("Insertion Sort\n");
    for(Turn=0;Turn<N-1;Turn++){
        if(Sorted[Turn]>Sorted[Turn+1]){
            break;
        }
    }
    sort(Sorted.begin(),Sorted.begin()+Turn+2);
}

void Check(){
    int i;
    for(i=N-1;i>0;i--){
        if(Sorted[i]!=Test[i]){
            break;
        }
        Turn++;
    }
    if(Sorted[0]==Test[i]){
        HeapSort();
    }else{
        InsertationSort();
    }
}

void Print(){
    int i;
    for(i=0;i<N;i++){
        printf("%d",Sorted[i]);
        if(i<N-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
}

int main(){
    Init();
    Check();
    Print();
    return 0;
}
