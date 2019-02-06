#include<stdio.h>

struct Rational{
    long long sign,numerator,denominator;
}num[2],ans;

long long gcd(long long a,long long b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

void Print1(struct Rational a){
    long long pub;
    if(a.numerator==0){
        printf("0");
    }else{
        if(a.numerator/a.denominator){
            printf("%d",a.numerator/a.denominator);
            a.numerator%=a.denominator;
            if(a.numerator==0){
                return;
            }else{
                printf(" ");
            }
        }
        pub=gcd(a.numerator,a.denominator);
        printf("%d/%d",a.numerator/pub,a.denominator/pub);
    }
}

void Print(struct Rational a){
    if(a.sign==-1){
        printf("(-");
        Print1(a);
        printf(")");
    }else{
        Print1(a);
    }
}
void Add(){
    long long a,b,pub;
    pub=gcd(num[0].denominator,num[1].denominator);
    a=num[0].denominator/pub;
    b=num[1].denominator/pub;
    ans.denominator=a*b*pub;
    ans.numerator=num[0].sign*num[0].numerator*b+num[1].sign*num[1].numerator*a;
    if(ans.numerator<0){
        ans.sign=-1;
        ans.numerator=-ans.numerator;
    }else{
        ans.sign=1;
    } 
    pub=gcd(ans.numerator,ans.denominator);
    ans.denominator/=pub;
    ans.numerator/=pub;
}

void Minus(){
    long long a,b,pub;
    pub=gcd(num[0].denominator,num[1].denominator);
    a=num[0].denominator/pub;
    b=num[1].denominator/pub;
    ans.denominator=a*b*pub;
    ans.numerator=num[0].sign*num[0].numerator*b-num[1].sign*num[1].numerator*a;
    if(ans.numerator<0){
        ans.sign=-1;
        ans.numerator=-ans.numerator;
    }else{
        ans.sign=1;
    }
    pub=gcd(ans.numerator,ans.denominator);
    ans.denominator/=pub;
    ans.numerator/=pub;
}

void Multi(){
    long long pub;
    ans.denominator=num[0].denominator*num[1].denominator;
    ans.numerator=num[0].numerator*num[1].numerator;
    if(ans.numerator==0){
        ans.sign=1;
    }else{
        ans.sign=num[0].sign*num[1].sign;
    }
    pub=gcd(ans.numerator,ans.denominator);
    ans.denominator/=pub;
    ans.numerator/=pub;
}

void Devide(){
    long long pub;
    ans.denominator=num[0].denominator*num[1].numerator;
    ans.numerator=num[0].numerator*num[1].denominator;
    if(ans.numerator==0){
        ans.sign=1;
    }else{
        ans.sign=num[0].sign*num[1].sign;
    }
    pub=gcd(ans.numerator,ans.denominator);
    ans.denominator/=pub;
    ans.numerator/=pub;
}

int main(){
    int i;
    long long a,b,pub;
    for(i=0;i<2;i++){
        scanf("%lld/%lld",&a,&b);
        if(a<0){
            num[i].sign=-1;
            a=-a;
        }else{
            num[i].sign=1;
        }
        pub=gcd(a,b);
        num[i].numerator=a/pub;
        num[i].denominator=b/pub;
    }
    Print(num[0]);
    printf(" + ");
    Print(num[1]);
    printf(" = ");
    Add();
    Print(ans);
    printf("\n");
    Print(num[0]);
    printf(" - ");
    Print(num[1]);
    printf(" = ");
    Minus();
    Print(ans);
    printf("\n");
    Print(num[0]);
    printf(" * ");
    Print(num[1]);
    printf(" = ");
    Multi();
    Print(ans);
    printf("\n");
    Print(num[0]);
    printf(" / ");
    Print(num[1]);
    printf(" = ");
    if(num[1].numerator==0){
        printf("Inf");
    }else{
        Devide();
        Print(ans);
        
    }
    printf("\n");
}

