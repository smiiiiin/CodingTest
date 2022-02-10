//  백준 19237: 어른상어
#include <iostream>
using namespace std;
#include <stdio.h> //시간단축 됨.

const int dy[4] = { -1, +1, 0, 0 };
const int dx[4] = { 0, 0, -1, +1 };
struct SHARK { int y, x, d; int priority[4][4]; }; //2차배열 만들 수 있음.
int N, M, K, ret;
int board[3][20][20]; //0판: 상어숫자 / 1판: 냄새의 상어숫자/ 2판: 몇초 잔여시간
                      //각자의 복사본도 있음.
SHARK shark[400]; //20*20 최대 400개의 상어 객체 만들기 struct SHARK형태의 배열 400개
void solve() {
    int time = 0; int kill_shark = 0;
    while (time <= 1000) { ++time; int new_board[3][20][20] = { 0, };
        for (int y = 0; y < N; ++y){
            for (int x = 0; x < N; ++x) {
                //board를 3개로 나눈이유: 손으로 문제풀때도 한칸에 3개의 숫자를 적었잖아!
                new_board[0][y][x] = board[0][y][x]; //0판에 상어크기(현위치) 복사
                new_board[2][y][x] = board[2][y][x]; //2판에 냄새시간 복사
                if (new_board[2][y][x] > 0) // 2판에 냄새잔여시간 남아있으면
                { --new_board[2][y][x]; //잔여시간 줄이고
                    new_board[1][y][x] = board[1][y][x];// 1판에 냄새 있다고 상어번호 남아있는 거임.
                    
                } } }

for (int i = 0; i < M; ++i) { //상어 번호 다 둘러보면서
    int cy = shark[i].y; int cx = shark[i].x; int cd = shark[i].d;
    if (cy == -1) { continue; } //상어 죽었으면 다음 상어번호
    
    bool is_move = false;
    
    // 질문1 : 다음상어와 자멸의 차이는?
    
    for(int d = 0; d < 4; ++d){ // 방향의 우선순위대로 따라가는데 업데이트 해야함. 하나를 골라야하니까
        //작은 DFS: 다 해보기
        int nd = shark[i].priority[cd][d];
        int ny = cy + dy[nd]; int nx = cx + dx[nd];
        //1번: 다음에 갈 곳이 없거나 영역표시 되어있으면 다음 상어; (!!!그게 내 영역일 수도 있는데)
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[2][ny][nx] != 0) { continue; }
        is_move = true; new_board[0][cy][cx] = 0;
        //2번: 다음에 갈곳에 상어가 없으면 움직이기 (내영역으로 돌아가는거 여기 포함 0판에는 그거 없음)
        if (new_board[0][ny][nx] == 0) {
            new_board[0][ny][nx] = i + 1; new_board[1][ny][nx] = i + 1; new_board[2][ny][nx] = K;
            shark[i].y = ny; shark[i].x = nx; shark[i].d = nd; }
        //3번: 노답이면 자멸.
        else { ++kill_shark; shark[i].y = -1; } break;
    
    }
    //질문2 : 위에서 계속 continue된게 무슨 의미지? 왜 1-2만 차이를 두고 같은코드를 2번이나 쓰지?
    //줄일 수 있는 방법은 없나? 
    if (is_move == false) {//for문에서 계속 continue되면 false유지될 수 있음.
        for (int d = 0; d < 4; ++d)
            { int nd = shark[i].priority[cd][d];
              int ny = cy + dy[nd]; int nx = cx + dx[nd];
                //1-1번: 다음 갈 곳이 없을 때, 다음 상어
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) { continue; }
                //1-2번:냄새 남아있는데 그게 내것이 아닐때, 다음 상어
                if (board[2][ny][nx] != 0 && board[1][ny][nx] != i + 1) { continue; }
                new_board[0][cy][cx] = 0;
                //2번: 없으면 움직이기
                if (new_board[0][ny][nx] == 0) {
                    new_board[0][ny][nx] = i + 1; new_board[1][ny][nx] = i + 1; new_board[2][ny][nx] = K;
                    shark[i].y = ny; shark[i].x = nx; shark[i].d = nd; }
                //3번: 자멸
                else { ++kill_shark; shark[i].y = -1; } break; } } }

//죽은 상어가 1빼고 다 죽으면 중단
if (kill_shark == M - 1) { break; }
for (int y = 0; y < N; ++y){
    for (int x = 0; x < N; ++x) { //옳게 된 얘 다시 집어넣기  dfs()뒤에 오는 느낌.
        board[0][y][x] = new_board[0][y][x];
        board[1][y][x] = new_board[1][y][x];
        board[2][y][x] = new_board[2][y][x]; } } }
    
    if (time <= 1000) { ret = time; } }

int main() {
cin>>N; cin>>M; cin>> K; //배열크기, 상어갯수, 냄새시간
for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
        cin>> board[0][y][x];
        if (board[0][y][x] != 0) {
            int shark_number = board[0][y][x] - 1;
            shark[shark_number].y = y; shark[shark_number].x = x;
            board[1][y][x] = board[0][y][x]; board[2][y][x] = K; } } }
    
for (int i = 0; i < M; ++i) {cin>>shark[i].d; --shark[i].d;}
    
for (int i = 0; i < M; ++i) {
    for (int d = 0; d < 4; ++d) {
        cin>> shark[i].priority[d][0];
        cin>> shark[i].priority[d][1];
        cin>> shark[i].priority[d][2];
        cin>> shark[i].priority[d][3];
        --shark[i].priority[d][0]; --shark[i].priority[d][1];
        --shark[i].priority[d][2]; --shark[i].priority[d][3]; } }
ret = -1;
solve();
cout<<ret;
return 0;

}
