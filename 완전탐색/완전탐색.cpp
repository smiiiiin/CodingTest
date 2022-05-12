// 백준 1992 쿼드트리
// third
// main 1변경
// main 2변경
// main 3변경
#include <iostream>
#include <cstdio>
using namespace std;
int map[64][64];

void dfs(int n, int y, int x){
    int cur = map[y][x];
    bool pass=1;
    
    for (int i = y; i < y + n; i++){
        for (int j = x; j < x + n; j++)
            if (map[i][j] != cur){
                pass=0;
                cout << '(';
                dfs(n/2, y, x);
                dfs(n/2, y, x + n/2);
                dfs(n/2, y+ n/2, x);
                dfs(n/2, y+ n/2, x + n/2);
                cout << ')';
                return;}}
    if(pass) {cout<<cur; return;}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++) {scanf("%1d",& map[i][j]); }}
    dfs(n,0,0);
    return 0;}
