//1번: 틀린 경우 
#include <bits/stdc++.h>

vector <int> v[101]; int map[101][101]; int visited[101][101]; bool visit[101][101];
int dy[4]={-1,1,0,0}; int dx[4]={0,0,-1,1}; int n,ret{0};

void dfs(int y, int x, int r){//CONNECTED에 덩어리번호 붙이기 
    visited[y][x]=r;
    
    for(int d=0;d<4;d++){
        int ny= y+dy[d]; int nx= x+dx[d];
        if(ny>=n||ny<0||nx>=n||nx<0) continue;
        if(map[ny][nx]==1&&visited[ny][nx]==0){
            dfs(ny,nx,r);
        }
    }
}


int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n;
    memset(visited,0, sizeof(visited));
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x]; 
            dfs(y,x,++ret); // !!!넣자마자 실행하면 상하좌우 돌릴 수가 없다. 뒤에 아직 cin하지도 않았는데!!
            
    }}
    return 0;
}
   


//1번: 맞는 경우 
#include <bits/stdc++.h>

vector <int> v[101]; int map[101][101]; int visited[101][101]; bool visit[101][101];
int dy[4]={-1,1,0,0}; int dx[4]={0,0,-1,1}; int n,ret{0};

void dfs(int y, int x, int r){//CONNECTED에 덩어리번호 붙이기 
    visited[y][x]=r;
    
    for(int d=0;d<4;d++){
        int ny= y+dy[d]; int nx= x+dx[d];
        if(ny>=n||ny<0||nx>=n||nx<0) continue;
        if(map[ny][nx]==1&&visited[ny][nx]==0){
            dfs(ny,nx,r);
        }
    }
}


int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n;
    memset(visited,0, sizeof(visited));
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x]; }}
    //이렇게 다 채우고 돌려야한다. 
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            dfs(y,x,++ret); }}
            
            
    return 0;
}


// 2번(번호 매기고 난 후의 경우): 맞는 경우        *bfs, dfs나 번호 매기기까지는 같은데 bfs로 할경우에 
// 덩어리 번호가 1번인 얘들만 먼저 넣고 싶으면

#include <bits/stdc++.h>

vector <int> v[101]; int map[101][101]; int visited[101][101]; bool visit[101][101];
int dy[4]={-1,1,0,0}; int dx[4]={0,0,-1,1}; int n,ret{0};



//!!! 단지를 매개변수로 받아서 1인단지만 먼저 큐에 넣고, 그 다음에 또 bfs호출되고 이게 가능하다. 
int bfs(int num){
    int distance{0};
    
    for(int y=0;y<n;y++){ 
        for(int x=0;x<n;x++){
            if(visited[y][x]==num){
                INFO info;
                info.y=y; info.x=x; info.num=num;
                q.push(info);
                visit[y][x]=1;}
                
            }
        }
    
    while(!q.empty()){
        int cy= q.front().y; int cx= q.front().x;
        cout<<cy<<cx<<"(cy,cx) "<<"\n";
        q.pop();
        for(int d=0;d<4;d++){
            int ny= cy+dy[d]; int nx= cx+dx[d];
            if(ny>=n||ny<0||nx>=n||nx<0)continue;
            
            //생략}}}


int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n;
    memset(visited,0, sizeof(visited));
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x]; }}
    
    
    //이렇게 단지별로bfs를 호출해야한다.
    for(int i=1;i<=ret;i++){
        bfs(i);
    }        
    
    
            
            
    return 0;
}
