//백준 20056
#include <iostream>
#include <vector>
using namespace std;
// 재료
struct FIRE { int y, x, m, s, d; };
const int dy[8] = { -1, -1, 0, +1, +1, +1, 0, -1 };
const int dx[8] = { 0, +1, +1, +1, 0, -1, -1, -1 };
int N, M, K;
vector<FIRE> fire;
vector<int> map[50][50];

void move() {
    vector<int> new_map[50][50];
    for (int i = 0; i < fire.size(); ++i)
    { int dir = fire[i].d; int speed = (fire[i].s % N); //여러바퀴 돌면 %를 한다.
        int ny = (fire[i].y + (dy[dir] * speed) + N) % N;//근데 얘는 왜 +N;
        int nx = (fire[i].x + (dx[dir] * speed) + N) % N;
        //fire에 들어온 순서대로 vector에 넣었다. 그러면 들어올때마다 map에서도 똑같이 넣었다.
        
        /* 도대체 왜 new_map[50][50]을 따로 만들어야하는가?
           : 상어는 움직이는데 현재 맵에 상어들의 정보를 지우기 귀찮아서
        */
        
        //ny,nx가 같은 다른 i가 같은 new_map에 들어갈 수도 있다.
        new_map[ny][nx].push_back(i);
        
        //i는 고유한 각각의 fish이기 때문에 i가 같은 다른 y나 x는 존재하지 않는다.
        fire[i].y = ny; fire[i].x = nx; }
    
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            map[y][x] = new_map[y][x]; } } } //update: 지난날의 과거는 잊어

void sum() {
    vector<FIRE> new_fire; //fire동적배열 update(과거 지우기) 하려고
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            //칸에 한fire도 없으면 다음 map
            if (map[y][x].size() == 0) { continue; }
            //칸에 한 fire만 있으면 한칸의 방을 쪼개서 욱여넣는 느낌이면 인덱스를 뒤에 오도록
            //판을 여러층으로 쌓아올리는 느낌이면 인덱스를 앞으로 like 청소년상어의 selected
            //한 좁은 칸에 들어갈 new_fish를 만든거다.
            if (map[y][x].size() == 1) { int index = map[y][x][0]; new_fire.push_back(fire[index]); continue; }
            
            int sum_m = 0, sum_s = 0; bool odd = true, even = true;
            for (int i = 0; i < map[y][x].size(); ++i) {
                int index = map[y][x][i];
                sum_m += fire[index].m; sum_s += fire[index].s;
                if (fire[index].d % 2 == 0) { odd = false; }
                else { even = false; } }
            
            //질량이 0인 파이어볼은 소멸한다.
            if (sum_m / 5 == 0) { continue; }
            int cur_m = sum_m / 5; int cur_s = sum_s / map[y][x].size();
            for (int i = 0; i < 4; ++i) {
                if (even||odd)
                    //합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면
                    //방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
                    {new_fire.push_back({ y, x, cur_m, cur_s, i * 2 }); }
                else
                    {new_fire.push_back({ y, x, cur_m, cur_s, i * 2 + 1 }); }
                
            } } } fire = new_fire; }


int solve() {
    //while(--k)는 k가 5면 4번만 돌린다.
    while(K--) {move(); sum(); }
    int ret = 0;
    for (int i = 0; i < fire.size(); ++i){
        ret += fire[i].m;
        }
    return ret;}


int main() {
    cin>>N; cin>>M; cin>>K; //격자크기,  파이어볼 개수, 마법사의 명령 개수
    for (int i = 0; i < M; ++i) {
        int y, x, m, s, d; //파이어볼 마다 위치, 질량, 속도, 방향 입력
        cin>>y; cin>>x;  cin>>m;  cin>>s;  cin>>d;
        //사용자들은 1부터 시작하지만 개발자들은 0부터 시작하는 세계이므로 우리가 알아서 하고
        //나중에 +1해줄게. 근데 언제하냐?
        --y; --x;  fire.push_back({ y, x, m, s, d });
        map[y][x].push_back(i); } //판에도 넣어주기
    int ret = solve();
    cout<<ret;
    return 0; }
