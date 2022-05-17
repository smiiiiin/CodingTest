//백준 7453 합이 0인 네 정수
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n; int map[4001][4]; vector<int> A, B; long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int y = 0; y< n; y++)
        for (int x = 0; x < 4; x++) cin >> map[y][x];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            A.push_back(map[y][0] + map[x][1]);
            B.push_back(map[y][2] + map[x][3]);}}
    sort(A.begin(), A.end()); sort(B.begin(), B.end());
    
    for (int i = 0; i < A.size(); i++) {
        int front = lower_bound(B.begin(), B.end(), -A[i]) - B.begin();
        int back = upper_bound(B.begin(), B.end(), -A[i]) - B.begin();
        ans += (back - front);}
    cout << ans << endl;
    return 0;}
 
 
