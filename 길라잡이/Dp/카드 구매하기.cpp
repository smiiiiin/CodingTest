// 백준알고리즘 11052번 :: 카드 구매하기
#include<iostream>
using namespace std;
#define max(a, b) (a > b) ? a : b
 
int N;
int arr[1002];
int dp[1002];
 
int main(void)
{
    cin >> N;
 
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    dp[1] = arr[1];
 
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + arr[i - j]);
        }
    }
 
    cout << dp[N];
    return 0;
}
