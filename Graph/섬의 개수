//백준 4963 섬
//입력에 공백이 없으면,
//제발 scanf("%1d",&map[y][x]) cin쓰고 싶으면 string으로 하고 -'0'하기
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>//memset
#define MAX 51
using namespace std;
int w,h;
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};
queue<pair<int, int>> q;
//0이 -1로 둘러싸인 경우, -1출력
void bfs(int y, int x){
    //cout<<"bfs한다"<<"\n";
    q.push({y,x});
    visited[y][x]=1;
  while(!q.empty()){
      int cy= q.front().first; int cx= q.front().second;
      q.pop();
      
      for(int d=0;d<8;d++){
          int ny= cy+dy[d]; int nx=cx+dx[d];
          if (ny<1||nx<1||ny>h||nx>w) continue;
          if(map[ny][nx]==1 && visited[ny][nx]==0){
              q.push({ny,nx});
              visited[ny][nx]=1;
          } } } }

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    while(1){
       memset(visited,0,sizeof(visited));
       memset(map,0,sizeof(map));
       int ret=0;
       cin>>w>>h;
       if(w==0&&h==0) break;
       
       for(int y=1;y<=h;y++){
           for(int x=1;x<=w;x++){
             cin>>map[y][x]; //1을 누르는 순간 bfs가 호출되서 다음칸에 1이 눌리기도 전에
               //그럼 토마토는 누르는 순간 bfs를 한게 아니라 누르는 순간 queue에 넣고 bfs를
               //호출한거다. 여기서 그렇게 해도 된다.
               /*
                내오답: cin>>map[y][x]; if(map[y][x]==1) {bfs(y,x); ret++;}
                */
             }
       }
        
        for(int y=1;y<=h;y++){
            for(int x=1;x<=w;x++){
                if(map[y][x]==1&&visited[y][x]==0){
                    bfs(y,x);ret++;
                
               }
              }
            }
        cout<<ret<<"\n";
    }
   return 0;
}
