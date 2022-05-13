// 동빈나 강의 참고|| 원리를 이해하자:)
// 3가지 경우, 눕힌거 2가지로 늘어나거나 2x2짜리추가 (*2) or 세운거 하나로 늘어나거나

#include <iostream>
using namespace std;
#define MOD 10007
int n;
int dp[1000];

int main(void)
{
    cin>>n;
    dp[1]=1; dp[2]=3;  //*2되게하려고 임의로 지정
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+2*dp[i-2]%MOD;
    }
    cout<<dp[n]%MOD;
    return 0;
}
