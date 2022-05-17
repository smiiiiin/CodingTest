//백준 9084 동전
#include<iostream>
#define MAX 10001
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,n,goal; cin>>t;
    while(t--){
        cin>>n; int coin[21]; int dp[MAX];
        //초기화
        fill(dp+1,dp+n+1,0); fill(coin+1,coin+n+1,0);
        for(int i=1;i<=n;i++) cin>>coin[i];
        cin>>goal; dp[0]=1;
        for(int i=1;i<=n;i++){ //동전개수만큼
            for(int j=coin[i];j<=goal;j++){
                dp[j]+= dp[j-coin[i]];}}
        cout<<dp[goal]<<"\n";
        return 0;}}
/*
 10 50 100원으로 500원
 100원   5개
        4개  50원 2개      50원 1개
        3개  50원 4개      50원 3개      50원 2개      50원 1개
        2개  50원 6개      50원 5개      50원 4개
        1개  50원 8개 ...  50원 2개      50원 1개       10원 45개
        0개  50원 10개 ... 50원 0개      10원 50개
 
 //초기화 나눠지면 dp[]를 1로 채우기
 goal 1 2 3 4 5 6 7 8 9 10 ... 20 30 40 50 ... 100 200 300 400 500
   10                   1       1 1  1   1       1   1   1   1   1
   50                                    1       1   1   1   1   1
  100                                            1    1   1   1   1
total                   1       1  1  1  2
 
 dp[100] (100원만들기) = 4가지
 + dp[50]=2 + dp[10]=1
 
 dp[90]= 2가지
 50원짜리 1개, 10원까리 9개
 dp[50]= 1개, dp[10]=1
 
 100원짜리 1개
         0개   50원짜리 2개
               50원짜리 1개 10원짜리 5개
               50원짜리 0개 10원짜리 10개
 
  
  goal 1 2 3 4 5 6 7 8 9 ... 100  200   300 400 500 600 700 800 900 ... 1000
  100원                        1    1    1   1    1   1   1   1   1       1
  500원                        0    0    0   0    1   0   0   0   0       1
 
 <<3가지
 
 1,2원으로 4원만들기 2원2개 1개 0개 3가지
 1,2원으로 3원 만들기 2원 1개 0개 2가지
 
 2원 1원만들기를 2번+ 2원짜리 하나
 
 3원 1원만들기를 3번+
 
 */
