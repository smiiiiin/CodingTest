//백준 15652 N과 M (4)
#include <iostream>
using namespace std;

int n,m;
int arr[9]={0,};
bool visited[9]={0,};

void dfs(int node, int cnt) { //브루트포스 
    
	if (cnt-1 == m) {
		for(int i=1;i<=m;i++){
		    cout<<arr[i]<<" ";}
		    cout << '\n';
		return; //그 전으로 돌아갓 (손으로 그린 그래프에서) 
		}
	
	for(int i=node ; i<=n ; i++){
	   
	        visited[i]=1;
	        arr[cnt]=i;
	        dfs(i,cnt+1);
	       // visited[i]=0;
	        }
}
 

int main() {
    cin>>n>>m;
    dfs(1,1);
}
