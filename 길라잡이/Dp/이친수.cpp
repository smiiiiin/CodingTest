//백준 2193 이친수 
#include<iostream>
typedef long long ll;
using namespace std;
int n;
ll dp[2][105];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin>>n; dp[0][1]=0; dp[1][1]=1; 
    for(int i=2;i<=n;i++) {dp[1][i]= dp[0][i-1];
    dp[0][i]= dp[0][i-1]+dp[1][i-1];}
    ll ret{0}; ret= dp[0][n]+dp[1][n];
    cout<<ret<<"\n";
    return 0;}
