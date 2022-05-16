//백준 2579 계단오르기
#include<iostream>
#include<algorithm> //max, fill
#define MAX 301
using namespace std;

int main(){
    int n; cin>>n; int arr[MAX]; int dp[MAX];
    for(int i=1;i<=n;i++) cin>>arr[i];
    dp[1]= arr[1];
    dp[2]= arr[1]+arr[2];
    dp[3]= max(arr[1]+arr[3] , arr[2]+arr[3]);
    for(int i=4;i<=n;i++) dp[i]=
        max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
    cout<<dp[n]<<"\n";
    return 0;}
/*
 6  dp[1]= 6
 10 dp[2]= 6+10
 20 dp[3]= 10+20
 15 dp[4]= {1+3 or 1+2}    + arr[4]
 25 dp[5]= 1+2+4+5
 10
 20
 << 75
 
 0x0
 x00
 
 0x00
 00x0
 
 00x00
 
 6개
 00xx00//이 경우는 포함되지 않는다.
 
 0x0x00
 x00x00
 
 00x0x0
 0x00x0
 */
