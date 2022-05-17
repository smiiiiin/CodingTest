// 1525 퍼즐 - string으로 map의 위치를 두는 이유, break할 경우를 쓰기 곤란해짐.
//string으로 stoi이용하고 find로 인덱스 위치 찾아서 /3 or %3으로 cy,cx둘 수 있으니까 이 방법을 고려
// next: 2251
#include <iostream>
#include <string> //.find함수 string에서 char의 인덱스 위치 return
#include <algorithm> //swap함수
#include <queue>
#include <map> //키와 값형태로 저장 count()함수 이용가능
using namespace std;
const int TARGET = 123456789; //우리의 목표
int dy[4]= {-1,1,0,0}; int dx[4]= {0,0,-1,1};
int main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int start = 0; //시작할 때 순열
    for (int i = 0; i < 3; i++){//입력형식에 맞춰줘야한다.
        for (int j = 0; j < 3; j++){
            int num; cin >> num;
            if (num == 0) num = 9;
            start = start * 10 + num;}}
        queue<int> q; map<int, int> visited;
        q.push(start); visited[start] = 0;// 왜 1이 아니지?
    
        while (!q.empty()){
            int cur = q.front(); string s = to_string(cur); q.pop();
            if (cur == TARGET) break; //int map[][]로 할경우 이걸 못해서 이렇게 해야함.
            int zero = s.find('9'); //9의 위치가 비어있는 칸
            int cy = zero / 3; int cx = zero % 3;
            for (int i = 0; i < 4; i++){
                int ny = cy + dy[i]; int nx = cx + dx[i];
                if (0 > ny || ny >= 3 || 0 > nx || nx >= 3) continue;
                string temp = s;
                swap(temp[cy * 3 + cx], temp[ny * 3 + nx]);
                int next = stoi(temp);
                if (visited.count(next)) continue; //next라는 키의 값의 개수가 여러개면
                visited[next] = visited[cur] + 1; q.push(next);}}
            
            //TARGET이라는 키의 값의 개수가 없으면
            if (!visited.count(TARGET)) cout << -1 << "\n";
            else cout << visited[TARGET] << "\n";
            return 0;
}




// 암기해서 정답
// 1525 퍼즐 - string으로 map의 위치를 두는 이유, break할 경우를 쓰기 곤란해짐.
//string으로 stoi이용하고 find로 인덱스 위치 찾아서 /3 or %3으로 cy,cx둘 수 있으니까 이 방법을 고려
// next: 2251
#include <iostream>
#include <string> //.find함수 string에서 char의 인덱스 위치 return
#include <algorithm> //swap함수
#include <queue>
#include <map> //키와 값형태로 저장 count()함수 이용가능
using namespace std;
const int TARGET = 123456789; //우리의 목표
int dy[4]= {-1,1,0,0}; int dx[4]= {0,0,-1,1};
int main(void){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int start = 0; //시작할 때 순열
    for (int i = 0; i < 3; i++){//입력형식에 맞춰줘야한다.
        for (int j = 0; j < 3; j++){
            int num; cin >> num;
            if (num == 0) num = 9;
            start = start * 10 + num;}}
            queue<string> q; map<int,int> visit_cnt;
    q.push(to_string(start)); visit_cnt[start]=0;
    while(!q.empty()){
        string turn= q.front(); q.pop();
        if(turn=="123456789") break;
        int zero= turn.find('9');
        int cy= zero/3; int cx= zero%3;
        for(int d=0;d<4;d++){
            int ny= cy+dy[d]; int nx= cx+dx[d];
            if(ny>2||nx>2||ny<0||nx<0) continue;
            //9의 위치와 ny,nx의 string에서의 위치를
            string next=turn;
            swap(next[zero],next[(ny*3)+nx]);
            if(visit_cnt[stoi(next)]) continue;
            visit_cnt[stoi(next)]=visit_cnt[stoi(turn)]+1;
            q.push(next);
        }
    }
    
            //TARGET이라는 키의 값의 개수가 없으면
            if (!visit_cnt.count(TARGET)) cout << -1 << "\n";
            else cout << visit_cnt[TARGET] << "\n";
            return 0;
}
