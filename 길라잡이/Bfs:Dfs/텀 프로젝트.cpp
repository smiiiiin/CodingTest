
//나 하는중
//백준 9466 텀 프로젝트
#include<iostream>
#include<cstring>
#include<queue>
#define MAX 100001
using namespace std;

int t,n,cnt; int arr[MAX]; int visited[MAX]; //처음시작노드

void bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur=q.front(); q.pop();
        int next=arr[cur];
        if(visited[next]!=-1 ) { visited[next]=cur;
            q.push(next);}
    }
    
    
}

int main(){
    cin>>t;
    while(t--){
        memset(arr,-1,sizeof(arr)); memset(visited,-1,sizeof(visited));
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            if(visited[i]!=-1) bfs(i);
        }
        }
    return 0;}













//내가 dfs쓰는 거 포기하고 이걸로 하려고 하는데도 이해가 안간다. 
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;

int t, n;
int graph[MAX]; 
bool visited[MAX];
bool done[MAX];
int cnt;
void hasCycle( int node) {

	visited[node] = true;
	int next = graph[node];

	
	if (!visited[next]) {
		hasCycle( next);
	}
	else if (!done[next]) {//방문은 했지만 아직 사이클이 아니라면 next까지 포함해서 사이클 완성
		//자기 자신을 포함한 팀의 멤버를 카운트
		for (int i = next; i != node; i = graph[i]) {//여기가 포인트인데 모르겠다. 
			cnt++;
		}
		cnt++;
	}
	done[node] = true;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> graph[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				hasCycle(i); 
			}
		}
		cout << n-cnt << '\n';
		cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
	}


	return 0;
}



//queue

#include <bits/stdc++.h>
using namespace std;

int n, t;
bool vis[100003];
int student[100003];
int startNumber[100003];
int countNumber[100003];

int main(){
    cout.sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int ans = n;
        fill(startNumber, startNumber + n + 1, -1);
        fill(countNumber, countNumber + n + 1, 0);
        fill(vis, vis + n + 1, false);
        for(int i = 1; i <= n; i++) {
            cin >> student[i];
        }
        for(int i = 1; i <= n; i++) {
            if(vis[i])continue;
            queue<int> Q;
            Q.push(i);
            startNumber[i] = i;
            vis[i] = true;
            countNumber[i] = 1;
            while(!Q.empty()) {
                int cur = Q.front(); Q.pop();
                vis[cur] = true;
                int nextStudent = student[cur];
                if(startNumber[nextStudent] == startNumber[cur]) {
                    if(nextStudent == cur) {
                        ans -= 1;
                    } else {
                        ans = ans - (countNumber[cur] - countNumber[nextStudent] + 1);
                    }
                    break;
                }
                if(vis[nextStudent]) continue;
                startNumber[nextStudent] = startNumber[cur];
                countNumber[nextStudent] = countNumber[cur] + 1;
                Q.push(nextStudent);
            }
        }
        cout << ans << '\n';
    }


    return 0;
}

//
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int T, n;
int choice[100002];
int team[100002]; // 0은 안 간 곳, 숫자는 첨 시작한 사이클 번호

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> choice[i];
		for (int i = 1; i <= n; i++) {
			if (team[i] == 0) {
				int cur = i;
				while (1) {
					team[cur] = i;
					cur = choice[cur];
					if (team[cur] == i) {
						while (team[cur] != -1) {
							team[cur] = -1;
							cur = choice[cur];
						}
						break;
					}
					else if (team[cur] != 0) break;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (team[i] != -1) ans++;
			team[i] = 0;
		}

		cout << ans << "\n";
	}
}
