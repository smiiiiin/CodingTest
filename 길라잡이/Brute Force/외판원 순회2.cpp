// 백준 10971 외판원순회 2 
// 백준 10971 외판원순회 2 

#include <iostream>
#include <algorithm>
using namespace std;

int arr[11] = { 0 };
bool visited[11] = { 0 };
int map[11][11] = { {0} };

int n;
int res = 987654321;

void dfs(int depth, int sum) {
int cost;    
    if(depth-1==n){
        cost= map[arr[n]][arr[1]];
        if(cost==0) return;
        res= min(res,sum+cost); return;
    }
    
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        arr[depth]=i;
        cost= map[arr[depth-1]][arr[depth]];
        if(cost==0) continue;
        
        visited[i]=1;
        dfs(depth+1, sum+cost );
        visited[i]=0;
        
        
    }

}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); cin >> n;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> map[y][x];
		}
	}
	
	for(int i=1;i<=n;i++){
	    visited[i]=1;
	    arr[1]=i;
	    dfs(2,0);
	    visited[1]=0;
	}


	cout << res<<"\n";
	return 0;
}


//내오답: depth마다 끊어줘야 조건을 넣을 수 있는데 나는 조합별로 다 넣어보고 나중에 계산 이래서 안된다.
//위에 정답은 한섬에서 다른섬으로 이동할때마다(depth를 더할 때마다) 0인지 아닌지 확인하고 0이면 continue를 통해 가는 것을 막아준다. 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int map[11][11];
vector<int> v;
int visit[11]; //마지막에 처음방문한 곳 무조건 가줘야함. 
int result{987654321};

void solve() { //브루트포스 
	if (v.size() == n) {  
		int tmp{0}; 
		for (int i = 0; i < n-1; i++) {
		    if(map[v[i]][v[i+1]]==0) return; 
		    //여기서 return이 아니라, 아예 다른데 return으로 작용해야하는데.. 이거때문에 매개변수 1개로 
			tmp += map[v[i]][v[i+1]];
		}
		int last= v[n-1]; int first= v[0];
	    tmp+= map[last][first];
		result = min(result, tmp);
		return;
	}
	
	for (int i = 1; i <= n; i++) { //백트래킹
		if (!visit[i]) {
			visit[i] = 1;
			v.push_back(i);
			solve();
			v.pop_back();
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for(int y=1;y<=n;y++){
	    for(int x=1;x<=n;x++){
	        cin>>map[y][x];
	    }
	}

	solve();
	cout << result << endl;
}


// 이 질문에 대한 답은 내가 조만간 하자. 
for (int i = 1; i <= n; i++) { 
		arr[1] = i;
		visited[i] = true;
		
		for (int i = 2; i <= n; i++) { 
		    if (visited[i]) continue;
    		arr[2] = i;
    		cost= map[arr[2]][arr[1]];
    		
    		visited[i] = true;
    		dfs(3, cost);
    		visited[i] = false;}
    		
	    visited[i] = false;
	} //이것도 depth 1,2를 초기화하는 방법일까? 
