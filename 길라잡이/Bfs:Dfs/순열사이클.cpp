// 백준 10451 순열 사이클
// 문제 자체가 순열의 의미는 5p2에서 (1,1)이 안됨. 같은걸 선택하지 않아. 그래서 두개의 노드가 하나를 가르키는 경우를 제하면
//11724의 connected문제와 동일하게 되고 dfs() 앞 혹은 뒤에 놓는 것이 타당함. 

//변수 위치 사용하기 직전에 놔라...
#include<iostream>
#include<vector>
using namespace std;
//LIST X DFS 로 해결하기: 4가지 다 가능하다.

bool visited[1001];
vector<int> li[1001];

void dfs(int node){
    visited[node]=1;
    for(auto i: li[node]){
        if(!visited[i]){
            dfs(i);
        }
    }
    
}

int main(){
    int t;
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin>>t;
    int n;
    while(t--){
    cin>>n;
        
    for (int i=1; i<=n; i++) {        // 사용한 공간 초기화
        li[i].clear(); 
         }
        //visited[i]=false; //이렇게 하는게 맞다. 
         //       }
        fill_n(visited,n,0);//방문안함으로 초기화 //fill_n은 처음에 선언한 크기에 딱맞게 해야한다. n이 아니라 1001로  
        int no;
    for(int i=1;i<=n;i++){
        cin>>no;
        li[i].push_back(no);
    }
    
        int ret{0};
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            ret++;//ret 이 여깄으면, 연결요소의 개수와의 차이점이 뭐야, 그냥 끝이 처음과 같지 않으면 어쩌려고..
        }
    }
    cout<<ret<<"\n";
}}
