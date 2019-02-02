#include<stdio.h>

#define MAXN 15
int ChartoInt(char ch){
    if(ch>='0'&&ch<='9'){
        return ch-'0';
    }else if(ch>='a'&&ch<='z'){
        return ch-'a'+10;
    }else{
        return -1;
    }
}

long long ChartoNum(char ch[],long long radix){
    int i=0;
    long long res=0;
    while(ch[i]!='\0'){
        res=radix*res+ChartoInt(ch[i]);
        i++;
    }
    return res;
}

int FindMin(char a[]){
    int i=0,min=0;
    while(a[i]!=0){
        if(ChartoInt(a[i])>min){
            min=ChartoInt(a[i]);
        }
        i++;
    }
    return min+1;
}

int Compare(long long num,char a[],long long radix){
    long long sum=0;
    int i=0;
    while(a[i]!='\0'){
        sum=sum*radix+ChartoInt(a[i]);
        if(sum>num){
            return 1;
        }
        i++;
    }
    if(sum>num){
        return 1;
    }else if(sum<num){
        return -1;
    }else{
        return 0;
    }
}

int main(){
    char a1[MAXN],a2[MAXN];
    int tag,temp;
    long long radix,num;
    int i=0;
    long long min,max,mid;
    scanf("%s %s ",a1,a2);
    scanf("%d%lld",&tag,&radix);
    if(tag==1){
        num=ChartoNum(a1,radix);
        min=(long long)FindMin(a2);
        max=(num>min?num+1:min+1);
        while(min<max){
            mid=(min+max)/2;
            temp=Compare(num,a2,mid);
            if(temp==1){
                max=mid;
            }else if(temp==-1){
                min=mid;
            }else{
                printf("%d\n",mid);
                return 0;
            }
        }
    }else{
        num=ChartoNum(a2,radix);
        min=(long long)FindMin(a1);
        max=(num>min?num+1:min+1);
        while(min<max){
            mid=(min+max)/2;
            temp=Compare(num,a1,mid);
            if(temp==1){
                max=mid;
            }else if(temp==-1){
                min=mid;
            }else{
                printf("%d\n",mid);
                return 0;
            }
        }
    }
    printf("Impossible\n");
    return 0;
}
