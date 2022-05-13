//백준 9095 1,2,3 더하기
#include <iostream>
using namespace std;

int dp(int n) {
    int ret{0};
    if (n == 0|| n== 1) ret+=1;
    if (n == 2) ret+=2;
    if (n >= 3) ret += dp(n - 3)+dp(n - 2)+dp(n-1);
    return ret;}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp(n) << endl;}
    return 0;}

/*
 1,2,3 더하기
 
 1= 1 1가지
 2= 11, 2 2가지
 3= 2에다가 1더하고 1에다가 2더하는 거 그리고 자기자신 = dp[2]+ dp[1]+1
 4= 3에다가 1더하고 2에다가 2더하고 1에다가 3더하고 = dp[3]+dp[2]+dp[1]
 5= 4에다가 1더하고 3에다가 2더하고 2에다가 1더하고 = dp[4]+dp[3]+dp[2]
 .
 .
 .
 
 
 <1,2,3,4 더하기>
 
 1= 1 1가지
 2= 11 2 2가지
 3= 2에다가 1더하고 1에다가 2더하는 거 그리고 자기자신 = dp[2]+ dp[1]+1
 4= dp[3]에 1더하고 dp[2]에 2더하고 dp[1]에 3더하고 자기자신 = dp[3]+dp[2]+dp[1]+1
 5= dp[4]+dp[3]+dp[2]+ dp[1]
 
 
 
 */
