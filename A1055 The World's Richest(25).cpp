#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct Person{
    char name[10];
    int age,worth;
};

bool cmp(Person a,Person b){
    if(a.worth!=b.worth){
        return a.worth>b.worth;
    }else if(a.age!=b.age){
        return a.age<b.age;
    }else{
        return strcmp(a.name,b.name)<0;
    }
}

vector<Person> P,temp;

int main(){
    int N,K;
    int i,j;
    int M,Amin,Amax;
    Person t;
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++){
        getchar();
        scanf("%s %d %d",&t.name,&t.age,&t.worth);
        P.push_back(t);
    }
    sort(P.begin(),P.end(),cmp);
    for(i=1;i<=K;i++){
        scanf("%d%d%d",&M,&Amin,&Amax);
        temp.clear();
        printf("Case #%d:\n",i);
        for(j=0;j<=P.size();j++){
            if(P[j].age>=Amin&&P[j].age<=Amax){
                temp.push_back(P[j]);
            }
            if(temp.size()>=M){
                break;
            }
        }
        if(temp.size()==0){
            printf("None\n");
        }else{
            for(j=0;j<temp.size();j++){
                printf("%s %d %d\n",temp[j].name,temp[j].age,temp[j].worth);
            }
        }
    }
    return 0;
}
