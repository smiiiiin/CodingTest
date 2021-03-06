//백준 11724 연결 요소의 개수 
#include <iostream>
using namespace std;
// 4가지 방법이 있다. Matrix, List 2가지 버전과 X DFS, BFS 2가지 버전의 조합. 
// 1. Matrix X DFS 
// !!!DFS의 경우, 깊이이기 때문에 새롭게 들어가는 dfs할때마다 조건에 해당되는게 여러개면 못하고 들어가는 경우가 있는데 이건 return후에 
//    거슬러올라오면서 그 시점에서 하게된다. 
bool map[1001][1001];
bool visited[1001];
int n,m,a,b,ret{0};

void dfs(int n){
    visited[n];
    
    for(int j=1;j<=n;j++){
        if(map[n][j]&&!visited[j]){
            dfs(j);
        }
    } 
}

void solution(){
cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        map[a][b]=1; 
        map[b][a]=1;//무방향에서 필수 잊지말기:) 
        
    }
        
    for(int i=1;i<=n;i++){
        if(!visited[i]){//visited가 안되어있어야 그 부분부터 시작하는게 맞다.  
        ret++; 
        dfs(i);}
    } 
   
   cout<<ret<<"\n";
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
   solution();
    return 0;
}


// 2. List X DFS 
#include<iostream>
#include<vector>
using namespace std;

vector<int> li[10001]; //vector는 유동적이다 푹신푹신 밑으로 늘어난다. 
bool visited[10001];

int n,m,a,b,ret{0};

void dfs(int node){
    visited[node]=1; //이걸 안하면 어떻하냐? 
    for(auto v: li[node]) {
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    
    cin>>n>>m;
    for(int i=0;i<m;i++){//선 개수 만큼 입력해야한다. 
        cin>>a>>b;
        li[a].push_back(b);
        li[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]) {ret++; dfs(i);}
    }
    
    cout<<ret<<"\n";
    
}


//3. Matrix X BFS 
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,a,b,ret{0};
bool map[10001][10001];
bool visited[10001];

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int itsyour_turn= q.front();//지금 네가 맨 앞이야, 소개해줄 얘들있으면 소개해주고 나가. 
        q.pop();
        
        for(int i=1;i<=n;i++){
            if(map[itsyour_turn][i]&&!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        map[a][b]=1;
        map[b][a]=1;}
        
    fill_n(visited,n,0); //초기화 안해도 돌아가지만 하자. 
    for(int i=1;i<=n;i++){
        if(!visited[i]) {ret++; bfs(i);}
    }
    
    cout<<ret<<"\n";
      
}


// 4. List X BFS 
//4. list X BFS 
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,a,b,ret{0};
vector<int> li[10001];
bool visited[10001];

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    
    while(!q.empty()){
        int itsyour_turn= q.front();//지금 네가 맨 앞이야, 소개해줄 얘들있으면 소개해주고 나가. 
        q.pop();
        
        for(auto i:li[itsyour_turn] ){
        if(!visited[i]){
            visited[i]=1;
            q.push(i);
        }
    }
}}

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        li[a].push_back(b);
        li[b].push_back(a);
    }
        
    fill_n(visited,n,0); //초기화 안해도 돌아가지만 하자. 
    for(int i=1;i<=n;i++){
        if(!visited[i]) {ret++; bfs(i);}
    }
    
    cout<<ret<<"\n";
      
}
