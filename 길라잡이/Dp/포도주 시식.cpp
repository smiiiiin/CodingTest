// 백준 2156 포도주시식 
// max({,,}); 이러면 3개중 max를 고를 수 있음 
#include <iostream>
#include <algorithm>
using namespace std;
int n; long long arr[10001]; long long dp[10001];

int main(void){   
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    dp[1]=arr[1]; dp[2]= arr[1]+arr[2]; 
    // 끝에서 두개 택했으면 그 전에것은 체크되면 안되니까 dp[i-3] 이런 식 
    for(int i=3;i<=n;i++) dp[i]= max({dp[i-1], dp[i-2]+arr[i],dp[i-3]+arr[i]+arr[i-1]});
    
    cout<<dp[n]<<"\n";
    return 0;}
