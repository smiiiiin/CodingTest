//백준 15651 N과 M (3)
#include <iostream>
using namespace std;
int n,m; int arr[8]={0,};

void dfs(int depth) { //브루트포스
    if (depth-1 == m) {
        for(int i=1;i<=m;i++){
            cout<<arr[i]<<" ";}
            cout << '\n';
        return;}
    
    for(int i=1;i<=n;i++){
            arr[depth]=i;
            dfs(depth+1);}}

int main() {
    cin>>n>>m; dfs(1);}
