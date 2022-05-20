// 백준 15650 N과 M (2)
// dfs(depth+1, node+1);  // dfs(depth+1, node+1);은 안된다 왜?왜?왜?????????

#include <iostream>
using namespace std;

int n,m;
int arr[8]={0,};
bool visited[8]={0,};

void dfs(int depth, int node) { //브루트포스
    
    if (depth-1 == m) {
        for(int i=1;i<=m;i++){
            cout<<arr[i]<<" ";}
            cout << '\n';
        return; //그 전으로 돌아갓 (손으로 그린 그래프에서)
        }
    
    for(int i=node;i<=n;i++){
        if(!visited[i]) {
            visited[i]=1;
            arr[depth]=i;
            dfs(depth+1, node+1);  // dfs(depth+1, node+1);은 안된다 왜?왜?왜?????????
            visited[i]=0; }}
}
 

int main() {
    cin>>n>>m;
    dfs(1,1);
}
