// 백준 1261 알고스팟 //queue에서 cur의 소개해준 순서 변수로 더해서 최소min써서 하는법
// 다익스트라 알고리즘: 가중치가 있을때 출발지-도착지까지 가중치 최소인 것의 값을 저장
// https://kpumangyou.tistory.com/21

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#define MAX 101
#define INF 987654321 //or 0x3f3f3f
using namespace std;
int n, m; int map[MAX][MAX]; int wall[MAX][MAX];
int dy[4]= { -1,1,0,0 }; int dx[4]={0,0,-1,1};

void bfs() {
    queue<pair<int,int>> q;
    wall[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        int cy= q.front().first;  int cx= q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int ny= cy+dy[d]; int nx= cx+dx[d];
            if(ny<0||nx<0||ny>=m||nx>=n) continue;
            if(map[ny][nx]==0){
                if(wall[ny][nx]>wall[cy][cx]){ //안가봤으면 INF니까 그 의미로만 거른다면, 언제 최소로 대체?
                    wall[ny][nx]=wall[cy][cx];
                    q.push({ny,nx});
                }
            }
            else if(map[ny][nx]==1){
                if(wall[ny][nx]>wall[cy][cx]+1){ //+1이 무슨 의미지?
                    //예제입력 3에서 1,2에서 0의 상하좌우의 하에 있는 1의 경우
                    // (2,1)에서 00부터 살피던 중, 이미 위에서의 하에서 처리됐는데
                    // map에서 1이니까 내가 1을 더한다고 가정해도 네가 크면
                    // 내가 1을 더한 상태(즉, 내가 최소) 작은 내가 네가 된다.
                    // 약간 min구할때 초기화를 max로 하고
                    //max 구할때 초기화를 min으로 하는 원리와 동일하다. 
                    wall[ny][nx]=wall[cy][cx]+1;
                    q.push({ny,nx});
                }
                
            }
            
    }
    }}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    string str;
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            wall[y][x] = INF;
            scanf("%1d",&map[y][x]);}}
    bfs();
    printf("%d\n" , wall[m-1][n-1]);
    return 0;}
