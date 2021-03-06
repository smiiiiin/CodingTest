//백준 1697 숨바꼭질 
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define MAX 100001

int n, k;
bool visited[MAX];

int bfs(int n) {
	queue<pair <int, int>> q;
	q.push(make_pair(n, 0));
	visited[n] = 1;

	while (!q.empty()) {
		int posi = q.front().first;
		int time = q.front().second;
		q.pop();

		if (posi == k)	return time;

		if (posi + 1 < MAX && !visited[posi + 1]) {
			q.push(make_pair(posi + 1, time + 1)); //이렇게 초대될때 매개변수를 찍어놓으면 몇번째로 소개된 애인지
			//표시가 가능하다. 
			visited[posi + 1] = true;
		}
		if (posi - 1 >= 0 && !visited[posi - 1]) {
			q.push(make_pair(posi - 1, time + 1));
			visited[posi - 1] = true;
		}
		if (posi * 2 < MAX && !visited[posi * 2]) {
			q.push(make_pair(posi * 2, time + 1));
			visited[posi * 2] = true;
		}
	}
	return 0;
}

int main() {
	cin >> n >> k;
	
	cout << bfs(n) << endl;
	return 0;
}

// 백준 1697 숨바꼭질
#include <iostream>
#include <algorithm> //min
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;
int s,f;
bool visited[MAX]  = { 0 };
vector<int> v;
int t{0};
int sec{987654321};

void bfs(int node) {
    queue<pair<int,int>> q;
    q.push({node,0});
    visited[node]=1;
        
    while(!q.empty()){
        int cx= q.front().first; t= q.front().second; q.pop(); 
        if(cx==f) return;
        
        int dx[3]= {cx,1,-1}; //여기서 2배, +1, -1순서로 봤는데 이거 순서만 바꿔도 틀린다. 
        for(int d=0;d<3;d++){
            int nx= cx+dx[d]; 
            if(nx >= MAX || nx<0) continue;
            if(!visited[nx]) {q.push({nx,t+1}); visited[nx]=1;}
        }
        
    }
}

int main() {
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false); 
    
    cin>>s>>f;
	bfs(s);
	cout << t <<"\n";
	return 0;
}
