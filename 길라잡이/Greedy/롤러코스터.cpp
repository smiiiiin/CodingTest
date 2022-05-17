/* https://suhwanc.tistory.com/23 */
//백준 2873 rollercoaster
#include <iostream>
#include <string>
#include <vector>

#define INF 0x3f3f3f3f //infinite로 두는이유: memset편하고 overflow2배해도 안발생
using namespace std;

int y, x; //좌표 개념으로 입력 내가 y,x순으로 항상 했으니까
int arr[1001][1001];
string ans;

int min_val = INF;
int min_y;
int min_x;

string Rep(char c, int n) {
    string ret = "";
    while (n--) ret += c; //뒤에다가 그냥 스트링 붙이는 거다. L뒤에 D뒤에 U...
    return ret;
}

void Solve(void) {
    if (y % 2) { //case2: 행이 홀수면, 오르은쪽 아래 외에에엔쪽 아래 지렁이
        for (int i = 0; i < y; i++) {
            if (i % 2 == 0) ans += Rep('R', x - 1); //행이 홀수 일때, 열 개수만큼 R
            else ans += Rep('L', x - 1);            //행이 짝수 일때, 열 개수만큼 L
            
            if (i != y - 1) ans += 'D'; //Rep함수로 x-1만큼 반복 후, 맨밑만 아니면 down
        }
    }
    else if (x % 2) { //case1: 열이 홀수면, 아래애애애에 오른쪽 위에에에에 오른쪽 지렁이
        for (int j = 0; j < x; j++) {
            if (j % 2 == 0) ans += Rep('D', y - 1); //열이 홀수 일때, 여행 개수만큼 D
            else ans += Rep('U', y - 1); //열이 짝수 일때, 여행 개수만큼 U
            
            if (j != x - 1) ans += 'R'; //Rep함수로 y-1만큼 반복 후, 맨밑만 아니면 down
            
        }
    }
    else {// ! case3: 최소값에서 흰색 하나만 빼는 경우 (거의 40분 끄적임으로 알아낸 사실)
        bool vacancy = false;
        for (int i = 0; i < y; i += 2) { // 열 단위를 2개씩 0,2,4 ... 를 기준으로
            
            if (i==min_y || i== min_y-1) { // 0,2,4 마다 왔는데 vacancy가
                //같은y에 있거나 아래 있는 경우, 아래로 내리고 vancancy에 true버튼을 변경한다.
                //vacancy는 한번 키면 껐다 켰다 안한다.
                vacancy = true;
                bool up = false; //일단 아래로 내리고 시작해 vacancy가 , 여기서 내린다는 의미는 아님.
                //for문 안에서 내릴 수 있도록 지정해주는 것임.
                for (int j = 0; j < x; j++) {
                    if (min_x != j) { //y좌표는 같은데 x좌표가 다를땐, 내리거나 올린다.
                        if (up) ans += 'U';
                        else ans += 'D';
                        up = !up; //up&down 스위치 꼬불꼬불해야하니까.
                    }
                    if (j != x - 1) ans += 'R'; //한번하고 필수로 R, 오른쪽이 끝날때까지
                }//(여기까지 위아래로 꾸불지렁이) 다 했는데
                
                if (i != y - 2) ans += 'D'; //행이 y좌표가 하나위라면 (밑에 칸있다면) 아래로
            }
            
            
            else { //vacancy영역이 지금 아닌데
                if (vacancy) {//vacancy영역을 지난 후라면 1이라고 체크된 후라면 왼쪽부터 크게
                    //구불구불
                    
                    ans += Rep('L', x - 1);//열이 같으면 왼오로 피하고
                    ans += 'D';
                    ans += Rep('R', x - 1);
                }
                else { //아직 vacancy영역을 만나기 전이라면 무조건 오른쪽부터 시작해서 크게 구불구불
                    ans += Rep('R', x - 1);
                    ans += 'D';
                    ans += Rep('L', x - 1);
                }
                if (i != y - 2) ans += 'D'; //크게 굽히고 한번 뚝 내려오는 것까지 한set 그래야
                //새롭게 0,2,4: y의 첫(x)칸에서 시작가능.
            }
        }
    
    } cout << ans;
}

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
    cin >> y >> x;
    for (int i = 0; i < y; i++) { //x랑y는 1부터 시작하는 사용자중심숫자로 입력됐는데
        //우리는 0부터 넣었기 때문에 Solve()함수에서 -1하는 것도 그렇고 밑에 93번 줄에서 %2==1로 하는것도 그럼.
        for (int j = 0; j < x; j++) {
            cin >> arr[i][j];
            if ((i+j)%2 && min_val > arr[i][j]) {
                //0부터 시작이고 흰색에서 삭제해야하니까, 짝-짝인 경우
                //if(2%2) if(0) false인 경우.
                min_val = arr[i][j];
                min_y = i;
                min_x = j;
            }
        }
    }
    Solve();
    cout<<"\n";
    return 0;
}
