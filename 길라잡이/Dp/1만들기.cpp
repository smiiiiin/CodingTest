//백준 1463 1로 만들기
#include<iostream>
#include<algorithm> //min
using namespace std;

int main(){
    int n; cin>>n; int dp[n];
    dp[1]=0; dp[2]=1; dp[3]=1;
    for(int i=4;i<=n;i++){
    if(i%2==0 && i%3==0) dp[i]= min(dp[i-1], min(dp[i/2],dp[i/3]))+1;
    else if(i%2==0) dp[i]= min(dp[i/2], dp[i-1])+1;
    else if(i%3==0) dp[i]= min(dp[i/3], dp[i-1])+1;
    else dp[i]= dp[i-1]+1;
    }
    cout<<dp[n]<<"\n";
    return 0;
}

/*
 n=642
 642-> 214 -> 107-> 106-> 53> 52>26>13>12>4>2>1 11번 나오는데
 
 정답은
 642> 321> 320 이렇게 2로 나누고 -1 순서로 가면 10번만 한다
 
 - 그냥 모르니깐 모든 경우의 수에서 min을 구한다고 생각
 
 */
