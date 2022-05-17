// 백준 2448 별 찍기 -11
// !!중요: 보통 DevideAndConqure 분할정복문제는 N이 3의 거듭제곱인 경우가 많다.
#include <iostream>
#include <memory.h> //memset
char space[3072][6144];        //  k값이 최대 10까지인 것을 고려

void dfs(int n, int y, int x) {
    if (n == 3) {
        /*
         abcde      ab*de
         fghij      f*h*j
         klmno      ***** //삼각형 모양
         */
        space[y][x] = '*';         //c
        space[y + 1][x - 1] = '*'; //g
        space[y + 1][x + 1] = '*'; //i
        space[y + 2][x - 2] = '*'; //k
        space[y + 2][x - 1] = '*'; //l
        space[y + 2][x] = '*';     //m
        space[y + 2][x + 1] = '*'; //n
        space[y + 2][x + 2] = '*'; //o
        return;
    }        // 별 한세트
    
    dfs(n / 2, y, x);        // 별의 윗부분을
    dfs(n / 2,y + (n / 2),x - (n / 2));    // 별의 좌하단 삼각형
    dfs(n / 2, y + (n / 2), x + (n / 2));    // 별의 우하단 삼각형
}

int main() {
    int num; int i, j; scanf("%d", &num);
    memset(space, ' ', sizeof(space));

    dfs(num, 0, num-1); //대략 첫점의 x축은 그림의 중심이 됨으로 num-1로 잡는다. 

    for (i = 0; i < num; i++) {
        for (j = 0; j < num * 2; j++) printf("%c", space[i][j]);
        printf("\n");}}
