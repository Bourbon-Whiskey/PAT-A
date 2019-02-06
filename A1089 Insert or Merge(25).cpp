#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N,m;
vector<int> Origin,Sorted,Test;

void Init(){
    int i,a;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        Origin.push_back(a);
        Test.push_back(a);
    }
    for(i=0;i<N;i++){
        scanf("%d",&a);
        Sorted.push_back(a);
    }
}

int isSort(int low,int high){
    int i;
    for(i=low;i<high-1;i++){
        if(Sorted[i]>Sorted[i+1]){
            break;
        }
    }
    if(i<high-1){
        return 0;
    }else{
        return 1;
    }
}

int check(){
    int i;
    m=1;
    for(i=1;i<N;i++){
        if(Sorted[i]>=Sorted[i-1]){
            m++;
        }else{
            break;
        }
    }
    sort(Test.begin(),Test.begin()+m);
    for(i=0;i<N;i++){
        if(Test[i]!=Sorted[i]){
            break;
        }
    }
    if(i==N){
        return 1;
    }else{
        return 0;
    }
}//插入为1，归并为0

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

void Insertation(){
    printf("Insertion Sort\n");
    if(m<N){
        sort(Sorted.begin(),Sorted.begin()+m+1);
    }
}

void MergeSort(){
    int i,k;
    printf("Merge Sort\n");
    m*=2;
    k=N/m;
    for(i=0;i<k;i++){
        sort(Sorted.begin()+i*m,Sorted.begin()+(i+1)*m);
    }
    if(N%m){
        sort(Sorted.begin()+i*m,Sorted.end());
    }
} 
int main(){
    int i,flag,k;
    Init();
    if(check()){
        //插入
        Insertation();
    }else{
        while(1){
            flag=1;
            k=N/m;
            for(i=0;i<k;i++){
                if(isSort(i*m,(i+1)*m)==0){
                    flag=0;
                    break;
                }
            }
            if(isSort(i*m,N)==0){
                flag=0;
            }
            if(flag==0){
                m/=2;
            }else{
                break;
            }
        }
        //归并
        MergeSort();
    }
    Print();
    return 0;
} 
