//백준1987 알파벳
#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 20
using namespace std;

int R, C, Answer; char map[MAX][MAX]; bool visited[26];
int dy[4] = { 1,-1,0,0 }; int dx[4] = { 0,0,-1,1 };
 
void dfs(int y, int x, int Cnt){
    Answer = max(Answer, Cnt);
    for (int d = 0; d < 4; d++){
        int ny = y + dy[d]; int nx = x + dx[d];
        if (nx< 0 || ny < 0 || ny >= R || nx >= C) continue;
        if (visited[map[ny][nx] - 'A']) continue;
        visited[map[ny][nx] - 'A'] = true;
        dfs(ny, nx, Cnt + 1);
        visited[map[ny][nx] - 'A'] = false;}}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int y = 0; y < R; y++){
        for (int x = 0; x < C; x++){
            cin >> map[y][x];}}
    visited[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << Answer << "\n";
    return 0;}

//1부터 변경 version
//백준1987 알파벳
#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 21 //1부터 넣으면 한자리 늘려줘야한다. 
using namespace std;
//visited는 0부터 시작, map이랑 안맞으니까 그냥 0부터 시작하자. 

int R, C, Answer; char map[MAX][MAX]; bool visited[26];
int dy[4] = { 1,-1,0,0 }; int dx[4] = { 0,0,-1,1 };
 
void dfs(int y, int x, int Cnt){
    Answer = max(Answer, Cnt);
    for (int d = 0; d < 4; d++){
        int ny = y + dy[d]; int nx = x + dx[d];
        if (nx< 1 || ny < 1 || ny > R || nx > C) continue;
        if (visited[map[ny][nx] - 'A']) continue;
        visited[map[ny][nx] - 'A'] = true;
        dfs(ny, nx, Cnt + 1);
        visited[map[ny][nx] - 'A'] = false;}}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int y = 1; y <= R; y++){
        for (int x = 1; x <= C; x++){
            cin >> map[y][x];}}
    visited[map[1][1] - 'A'] = true;
    dfs(1, 1, 1);
    cout << Answer << "\n";
    return 0;}

