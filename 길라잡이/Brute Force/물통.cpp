// 2251 물통 ; 널 꽉 채우거나(ㄱ) 날 다 비우거나(ㄴ)
// ㄱ: 비우는 물통과 채우는 물통의 합이 채우는 물통의 한계보다 클 경우, 비우는 물통은 완전히 비지 않습니다.
// ㄴ: 비우는 물통과 채우는 물통의 합이 채우는 물통의 한계보다 같거나 작을 경우 비우는 물통은 완전히 빕니다.
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std; 
#define MAX 202
int A, B, C; vector <int> water; bool visited[MAX][MAX];


void BFS() {
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},C});
    
    while (!q.empty()) {
        int ca= q.front().first.first;
        int cb= q.front().first.second;
        int cc= q.front().second;
        q.pop();
        
        if(visited[ca][cb]) continue; //ca+cb+cc의 값은 정해져있으므로 2가지만 보면된다.
        visited[ca][cb]=1;
        if(ca==0) {water.push_back(cc);
        }
        //a->b
        if(ca >B-cb) //B에 남아있는 용량이 a보다 작으면
            q.push({{(ca+cb)-B,B},cc});
        else //B에 남아있는 용량이 a가 가진 물보다 많으면 a를 다 비워
            q.push({{0,ca+cb},cc});
        
        //b->a
        if(cb>A-ca)
            q.push({{A,(ca+cb)-A},cc});
        else
            q.push({{ca+cb,0},cc});
        
        
        
        //b->c
        if(cb > C-cc)
            q.push({{ca,cb+cc-C},C});
        else
            q.push({{ca,0},cb+cc});
        
        //c->b
        if(cc > B-cb)
            q.push({{ca,B},cb+cc-B});
        else
            q.push({{ca,cb+cc},0});
        
        
        
        //c->a
        if(cc >A-ca) //B에 남아있는 용량이 a보다 작으면
            q.push({{A,cb},ca+cc-A});
        else //B에 남아있는 용량이 a가 가진 물보다 많으면 a를 다 비워
            q.push({{ca+cc,cb},0});
        
        //a->c
        if(ca>C-cc)
            q.push({{ca+cc-C,cb},C});
        else
            q.push({{0,cb},ca+cc});
      }
    
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin >> A >> B >> C;
    BFS();
    sort(water.begin(), water.end());
    
    for (int i = 0; i < water.size(); i++)
        cout << water[i] << " ";
    
    return 0;
}

