//백준 9466 텀 프로젝트 : dfs 이용 이게더 이해하기 쉽다 나는
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;
// 입력 arr[]은 내가 원하는 얘가 있으니까 자식노드라고 생각
int t, n; int arr[MAX]; int visited[MAX]; int cnt;

void dfs( int node) {
    //방문 안했다면 해주고 다음노드
    if (visited[node]==-1) visited[node] = 1; int next = arr[node];
    
    if (visited[next]==-1) dfs( next);
    // visited[next]=1은 next인데 방문을 했다는 의미: back_edge거나 자기자신 가르키는 경우
    else if (visited[next]<2) {//방문은 했지만 사이클완성이 아니라면
        for (int i = next; i != node; i = arr[i]) { // cycle안에 노드 개수 세기
            cnt++;
        }
        cnt++;}  //그리고 나자신까지 +1;
    
    visited[node] = 2;} // 사이클완성


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t; while (t--) {
        // 초기화
        cnt = 0; memset(visited, -1, sizeof(visited));
        
        cin >> n; for (int i = 1; i <= n; i++) cin >> arr[i];
        
        for (int i = 1; i <= n; i++) dfs(i);
        
        cout << n-cnt << '\n';}
    return 0;}










//백준 9466 텀 프로젝트 : 다른정답: 움직이는 cur
#include <iostream>
#include <algorithm>
using namespace std;

int t, n; int arr[100002]; int visited[100002]; // 0은 안 간 곳, 숫자는 첨 시작한 사이클 번호

void moving_cur(){
    for (int starter = 1; starter <= n; starter++) {
        if (visited[starter] == 0) {// 들른적 없으면
            int cur = starter;
            
            
            while (1) {
                visited[cur] = starter; //방문한 걸 자기노드로 표시한다.
                cur = arr[cur]; //cur의 이동
                
                
                if (visited[cur] == starter) { //방문이 되어있으면 back_edge or자기자신
                    while (visited[cur] != -1) {
                        visited[cur] = -1; //사이클 안에 친구들을 다 -1로 만든다
                        cur = arr[cur]; //cur은 사이클을 돌며 이동한다
                    } break; //1번 브레이크
                }
                // visited[cur]이 0으로 아직 방문 안했다면 위로 가서 방문한다
                
                else if (visited[cur] != 0) break; // 2번 브레이크
            }
            //1,2번 브레이크 하면 starter부터 다시 간다
        }}}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t; while (t--) {
        cin >> n; int ans = 0;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        
        moving_cur();
        
        for (int i = 1; i <= n; i++) { //다돌려가며
            if (visited[i] != -1) ans++; //-1이 아니면 외톨이들 수 (=답)
            visited[i] = 0; //초기화
        }

        cout << ans << "\n";
    }
}
