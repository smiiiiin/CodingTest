// 2667 단지번호 붙이기 BFS
// BFS , DFS 매트릭스로 기본맛
//입력에 공백이 없으면,
//제발 scanf("%1d",&map[y][x]) cin쓰고 싶으면 string으로 하고 -'0'하기
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
#define MAX 26
using namespace std;

int n; int map[MAX][MAX]; int visited[MAX][MAX]; int num[MAX*MAX];
int dy[4]={-1,1,0,0}; int dx[4]={0,0,-1,1};
queue<pair<int, int>> q;

void bfs(int y, int x, int r){
    q.push({y,x}); visited[y][x]= r;
  while(!q.empty()){
      int cy= q.front().first; int cx= q.front().second; q.pop();
      
      for(int d=0;d<4;d++){
          int ny= cy+dy[d]; int nx=cx+dx[d];
          if (ny<0||nx<0||ny>=n||nx>=n) continue;
          
          if(map[ny][nx]==1 && visited[ny][nx]==0){
              q.push({ny,nx});
              visited[ny][nx]=r;
          } } } }

int main(){
    memset(visited,0,sizeof(visited)); memset(map,0,sizeof(map));
    memset(num,0,sizeof(num)); int ret=0; cin>>n;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            scanf("%1d",&map[y][x]);}}
 
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(map[y][x]==1&&visited[y][x]==0){ //1이고 방문한 적 없으면 돌아간다 bfs
                    bfs(y,x,++ret);}}}
    printf("%d\n",ret);
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            num[visited[y][x]]++;}} 
    sort(num+1,num+ret+1);
    for(int i=1;i<=ret;i++){ printf("%d\n",num[i]); }
    return 0;
}
   
