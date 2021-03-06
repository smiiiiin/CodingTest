// 백준 1451 직사각형으로 나누기
// 구역을 나눌땐, 첫점과 끝점을 잡는다.
// 백준 1451 직사각형으로 나누기
// 구역을 나눌땐, 첫점과 끝점을 잡는다.
#include <iostream>
#include <algorithm>//max
#include <cstdio>//scanf
using namespace std;

int Y, X;
int Num[101][101];
long long Max = -1;

int getSum(int fy, int fx, int sy, int sx) { //시작점, 끝점 <pair>로도 가능
    int sum = 0;
    for (int i = fy; i <= sy; i++) {
        for (int j = fx; j <= sx; j++) {
            sum += Num[i][j];
        }
    }
    return sum;
}


void solution() {
    cin >> Y >> X;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            scanf("%1d", &Num[y][x]);
        }
    }
    
    //1번: 目 모양
    for (int i = 0; i < Y-2 ; i++) {
        for (int j = i+1; j < Y-1 ; j++) {
            long long square1 = getSum(0, 0, i, X - 1);
            long long square2 = getSum(i + 1, 0, j, X - 1);
            long long square3 = getSum(j + 1, 0, Y - 1, X - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //2번: 皿 모양
    for (int i = 0; i < X - 2; i++) {
        for (int j = i + 1; j < X - 1; j++) {
            long long square1 = getSum(0, 0, Y - 1, i);
            long long square2 = getSum(0, i + 1, Y - 1, j);
            long long square3 = getSum(0, j + 1, Y - 1, X - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //3번: ㅓ모양
    for (int i = X - 1; i > 0; i--) {
        for (int j = 0; j < Y - 1; j++) {
            long long square1 = getSum(0, i, Y - 1, X - 1);
            long long square2 = getSum(0, 0, j, i - 1);
            long long square3 = getSum(j + 1, 0, Y - 1, i - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //4번: ㅏ모양
    for (int i = 0; i < X - 1; i++) {
        for (int j = 0; j < Y - 1; j++) {
            long long square1 = getSum(0, 0, Y - 1, i);
            long long square2 = getSum(0, i + 1, j, X - 1);
            long long square3 = getSum(j + 1, i + 1, Y - 1, X - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //5번: ㅜ 모양
    for (int i = 0; i < Y - 1; i++) {
        for (int j = 0; j < X - 1; j++) {
            long long square1 = getSum(0, 0, i, X - 1);
            long long square2 = getSum(i + 1, 0, Y - 1, j);
            long long square3 = getSum(i + 1, j + 1, Y - 1, X - 1);
            Max = max(Max, square1*square2*square3);
        }
    }

    //6번 ㅗ모양
    for (int i = Y - 1; i > 0; i--) {
        for (int j = 0; j < X - 1; j++) {
            long long square1 = getSum(i, 0, Y - 1, X - 1);
            long long square2 = getSum(0, 0, i - 1, j);
            long long square3 = getSum(0, j + 1, i - 1, X - 1);
            Max = max(Max, square1*square2*square3);
        }
    }
    cout << Max << endl;
}

int main() {
    solution();
    return 0;
}
