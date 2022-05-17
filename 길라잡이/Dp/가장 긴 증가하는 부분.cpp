//백준 11053 가장 긴 증가하는 부분수열
#include<iostream>
#include<algorithm> //max, fill
#define MAX 1001
using namespace std;

int main(){
    int n; cin>>n; int arr[MAX]; int dp[MAX];
    fill(dp+1, dp+n+1, 1);
    for(int i=1;i<=n;i++) cin>> arr[i];
    
    for(int cock=2;cock<=n;cock++){
        for(int j=1;j<cock;j++){
            if(arr[j]<arr[cock]) dp[cock]= max(dp[j]+1, dp[cock]);
            }
    }
    int res= *max_element(dp+1, dp+n+1); //제발:) 1부터 시작했으면
    cout<<res<<"\n";
    return 0;}

/*
    예제) 10 20 10 30 20 50
         -  -     -     -     >> 길이:4
         1  2  1  3
 
 */
