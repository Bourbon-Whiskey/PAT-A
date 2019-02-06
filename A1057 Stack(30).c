#include <stdio.h>
#define lowbit(i) ((i)&(-i))//i第一位1和其左边全部的0，能整除i的最大的i的幂次 
#define maxn 100010

int c[maxn];//树状数组 
//stack<int> s;
int s[maxn],top=-1;
 
void update(int x,int v){//更新操作，将第x个数加上一个数v 
    int i;
    for(i=x;i<maxn;i+=lowbit(i)){
        c[i]+=v;
    }
}
int getsum(int x){//返回前x个整数和 
    int sum=0,i;
    for(i=x;i>0;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}
void PeekMedian() {
    int left=1,right=maxn,mid,k=top/2+1;
    while(left<right) {
        mid=(left+right)/2;
        if(getsum(mid) >= k){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    printf("%d\n",left);
}
int main(){
    int n,temp;
    int i;
    char str[15];
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%s",str);
        if(str[1]=='u') {
            scanf("%d", &temp);
            s[++top]=temp;
            update(temp,1);//位置temp+1
        }else if(str[1]=='o') {
            if(top>-1) {
                update(s[top],-1);
                printf("%d\n", s[top--]);
            } else {
                printf("Invalid\n");
            }
        }else{
            if(top>-1){
                PeekMedian();
            }else{
                printf("Invalid\n");
            }
        }
    }
    return 0;
}
