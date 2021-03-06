//백준 2178 미로탐색
//<너무중요!!!> 입력에 공백이 없으면,
//제발 scanf("%1d",&map[y][x]) or cin쓰고 싶으면 string으로 하고 -'0'하기
#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;
int m,n; int map[MAX][MAX]; int visited[MAX][MAX];
int dy[4]={-1,1,0,0}; int dx[4]={ 0,0,-1,1};
queue<pair<int, int>> q;

//0이 -1로 둘러싸인 경우, -1출력
void bfs(){
  q.push({1,1});
  visited[1][1]=1;
  while(!q.empty()){
      int y= q.front().first; int x= q.front().second; q.pop();
      
      for(int d=0;d<4;d++){
          int ny= y+dy[d]; int nx=x+dx[d];
          if (ny<1||nx<1||ny>n||nx>m) continue;
          if(map[ny][nx]==1 && visited[ny][nx]==0){
              q.push(make_pair(ny, nx));
              visited[ny][nx]=visited[y][x]+1;//변한 일수로 상태 표시
      } } } }
    
int main(){
       memset(visited,0,sizeof(visited));
       memset(map,0,sizeof(map));
       cin>>n>>m;
       for(int y=1;y<=n;y++){
           for(int x=1;x<=m;x++){
             scanf("%1d", &map[y][x]);
           }
       }
       bfs();
    printf("%d\n", visited[n][m]);
    return 0;}
