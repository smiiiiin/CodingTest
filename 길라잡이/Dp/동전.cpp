//백준 동전
// https://www.youtube.com/watch?v=2IkdAk1Loek
// 03:01- 
 
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10001

int t, n, goal; int dp[MAX]; int coin[21];

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); cin>>t;
   
    while(t--){
        cin>>n; for(int i=0;i<n;i++) cin>>coin[i]; cin>>goal;
        fill(dp,dp+goal+1,0); dp[0]=1;
        for(int c= 0;c<n;c++){
            for(int i=coin[c]; i<=goal;i++){
                dp[i]+= dp[i-coin[c]];}}
        
        cout<<dp[goal]<<"\n";
        
    }}


 
 
 
 
 

 
