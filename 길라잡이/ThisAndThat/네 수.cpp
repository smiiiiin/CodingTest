//백준 10824
//string -> long long 숫자로 변형할때는 stoll (stroll아니라고;;;) 그리고 int 가 아니라 long long 으로 변환해야한다는 사실 잊지말것
#include <iostream>
#include <string>
using namespace std;



int main() {
    string a,b,c,d;
    long long ret;
    cin>>a>>b>>c>>d;
    
    a= a+b;
    c= c+d;
    
   ret= stoll(a)+stoll(c);
    cout<<ret<<"\n";
}
