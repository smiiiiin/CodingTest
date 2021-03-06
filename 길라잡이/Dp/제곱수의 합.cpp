// 백준 1699
// N=12인 경우를 생각해보자:)
#include <iostream>
#include <cmath>
using namespace std;

int dp[100001]; const int INF = 987654321;

int main(){ 	
    int N; cin >> N;
	for (int i = 0; i <= N; ++i) dp[i] = i;
	
	for (int i = 2; i <= N; ++i){
		for (int j = 1; j * j <= i; ++j){
			dp[i] = min(dp[i],dp[i-(j*j)]+1);}}
	cout << dp[N];}
