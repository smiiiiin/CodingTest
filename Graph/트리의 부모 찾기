//백준 11725 
// !!!   <<endl; 절대금지 시간초과나기 딱좋아~~
//ans와 visited를 한방에 해결한다. visited를 한방에 해결할 수 있으면 하자!

#include <iostream>
#include <vector>
using namespace std;

vector<int>v[100001];
int ans[100001];

void dfs(int node) {
    for (auto i: v[node]){
        if (ans[i] == 0) {
            ans[i] = node;
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
  
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
  
   
    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << ans[i] << "\n";
    }
   
   
    return 0;

}
   
