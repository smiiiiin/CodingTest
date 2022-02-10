#include <iostream>
#include <queue>
using namespace std;
 
struct SHARK {
    int x,y, time;
};
 
int n;
int map[20][20];
 
int shark_size, shark_eat; //얘는 struct에 넣는 방식으로 못할까?
SHARK shark;

 
const int dx[] = { 0, 0, -1, +1 };
const int dy[] = { -1, +1, 0, 0 };//상하좌우

    
 
int main()
{
    cin>>n;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            cin>> map[x][y];
            if (map[x][y] == 9) {
                shark.y = y; shark.x = x; shark.time = 0;
                shark_size = 2; shark_eat = 0;
                map[x][y] = 0;
            }
        }
    }//여기까지 맵을 채운다. 물고기들의 사이즈랑 아기상어의 위치를, 아기상어 정보 넣고 아기상어 사이즈 0으로 초기화 여기에는 먹을 물고기는 없는거나 다름없어지는 거다.

    bool is_update = true;
        while (is_update) { //update가 멈추면 그만두게 한다(먹을 게 없다)
        is_update = false;
     
            bool visited[20][20] = { false, }; //,뒤에 다 false로 초기화
            queue<SHARK> q; //후보들을 넣어 둘 큐를 만든다.
            visited[shark.x][shark.y] = true; //아기상어의 위치는 방문한거임.
            q.push(shark);// 아기상어를 큐에 넣는다.
     
            SHARK selected; //min같은 느낌: 내가 min인데 나보다 작으면 네가 min이다.
            selected.x = 20; selected.time = -1; //selected의 초기화다. 선택 안되도록.
            
            while (!q.empty()) {
                SHARK cur = q.front();  q.pop(); //pop은 커서를 오른쪽으로
                //움직이는 역할을 하는 듯하게 한다.
    

                for (int dir = 0; dir < 4; ++dir) {// 인접한 상하좌우를 둘러보며
                    //후보군들을 생성한다.
                    SHARK next;// 새로운 노드/셀/block? 을 만듦.
                    next.x = cur.x + dx[dir];
                    next.y = cur.y + dy[dir];
                    next.time = cur.time + 1;
     
                    if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) {
                        continue; //반복문의 끝으로 이동한다.
                        
                    }
                    //들른 적 없고 갈 수 있으면
                    if (visited[next.x][next.y] == false && shark_size >= map[next.x][next.y]) {
                        visited[next.x][next.y] = true; //간다
                        q.push(next); //후보군을 queue에 하나씩 넣고 -1
                    }
                    
                   }
                
                //초기화 상태가 아닌데 && (                          )하면 종료한다.
                if (selected.time != -1 && selected.time < cur.time) {
                    break;
                }
                
                // 먹을 수 있고 0이 아니면(먹이가 있으면)
                if (map[cur.x][cur.y] < shark_size && map[cur.x][cur.y] != 0) {
                 is_update = true; //먹는다- 이때 밑에 이프문과 연동된다.
                    if ( (selected.x == cur.x && selected.y > cur.y)|| selected.x > cur.x ) {
                        selected = cur; //높이가 같으면 왼쪽에 있거나 높이 있는것.
                        //== 높이 있는게 우선, 그 다음 왼쪽에 있는것.
                    } //상하좌우 해서 (4번이하의)cur이동(for문) 끝에 결정되는 selected.
                }
        }
                 
        if (is_update) { //bool을 통해서 동기화: 필요할 때 마다 호출이 가능하다. //먹는다= 이동한다= 선택한다
            shark= selected;//cout<<selected.time;은 못함. 지역변수라서?
            ++shark_eat;
            if (shark_eat == shark_size) {
                ++shark_size; //사이즈 키우고
                shark_eat = 0;//먹은 것 0으로 초기화하고 : 내생각엔 이부분 때문에 SHARK구조체에 size,eat 변경시 에러인것 같음.
            }
            map[shark.x][shark.y] = 0;}
          }

        cout<<shark.time;
     
        return 0;
    }


    
