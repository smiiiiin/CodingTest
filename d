#include <iostream>
using namespace std;
#define MOD 1000000000
typedef long long ll;
int n;
ll dp[105][15];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
	ll res = 0;
    cin>>n;
    for(int y=0;y<10;y++){
            dp[y][0]=1; dp[0][0]=0;
        }
    for(int x=0;x<10;x++){
        dp[0][x+1]=dp[1][x];
        dp[9][x+1]= dp[8][x];
        
        for(int y=1;y<n;y++){
            dp[y][x]= dp[y-1][x-1]+dp[y+1][x-1]% MOD;
        }
        
    }

	for (int y = 0; y <= 9; y++) {
		res = (res + dp[y][n-1]) % MOD;
	}
	cout<< res % MOD;
	return 0;
}
/*
