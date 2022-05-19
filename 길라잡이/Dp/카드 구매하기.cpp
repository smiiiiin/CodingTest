// 백준 11052 카드 구매하기
#include<iostream>
#include<algorithm>
using namespace std;
int n;  int arr[1002]; int dp[1002];
 
int main(void){
    //초기화 안한 DP[0]=0;이니까. 
    cin>>n; for(int i=1;i<=n;i++) cin>>arr[i]; dp[1]=arr[1]; 
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){ //j=0을 해야 arr[]자기자신만 사는경우도 포함 
            dp[i]=max(dp[i], dp[j]+arr[i-j]);}}
    cout<<dp[n]<<"\n";
    return 0;}
