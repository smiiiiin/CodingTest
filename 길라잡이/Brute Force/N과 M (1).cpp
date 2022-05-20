// 백준 15649 N과 M (1)

/* 번호 찍어내는건 cnt에서 하는거라 cnt를 깊이로 생각하면 됨, visited는 딱히 관계가 없다. 그냥 !visited이면 들어가서 해주는 거임
   dfs(1)에서 i=2,3,4인 경우를 못함, dfs(2)에서는 i=3,4인경우를 못하고 dfs(3)에서는 i=4인 경우를 못해서 return 후 이것들을 해준다.
   visited[i]=0;에서 i는 arr[cnt]=i에서 i이므로 현재 dfs()안에 들어간 숫자의 -1이라고 보면 된다. */

#include <iostream>
using namespace std;

int n,m; int arr[9]; bool visited[9];

void dfs(int depth) {
    
    if (depth-1 == m) {
        for(int i=1;i<=m;i++) cout<<arr[i]<<" ";
        cout<<"\n"; return;}
        
    for(int i=1;i<=n;i++){ //i는 node에 대해서 , dfs()와 dfs() 사이의 것들을 못함. i=1일때 i=2,3,4,5
        if (!visited[i]) {
            visited[i] = 1; arr[depth]=i;
            dfs(depth+1);
            visited[i]=0;
            //cout<<"out: "<<i<<" "; //test해볼 수 있는 코드
        }}}

int main() {cin >> n>>m; dfs(1); }
