//백준 2225 합분해 
#include <iostream>
#include <vector>
#include <algorithm>
int n,k; int dp[201][201];
using namespace std;

int main(){
    cin>>n>>k;
    for(int i=0;i<=n;i++) dp[i][1]=1; 
    for(int i=0;i<=k;i++)  dp[0][i]=1;
    
    for(int y=1;y<=n;y++){
        for(int x=2;x<=k;x++){// for(int z=0;z<=n;z++)
            dp[y][x]=(dp[y-1][x]+dp[y][x-1])%1000000000;}}

    cout<<dp[n][k]<<"\n"; return 0;}
