//백준 11055 가장 큰 증가 부분 수열
#include<iostream>
#include<algorithm> //max, fill
#define MAX 1001
using namespace std;

int main(){
    int n; cin>>n; int arr[MAX]; int dp[MAX];
    for(int i=1;i<=n;i++) {cin>> arr[i]; dp[i]=arr[i];}
    
    for(int cock=2;cock<=n;cock++){
        for(int j=1;j<cock;j++){
            if(arr[j]<arr[cock]) dp[cock]= max(dp[cock], arr[cock]+ dp[j]);}}
        
    int res= *max_element(dp+1, dp+n+1); //제발:) 1부터 시작했으면
    cout<<res<<"\n";
    return 0;}

// 1 50 2 100 *2는 더하지 않는 이유
