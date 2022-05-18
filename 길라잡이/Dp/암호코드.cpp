// 백준 2011 암호코드 
// 완전 유의할 것: int dp[5001] = {1,1}; // dp의 0,1번째 값만  1
#include<iostream>
#include<string>
#define mod 1000000
using namespace std;

int main(){
    string s; cin>>s; int size = s.size();
    if(s[0]=='0'){ cout<<0; return 0;}
    
    int dp[5001] = {1,1}; // dp의 0,1번째 값만  1
    for(int i=2; i<=size; i++){
        //나의 전값이 0보다만 크다면 그대로 옮김
        if(s[i-1]>'0') dp[i]=dp[i-1]%mod; 
        //두자리씩 10-26일때 
        int n =(s[i-2]-'0')*10 + s[i-1]-'0'; 
        if(10<=n && 26>=n) dp[i] = (dp[i]+dp[i-2])%mod;}
    cout<<dp[size];}
 
