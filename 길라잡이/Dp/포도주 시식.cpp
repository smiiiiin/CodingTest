//백준 2156
//2xN 타일링 문제와 비슷한 원리: 반복되는 단위의 최소를 찾는다. 
#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long a[10001];
long long dp[10001];

int main(void)
{   cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1]= a[1];
    dp[2]= a[1]+a[2];
    for(int j=3;j<=n;j++){
        dp[j]= max({dp[j-1], a[j]+a[j-1]+dp[j-3], a[j]+dp[j-2]});
    }
    cout<<dp[n];
    return 0;
}


