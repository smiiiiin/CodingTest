//백준 21608
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct student {
    int id;
    int lover[4];
    int x, y;
};

int N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct info { //prioirity_queue로 알맹이(struct)를 구성하면, 안에서 자동으로 >내림차순을 쓰는데 <로 설정하면 오름차순으로 가능
    int x, y, blankCnt=0, friendCnt = 0;
    bool operator <(const info& i) const {
        if (friendCnt == i.friendCnt) {
            if (blankCnt == i.blankCnt) {
                if (x == i.x) return y > i.y;
                else return x > i.x;
            }
            else return blankCnt < i.blankCnt;
        }
        else return friendCnt < i.friendCnt;
    }
};


int satisfied[] = { 0,1,10,100,1000 };



int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int board[20][20] = {0,};
    cin >> N;

    vector<student> students(N * N);
    for (int i = 0; i < N * N; i++) {
        cin >> students[i].id;
        for (int j = 0; j < 4; j++) {
            cin >> students[i].lover[j];
        }
    }

    // 1. 자리 배치하기
    for (int s = 0; s < N * N; s++) { //모든 학생들에 대해서 한명씩
        priority_queue<info> pQ;

        for (int i = 0; i < N; i++) { //판을 다 돌아볼거다. 0,0자리부터
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 0) {
                    int blankCnt = 0, friendCnt = 0;
                    for (int d = 0; d < 4; d++) { //모든 칸마다 주변4방향으로 둘러본다.
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;// 다음방향
                        if (board[nx][ny] == 0) blankCnt++; //빈칸이면 빈칸추가
                        else {
                            for (int k = 0; k < 4; k++) { //누가 있으면
                                if (board[nx][ny] == students[s].lover[k]) { //근데 내 lover면
                                    friendCnt++; //친구추가
                                    break;
                                }
                            }
                        }
                    }
                    pQ.push({ i,j,blankCnt , friendCnt }); //상하좌우 중에서 하나 선택
                    //이로써 한상어 기준 모든칸에 대한 정보가 pq에 들어옴
                }
            }
        }

        //한 상어가 어디로 갈지 알려줌. PQ(+info)로인해 맨위에 것이 가장 최선의 선택
            int x = pQ.top().x;
            int y = pQ.top().y;

            board[x][y] = students[s].id;
            students[s].x = x;
            students[s].y = y;
        //이걸 모든 상어 대해서 반복한다.
    }

    // 2. 만족도 계산
    int res = 0;
    for (int s = 0; s < N * N; s++) {
        int x = students[s].x;
        int y = students[s].y;

        int friends = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) continue;
            for (int k = 0; k < 4; k++) {
                if (board[nx][ny] == students[s].lover[k]) {
                    friends++;
                    break;
                }
            }
        }
        res += satisfied[friends];
    }

    cout << res;

    return 0;
}
