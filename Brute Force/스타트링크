//백준 5014 스타트링크
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000001
using namespace std;
int f,s,g,u,d,res{0};
int fl[MAX];
int dy[2];

void bfs(int node){
    dy[0]=u; dy[1]= -1* d; 
    queue<int> q;
    fl[node]=0; q.push(node);
    while(!q.empty()){
        int cur= q.front(); q.pop();
   
        if(cur==g) {cout<<fl[cur]; break;}
   
        for(int d=0;d<2;d++){
            int next= cur+dy[d];
            if(next>f|| next<=0) continue;
            if(fl[next]!=-1) continue;
            q.push(next);
            fl[next]=fl[cur]+1;
        }}
}

int main(){
    memset(fl,-1,sizeof(fl));
    
    cin>>f>>s>>g>>u>>d;
    bfs(s);
    if (fl[g]==-1) cout<<"use the stairs";
    return 0;
}
