// 백준 1707 이분그래프 
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
//list X BFS
using namespace std;
int t,n,m,a,b; 
vector<int> li[20010];
int color[20010]; //-1노방문, 0 흰, 1 검 

void bfs(int node){
    queue<int> q;
    q.push(node);
    color[node]=0; //방문하면 흰색이다. 
    while(!q.empty()){
        int your_turn=q.front();
        q.pop();
        
        for(auto i: li[your_turn]){
            if(color[i]==-1){//방문 하지 않았었다면 
                q.push(i);
                color[i]= 1-color[your_turn]; //불러준 친구와 다른색이다. 
            }
        }
    }
}


bool is_right(){
    for(int i=1;i<=n;i++){
        for(auto j: li[i]){//자식과 색상이 다르면 TRUE 
            if(color[i]==color[j]) return false;
        }
    }
    return true;
}

int main(){
    
 cin>>t;
 while(t--){
     cin>>n>>m;
     for(int k=1;k<= n;k++) li[k].clear();//다른케이스에서사용할때정리해줘야지!!! t-- 가 있잖아
     
     for(int i=0;i<m;i++){
         cin>>a>>b;
         li[a].push_back(b);
         li[b].push_back(a);
     }
    //memset(color, 0xff, sizeof(color));//-1로 초기화 하는 것과 같은 효과
     
    //fill_n(color,n,-1); //얘는 쓰면 틀림. 느려. 
     
     for(int i=1;i<=n;i++){
         if(color[i]==-1){bfs(i);}
     }
     if(is_right()) {cout<<"YES"<<"\n";}
     else {cout<<"NO"<<"\n";}
 }
      return 0;
}
