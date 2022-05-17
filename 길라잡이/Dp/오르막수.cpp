//백준 11057
//long long 하고 범위를 크게 써야지 안틀린다. 
#include <iostream>
#define MOD 10007
using namespace std;
int n;
long long dp[10][1005];
long long ret;

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) dp[0][i]=1;
    for(int i=0;i<10;i++) dp[i][1]=1;
    
    
    for(int x=2;x<=n;x++) {
        for(int y=1;y<=9;y++){
            dp[y][x]= (dp[y-1][x]+dp[y][x-1])% MOD;
        }
    }
    ret=0;
    for(int i=0;i<=9;i++){
        ret+= dp[i][n]% MOD; //MOD 금지
    }
    
    cout<<ret % MOD;
    return 0;
}
