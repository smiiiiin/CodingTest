//백준 2146 다리만들기
//https://www.acmicpc.net/submit/2146/41266419 참고하기 
#include<iostream>
#include<cstring> //memset()
#include<vector>
#include<queue>
#include<algorithm>//min()
#define endl "\n"
#define MAX 100
using namespace std;
 
int n, ans; int map[MAX][MAX]; bool visited[MAX][MAX];
int dy[4] = { -1, 1, 0, 0 }; int dx[4] = { 0, 0, -1, 1 };
 
vector<pair<int, int>> v;
 
void Make_LandLabel(int y, int x, int l){
    queue<pair<int, int>> q;
    q.push({y, x}); visited[y][x] = 1; map[y][x] = l;
 
    while (!q.empty() ){
        int y = q.front().first; int x = q.front().second; q.pop();
 
        for (int d = 0; d < 4; d++){
            int ny = y + dy[d]; int nx = x + dx[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            
            if (visited[ny][nx] == 0 && map[ny][nx] == -1){
                visited[ny][nx] = 1;
                map[ny][nx] = l;
                q.push(make_pair(ny, nx));}}}}
 
int BFS(int num){
    int res = 0;
    queue<pair<int, int>> qq;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++){
            if (map[y][x] == num){
                visited[y][x] = 1;
                qq.push(make_pair(y, x));}}}
 
    while (!qq.empty()){
        int S = qq.size();
        for (int i = 0; i < S; i++){
            int y = qq.front().first; int x = qq.front().second; qq.pop();
 
            for (int d = 0; d < 4; d++){
                int ny = y + dy[d]; int nx = x + dx[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                
                if (map[ny][nx] != 0 && map[ny][nx] != num) return res;
                
                else if (map[ny][nx] == 0 && visited[ny][nx] == false){
                    visited[ny][nx] = true;
                    qq.push(make_pair(ny, nx));}}
        }
        res++; }
    return res;}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ans = 987654321; cin >> n;
    
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++){
            cin >> map[y][x];
            if (map[y][x] == 1){
                map[y][x] = -1;
                v.push_back(make_pair(y, x));}}}
    
    int Land_Label = 0;
    for (int i = 0; i < v.size(); i++){
        int y = v[i].first; int x = v[i].second;
        if (visited[y][x] == 0) Make_LandLabel(y, x, ++Land_Label);
    }
 
    for (int i = 1; i < Land_Label; i++){
        ans = min(ans, BFS(i));
        memset(visited,0,sizeof(visited));}
    
    cout << ans << endl;
    return 0;}
