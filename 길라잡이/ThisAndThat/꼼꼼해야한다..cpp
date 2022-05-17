//백준 1850
//꼼꼼해야한다. 문제 잘 읽고 최대공약수라고 그 숫자를 내라는 법도 없다.
//답은 3인데 출력은 111 7이면 1111111 이렇게 하라고 했고 범위로 long long 으로 해야하고  #define MOD 120 이렇게 임의문자 다음 찐이 와야한다. 
// 그래서 #define ll long long 이렇게 써야한다. 

#include <iostream>
using namespace std;
#define ll long long 
ll a,b;

ll gcd(ll a, ll b){
    ll c= a%b; //굳이 뭐가 작고큰지 할필요 없는게 알아서 자동으로 됨. 계산해봐. 
    
    while(c!=0){
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}


int main()
{
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(false);
    cin>>a>>b;
    ll ret=  gcd( a, b);
    for (int i = 0; i < ret; i++) {cout << 1;} //최대공
    cout << "\n";
    return 0;
}

