//백준 2146 다리만들기
//https://www.acmicpc.net/submit/2146/41266419 참고하기 
#include<iostream>
#include<cstring> //memset()
#include<vector>
#include<queue>
#include<algorithm>//min()
#define endl "\n"
#define MAX 100
using namespace std;
 
int n, ans; int map[MAX][MAX]; bool visited[MAX][MAX];
int dy[4] = { -1, 1, 0, 0 }; int dx[4] = { 0, 0, -1, 1 };
 
vector<pair<int, int>> v;
 
void Make_LandLabel(int y, int x, int l){ //1이고 방문안했으면 , 단지번호 매기기
    queue<pair<int, int>> q;
    q.push({y, x}); map[y][x] = l; visited[y][x]=1;
 
    while (!q.empty() ){
        int y = q.front().first; int x = q.front().second; q.pop();
 
        for (int d = 0; d < 4; d++){
            int ny = y + dy[d]; int nx = x + dx[d];
            // 틀 안벗어나기는 기본아니냐~
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            
            if (visited[ny][nx] == 0 && map[ny][nx] == 1){
                map[ny][nx] = l; visited[ny][nx]=1;
                q.push({ny, nx});}}}}
 
int BFS(int num){ // 단지번호마다: (?방문안했고) 내 단지 아니고 0 아니면 return res;
    int res = 0;
    queue<pair<int, int>> q;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++){
            if (map[y][x] == num){
                visited[y][x] = 1;
                q.push(make_pair(y, x));}}}
 
    while (!q.empty()){
        /* !!중요)
         원래는 아래 2줄 코드 필요없이 진행되는 건데 res++더해주려고 딱딱 q의 단위를 끊어주는 거다
         map[y][x]=1인 얘들이 끝나면, 걔네가 소개해준 옆친구들 개수만큼만 딱 돌리기 그래서
         친구를 소개해준 횟수만큼 res++를 더하는 거다. 즉 이동 수가 된다
        */
        int S = q.size();
        for (int i = 0; i < S; i++){
            int y = q.front().first; int x = q.front().second; q.pop();
 
            for (int d = 0; d < 4; d++){
                int ny = y + dy[d]; int nx = x + dx[d];
                //틀 안벗어나기는 기본이다
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                
                if (map[ny][nx] != 0 && map[ny][nx] != num) return res;
                //위에 if문에서 visited[ny][nx] == 0 !! 이거 추가하면 왜 안되는 건가요?
                else if (map[ny][nx] == 0 && visited[ny][nx] == 0){
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));}}
        }
        //q가 비지 않는 동안 res++한다 // 이동의 횟수
        res++; }
    return res;}

int main(void){
    //ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ans = 987654321; cin >> n;
    //memset(visited,0,sizeof(visited)); memset(map,0,sizeof(map));
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++){
            scanf("%1d",&map[y][x]);
        }}
    
    int l{0};
    for (int y = 0; y < n; y++){
        for (int x = 0; x < n; x++){
            if(visited[y][x]==0 && map[y][x]==1) Make_LandLabel(y, x, ++l);
        }}
    
    for (int i = 1; i < l; i++){ //단지 수 별로
        ans = min(ans, BFS(i));
        memset(visited,0,sizeof(visited));}
    
    cout << ans << endl;

    
    return 0;}
