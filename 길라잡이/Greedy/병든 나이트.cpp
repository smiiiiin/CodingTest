// 백준 1783 병든 나이트
// 고딩이나 초딩때 문제풀듯 노가다+ 규칙찾기 (연필 필수) 
// 작은 단위부터 시작해서 경우의 수를 나눠야 한다.
#include <iostream>
#include <vector>
using namespace std;
int N, M;
int main(void){
    cin >> N >> M;
    if (N == 1) //세로 한칸이면 움직일 수 없다
        cout << 1 << endl;
    else if (N == 2) // 세로가 두 칸이면 2와 3번만 가능(3회까지만 움직일 수 있다)
        // 1,2면 1| 3,4면 2| 5이상이면 4 그래서 min(4,-)
             cout << min(4, (M + 1) / 2) << endl;
    
    //1, 2, 3, 4번이 적어도 한번씩은 나와야 한다
    else if (N >= 3){
             //가로가 6까지는 최대 4칸(1번, 4번, 2 or 3번)
             if (M <= 6) cout << min(4, M) << endl;

             else //2번 3번 한번씩 나머지는 1번, 4번
                cout << M - 2 << endl;}
    return 0;
}
