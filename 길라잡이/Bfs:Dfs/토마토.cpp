//백준 7576 토마토
//입력에 공백이 없으면,
//제발 scanf("%1d",&map[y][x]) cin쓰고 싶으면 string으로 하고 -'0'하기
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>//memset
#define MAX 1001
using namespace std;
int m,n;
int map[MAX][MAX];
int visited[MAX][MAX];
int ret{-2}; // 애초에 0이 없는 경우 다음친구 소개할일이 없어서 ret을 이렇게 초기화했다. 
int dy[4]={-1,1,0,0}; int dx[4]={ 0,0,-1,1};
queue<pair<int, int>> q;
//0이 -1로 둘러싸인 경우, -1출력
void bfs(){
     
  while(!q.empty()){
      int y= q.front().first; int x= q.front().second;
      q.pop();
      
      for(int d=0;d<4;d++){
          int ny= y+dy[d]; int nx=x+dx[d];
          if (ny<1||nx<1||ny>n||nx>m) continue;
          if(map[ny][nx]==0&&visited[ny][nx]==0){//안익었으면 익히기
              q.push({ny,nx});
              map[ny][nx]=1;
              visited[ny][nx]=visited[y][x]+1;//변한 일수로 상태 표시
             ret= visited[ny][nx];
      } } } }
      
      

int main()
{
       cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
       memset(visited,0,sizeof(visited));
       //memset(map,-2,sizeof(map)); //-1없 0안익 1 익음
       //map은 cin으로 넣을건데 굳이 초기화?
        
       cin>>m>>n;
       
       for(int y=1;y<=n;y++){
           for(int x=1;x<=m;x++){
             cin>>map[y][x];
             if(map[y][x]==1){
                 q.push({y,x});
                 visited[y][x]=1; //모든 판에 대해 1이면 위치 큐에 다 넣음.
             }
           }
       }
       bfs();
      
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            // 익지 않은 토마토(0)가 존재할 경우
            if (map[y][x] == 0) {
                ret= 0; //밑에 ret에 맞춰서 -1이 나오게 하면 됨.
            }
        }
    }
    if(ret==-2) ret+=3 ; //저장될 때부터 모든 토마토가 익어있는 상태(0이 없다) 이면 0 출력. 그러러면 3을 더해야 -1해서 0이 나온다. 
    cout<<ret-1<<"\n";
    
    return 0;
}

