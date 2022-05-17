//재귀함수, 백트래킹, DFS이용
#include <iostream>
using namespace std;

struct FISH { // 물고기들
    int y , x ;
    int dir; //방향
};

const int dy[8] = { -1, -1, 0, +1, +1, +1, 0, -1 }; //위부터 반시계방향
const int dx[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };

int ret;

void solve(int board[4][4], FISH fish[], int shark_y, int shark_x, int sum) {
    int selected_board[4][4];
    FISH selected_fish[16];
    for (int y = 0; y < 4; ++y) {//천천히 변하는 것: 행변호 즉, 열
        for (int x = 0; x < 4; ++x) { //빨리 변하는 것: 열번호 즉, 행
            selected_board[y][x] = board[y][x]; //selected로 만든거 그대로 복사하기
            //복사한 걸로 해보고 안되면 그전으로 백트래킹 하기 위함 by 재귀 -> 이해 못함
        }
    }
    for (int i = 0; i < 16; ++i) {
        selected_fish[i] = fish[i];
    }

    //eat
    int fish_number = selected_board[shark_y][shark_x];
    int shark_dir = selected_fish[fish_number].dir;
    selected_fish[fish_number].y = -1; //처음에 selected는 말도안되게 초기화
    selected_fish[fish_number].x = -1; //x,y는 물고기의 위치
    selected_fish[fish_number].dir = -1; //방향
    selected_board[shark_y][shark_x] = -1;//보드에는 물고기 사이즈가 있다.

    sum += (fish_number+1); 
    if (ret < sum) { //내 결과보다 크면 그게 결과다 (근데 이거 왜함?) 안하면 틀림.
        ret = sum;
    }

    //fish move
    for (int f = 0; f < 16; ++f) {
        if (selected_fish[f].x == -1) { //먹힌얘면 다음 물고기
            continue;
        }
        int cx = selected_fish[f].x;
        int cy = selected_fish[f].y;
        int cd = selected_fish[f].dir;
        
        int nx = cx + dx[cd];
        int ny = cy + dy[cd];
        int nd = cd;
        while (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (nx == shark_x && ny == shark_y)) {// 갈데가 없으면
            nd = (nd + 1) % 8; //왼쪽으로 45도씩 회전- mod8 8안에서만 노니까: 필수
            nx = cx + dx[nd];
            ny = cy + dy[nd];
        }

        if (selected_board[ny][nx] != -1) {
            int target = selected_board[ny][nx];
            //swap
            selected_fish[target].y = cy; //오고
            selected_fish[target].x = cx;
            selected_fish[f].y = ny;//보내고
            selected_fish[f].x = nx;
            selected_fish[f].dir = nd;

            selected_board[ny][nx] = f;//보내고
            selected_board[cy][cx] = target;//오고
        }
        else { // selected_board[ny][nx]==-1 이면 ????
            selected_fish[f].y = ny;// 보내기만 한다.
            selected_fish[f].x = nx;
            selected_fish[f].dir = nd;

            selected_board[ny][nx] = f;
            selected_board[cy][cx] = -1;
        }
    }

    //shark move
    for (int step = 1; step < 4; ++step) {
        int nx = shark_x + dx[shark_dir] * step;
        int ny = shark_y + dy[shark_dir] * step;
        if (nx < 0 || ny < 0 || nx >= 4|| ny >= 4) {
            break;// 중단
        }
        if (selected_board[ny][nx] != -1) {
            solve(selected_board, selected_fish, ny, nx, sum);//재귀함수
        }
    }
}

int main()
{
    FISH fish[16]; //FISH의 객체 16개 생성
    //vector<FISH> fish or queue<FISH> fish : 둘다 FISH덩어리의 배열느낌인데
    // 쉽게 쓸 수 있는 함수가 다름 (벡터는 fish.push_back(int elem)/ 큐는 fish.push(int elem)
    // int* arr= new int[sz];
    // class Node{Node* n; }; Node* n; n= new Node;
    int board[4][4];
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            int a, b;
            cin>>a; cin>>b;
            --a; --b;
            fish[a].y = y; //ex)물고기 사이즈4는 0부터 시작하는 배열에 4번째인 index3에 들어가도록
            //4번째 FISH덩어리에 정보 집어넣기
            fish[a].x = x;
            fish[a].dir = b;
            board[y][x] = a;
            //보드판도 완성하기
        }
    }
    ret = 0;
    solve(board, fish, 0, 0, 0);
    cout<<ret;
    return 0;
}
// 
