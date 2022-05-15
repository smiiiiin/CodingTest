//백준 11722 가장 긴 감소하는 부분수열
#include<iostream>
#include<algorithm> //max, fill
#define MAX 100001
using namespace std;

int main(){
    int n; cin>>n; int arr[MAX]; int dp[MAX];
    fill(dp+1, dp+n+1, 1);
    for(int i=1;i<=n;i++) cin>> arr[i];
    
    for(int cock=n;cock>0;cock--){
        for(int j=n+1;j>cock;j--){
            if(arr[j]<arr[cock]) dp[cock]= max(dp[j]+1, dp[cock]);
            }
    }
    int res= *max_element(dp+1, dp+n+1); //제발:) 1부터 시작했으면
    cout<<res<<"\n";
    return 0;}
