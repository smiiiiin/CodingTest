//백준 2186 문자판
#include<iostream>
#include<cstring>
#include<string>
#define MAX 100
using namespace std;
 
int N, M, K, res;
char MAP[MAX][MAX];
int dp[MAX][MAX][80];
 
string Dest; int Dest_Len;
int dy[] = { 0, 0, 1, -1 }; int dx[] = { 1, -1, 0, 0 };
 
int dfs(int y, int x, int idx){ //map[y][x]에서 Dest[idx]와의 일치 경우의 수
    if (dp[y][x][idx] != -1) return dp[y][x][idx];
    if (idx >= Dest_Len) return 1; //밑바닥은 그런 경우의 수는 1이다.
 
    dp[y][x][idx] = 0;
    for (int d = 0; d < 4; d++){
        for (int k = 1; k <= K; k++){
            int ny = y + dy[d] * k;
            int nx = x + dx[d] * k;
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (MAP[ny][nx] != Dest[idx]) continue;
            //만약에 맞으면 Dest에서 다음문자와 비교해야한다, 맞는 경우가
            //여러개 있을 수 있다.
            dp[y][x][idx] += dfs(ny, nx, idx + 1);}}
    
    return dp[y][x][idx];
}

 
int main(void){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++){
        for (int x = 0; x < M; x++){
            cin >> MAP[y][x];}}
    
    cin >> Dest;
    Dest_Len = Dest.length();
    memset(dp, -1, sizeof(dp));
    
    char Temp = Dest[0];
    for (int y = 0; y < N; y++){
        for (int x = 0; x < M; x++){
            if (MAP[y][x] == Temp){
                res = res + dfs(y, x, 1);}}}
    
    cout << res << "\n";
    return 0;}

