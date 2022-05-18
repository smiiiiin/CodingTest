//9465: sticker
//index크기 존나게 유의하삼: 이거때문에 1시간 태움

#include <iostream>
#include <algorithm>
using namespace std;
int t; int n;
long long dp[2][100003];

int main(void)
{   cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>t;
    
    while(t--){
        cin>>n;
    for(int y=0;y<2;y++){
        for(int x=0;x<n;x++){
            cin>>dp[y][x];
        }}
    
    dp[0][1]+=dp[1][0]; dp[1][1]+=dp[0][0];
    
    for(int x=2;x<n;x++){
        for(int y=0;y<2;y++){
            dp[y][x]+= max(dp[1-y][x-1], dp[1-y][x-2]);
        }
    }
        cout<< max(dp[0][n-1], dp[1][n-1])<<"\n";
        
    }
    return 0;
}
