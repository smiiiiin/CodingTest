//백준 15652 N과 M (4)
#include <iostream>
using namespace std;
int n,m; int arr[9]={0,};

void dfs(int depth, int node) { //브루트포스
    if (depth-1 == m) {
        for(int i=1;i<=m;i++){
            cout<<arr[i]<<" ";}
            cout << '\n'; return;}
    
    for(int i=node ; i<=n ; i++){
            arr[depth]=i;
            dfs(depth+1,i);}}

int main() { cin>>n>>m; dfs(1,1);}
