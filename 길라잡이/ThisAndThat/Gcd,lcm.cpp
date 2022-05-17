//백준 2609
/*
근데 따지고보니 이문제와 크게 관련없음. 
runtime error가 나오니까 식 변형 필수 그래서 a+b % c 랑 a%c + b%c 를 배운거임. 
int lcm(int a, int b){
    int g=gcd(a,b);
    int aa= a/g;
    int bb= b/g;
    int ret= g*aa*bb;
    return ret;
}*/
#include <iostream>
using namespace std;

int a,b;

int gcd(int a, int b){
    int c= a%b; //굳이 뭐가 작고큰지 할필요 없는게 알아서 자동으로 됨. 계산해봐. 
    
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
int lcm(int a, int b){
    return a * b/gcd(a,b);
}


int main()
{
    cin>>a>>b;
    cout<<gcd(a,b)<<"\n"<<lcm(a,b)<<"\n";
    return 0;
}



