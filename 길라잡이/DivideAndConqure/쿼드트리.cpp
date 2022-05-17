// 백준 1992 쿼드트리 
#include <iostream>
#include <string>
using namespace std;
string video[64];

void dfs(int size, int y, int x){
    char cur = video[y][x];
    for (int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++)
            if (video[i][j] != cur){
                cout << '(';
                dfs(size / 2, y, x);
                dfs(size / 2, y, x + size / 2);
                dfs(size / 2, y + size / 2, x);
                dfs(size / 2, y + size / 2, x + size / 2);
                cout << ')';
                return;}
    cout << cur;}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> video[i];
    dfs(n,0,0);
    return 0;}3
