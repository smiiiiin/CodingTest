//9465: sticker
//index크기 존나게 유의하삼: 이거때문에 1시간 태움


#include <iostream>
#include <algorithm>
using namespace std;
int t; int n;
long long dp[2][100003];

int main(void)
{   scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
    for(int y=0;y<2;y++){
        for(int x=1;x<=n;x++){
            scanf("%d", &dp[y][x]);
        }}
    
    dp[0][2]+=dp[1][1]; dp[1][2]+=dp[0][1];
    
    for(int x=3;x<=n;x++){
        for(int y=0;y<2;y++){
            dp[y][x]+= max(dp[1-y][x-1], dp[1-y][x-2]);
        }
    }
        printf("%d\n", max(dp[0][n], dp[1][n]));
        
    }
    return 0;
}
