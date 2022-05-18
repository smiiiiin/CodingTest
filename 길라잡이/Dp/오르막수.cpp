//백준 11057 오르막 수 
//long long 하고 범위를 크게 써야지 안틀린다. //괄호도 주의해라 
#include <iostream>
#define MOD 10007
using namespace std;
int n; long long dp[1005][10]={0,}; long long ret{0};

int main(void){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); cin>>n;
    for(int i=0;i<10;i++) dp[1][i]=1;  for(int i=1;i<=n;i++) dp[i][0]=1; 
    
    for(int y=2;y<=n;y++){
        for(int x=1;x<10;x++){
            dp[y][x]= (dp[y-1][x]+dp[y][x-1]) %MOD;  }}
    for(int i=0;i<10;i++) ret= (ret+ dp[n][i]) %MOD;
    cout<<ret%MOD<<"\n";
    return 0;}

