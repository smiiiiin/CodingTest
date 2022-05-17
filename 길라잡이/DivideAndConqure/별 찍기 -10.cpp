// 백준 2447 별 찍기 -10
#include <iostream>
#include <cstdio>
using namespace std;
bool map[2222][2222];

void dfs(int n, int y, int x) {
    if(n == 1) { map[y][x] = 1; return; }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue; //가운데 뻥
            dfs(n/3, y+ n/3*i, x+ n/3*j);}
    }
}

int main() {
    int n; scanf("%d", &n);
    dfs(n, 0, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j =0; j < n; j++) {
            if(map[i][j]) printf("*");
            else printf(" ");}
        printf("\n");}
    return 0;}


// 얘도 정답인데 머리아프다..
// 백준 2447 별 찍기 -10 
// !!중요: 보통 DevideAndConqure 분할정복문제는 N이 3의 거듭제곱인 경우가 많다.
#include <iostream>
using namespace std;

void dfs(int n, int y, int x){
    if((y / n)%3 == 1 && (x / n)%3 == 1) cout << ' ';
    else{
        if(n / 3 == 0) cout <<'*';
        else dfs(n/3, y,x);}}
        
int main() {
    int num; cin >> num;
    for(int y = 0; y < num; y++){
        for(int x = 0; x < num; x++) dfs(num,y,x);
        cout << '\n';}}
        
        
        
        
// 백준 2447 별 찍기 -10의 응용인 내가 만들어본 문제 아예 똑같이 그냥 찍어내기, 그 안의 그 안의 그 안의 느낌이 아니라. 
#include <iostream>
#include <cstdio>
using namespace std;
bool map[2222][2222];

void dfs(int n, int y, int x) {
    if(n == 3) {
        map[y][x]=1; map[y][x+1]=1; map[y][x+2]=1;
        map[y+1][x]=1; map[y+1][x+2]=1;
        map[y+2][x]=1; map[y+2][x+1]=1; map[y+2][x+2]=1;
        return; }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            dfs(n/3, y+ n/3*i, x+ n/3*j);}
    }
}

int main() {
    int n; scanf("%d", &n);
    dfs(n, 0, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j =0; j < n; j++) {
            if(map[i][j]) printf("*");
            else printf(" ");}
        printf("\n");}
    return 0;}

        
    
