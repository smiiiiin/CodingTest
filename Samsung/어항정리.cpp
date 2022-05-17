//백준 23291
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int N, K;
vector<vector<int>> board;
 
 
bool if_end() {
    // 물고기 수에 따라 종료조건이 성립한 경우 true 반환
    int max_fishes = *max_element(board[0].begin(), board[0].end());
    int min_fishes = *min_element(board[0].begin(), board[0].end());
    return ((max_fishes - min_fishes) <= K);
}
 
 
// 3. 물고기 수 조절
void move_fishes() {
    vector<vector<int>> new_board = board;
 
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (board[y][x] == -1) continue;
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == -1)
                    continue;
                // 각 좌표에 대하여 (인근 좌표와의 차/5) 만큼 빼서 new_board에 기록
                // -> 모든 인접칸에 대하여 동시에 발생한 것과 같게됨
                new_board[y][x] += (int) (board[ny][nx] - board[y][x]) / 5;
                //빼는건?
            }
        }
    }
 
    // 4. board를 일자로 펴줌 왼쪽아래부터 위로* 반복
    vector<int> flat_bowl;
    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < N; ++y) {
            if (new_board[y][x] == -1)
                continue;
            else
                flat_bowl.push_back(new_board[y][x]);
        }
    }
    //board를 초기화 한 후 board[0]를 flat_bowl로 교체
    board = vector<vector<int>>(N, vector<int>(N, -1));
    board[0] = flat_bowl; // board[0]를 flat_bowl로 교체
}
 
void move() {

    // 1. 어항의 물고기 수가 가장 적은 곳에 +1
    int min_fishes = *min_element(board[0].begin(), board[0].end());
    for (int i = 0; i < N; ++i) {
        if (board[0][i] == min_fishes)
            board[0][i]++;
    }
    
    int ly = 1, lx = 1; // length y, length x
    int sx = 0; // start y, start x
    // 2. 맨 왼쪽 것 오른 위로 쌓고 공중부양 90도로 돌려서 쌓기 (1층이 있어야한다)
    while (sx + ly + lx <= N) {
        for (int y = 0; y < ly; ++y) {
            for (int x = 0; x < lx; ++x) {
                int ny = lx - x;
                int nx = sx + lx + y;
                board[ny][nx] = board[y][x + sx];
                board[y][x + sx] = -1;
            }
        }
        sx += lx;
        if (ly == lx) ly++;
        else lx++;
 
 
    }
    // 3. 물고기 수 조절 (~4번)
    move_fishes();
 
    // 5. 가운데를 중심으로 180도 공중부양 쌓기 (2번 시행)
    sx = 0;
    ly = 1;
    lx = N / 2;
    
    for (int i = 0; i < 2; ++i) {
        for (int y = 0; y < ly; ++y) {
            for (int x = 0; x < lx; ++x) {
                int ny = 2 * ly - y - 1;
                //int nx = 2 * lx + sx - x - 1;
                int nx= N-x-1;
                board[ny][nx] = board[y][x + sx];
                board[y][x + sx] = -1;
            }
        }
        sx += lx;
        lx /= 2;
        ly *= 2;
    }
    // 6. 3,4번을 한번 더
    move_fishes();
 
}
 
int solve() {
    int count = 0;
    while (!if_end()) {
        count++;
        move();
    }
    return count;
}
 
int main() {
    cin >> N >> K;
    board = vector<vector<int>>(N, vector<int>(N, -1));
    //vector<int> int배열인데 vector라 STL쓸 수 있어. (배열 개수, 초기화 값(배열개수, 초기화값) )
    //즉 -1값으로 초기화된 N개의 한줄을 N개로 쌓은 N*N배열이 board라는 말씀.
    for (int i = 0; i < N; ++i) {
        cin >> board[0][i];
    }
    cout << solve();}


/* https://leeeegun.tistory.com/3 */
