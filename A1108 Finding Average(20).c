#include<stdio.h>
#include<math.h>

double sum=0.0;
int cnt=0;
void check(){
    int i=0;
    int minus=1,dec=0,sum1=0,sum2=0;
    double ans=0.0;
    char temp[1000];
    scanf("%s",temp);
    if(temp[i]=='-'){
        minus=-1;
        i++;
    }
    while(temp[i]!=0){
        if(temp[i]>='0'&&temp[i]<='9'){//数字 
            if(dec==0){
                sum1=sum1*10+temp[i]-'0';
                if(sum1>1000){
                    break;
                } 
            }else{
                dec++;
                if(dec>3){
                    break;
                }
                sum2=sum2*10+temp[i]-'0';
            }
        }else if(temp[i]=='.'){//小数点 
            if(dec==0){
                dec++;
            }else{
                break;
            }
        }else{//其他 
            break;
        }
        i++;
    }
    if(temp[i]==0){
        ans=(sum1*1.0+((sum2*1.0)/pow(10.0,dec-1)));
        if(ans>1000){
            printf("ERROR: %s is not a legal number\n",temp);
            return;
        }
        ans*=(1.0*minus);
        sum+=ans;
        cnt++;
    }else{
        printf("ERROR: %s is not a legal number\n",temp);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        check();
    }
    if(cnt==0){
        printf("The average of 0 numbers is Undefined\n");
    }else if(cnt==1){
        printf("The average of 1 number is %.2lf\n",sum);
    }else{
        printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
    }
    return 0;
} 
