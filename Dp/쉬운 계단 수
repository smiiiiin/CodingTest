//백준 10844
//long long이 중요하다. 

#include <iostream>
using namespace std;
int n;
long long dp[15][103];

int main(void)
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n;
    dp[0][1]=0;
    for(int i=1;i<=9;i++) {dp[i][1]=1;}
    
    for(int x=2;x<=n;x++) {
        dp[0][x]= dp[1][x-1]% 1000000000;
        for(int y=1;y<=8;y++){
            dp[y][x]= (dp[y-1][x-1]+dp[y+1][x-1])% 1000000000;
        }
        dp[9][x]= dp[8][x-1]% 1000000000;
    }
    long long sum{0};
    for(int i=0;i<=9;i++){
        sum+= dp[i][n]; //MOD 금지
    }
    
    cout<<sum % 1000000000;
    return 0;
}


//하는중

//백준 10844 쉬운 계단 수 
#include <iostream>
using namespace std;
#define MAX 101
int n; int dp[MAX][MAX]; 

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); 
    cin>>n;
    dp[1][0]=0; for(int i=0;i<10;i++) dp[1][i]=1; for(int i=1;i<=n;i++) dp[i][0]=1;
    
    for(int y=2;y<=n;y++){
        for(int x=1;x<9;x++){
            dp[y][x]= dp[y-1][x-1]+dp[y-1][x+1]% 1000000000;}}
    for(int i=2;i<=n;i++) dp[i][9]= dp[i-1][8];
            
    int res{0};
    for(int i=0;i<10;i++) res+= dp[n][i];
    cout<<res% 1000000000<<"\n";
    return 0;
    }
