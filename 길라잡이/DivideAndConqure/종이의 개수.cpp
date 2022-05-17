// 백준 1780 종이의 개수
#include <iostream>
using namespace std;
int map[2200][2200]; int output[3];  // -1 0 1
 
void dfs(int n, int y, int x){
    int first = map[y][x];
    bool flag = true;
    
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(map[i][j] != first){
                //cout<<i<<j<<"\n";
                flag = false; break;}}}
                //break안하면 출력초과: 왜? 경계만 false flag박으면 되서
    
    if(flag) output[first]++;
    //n,n까지 오기까지 false아무일 없었다면 이판은 +1

//이 부분 아래 대체가능 코드 있음
    else { //그렇지 않으면 다시 분할
        for(int a = y; a < y + n; a += n/3 ){ //9로 나눴을때 구역의 첫위치마다 
            for(int b = x; b < x + n; b += n/3){
                dfs(n/3, a, b);}}}}
                 /* 처음에 (0,0,3)을 하면 못하는 친구들 8개가 생긴다
                  -   (0,3) (0,6)
                (3,0) (3,3) (3,6)
                (6,0) (6,3) (6,6) 다음과 같다. */
             
 //대체 가능 코드-1               
 /*             
    else { 
        for(int a = 0; a < 3; a ++ ){
          for(int b = 0; b < 3; b ++){
             dfs(n/3, y+ n/3*a , x+ n/3*b );}}}}
                */
                
 //대체 가능 코드-2           
 /*
    else {
        for(int a = 0; a < n; a+=n/3 ){
            for(int b = 0; b < n; b+=n/3){
                dfs(n/3, y+ a , x+ b );}}}}
                */

int main(){
    int n; cin >> n;
    
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++) cin >> map[y][x];}
    
    dfs(n, 0, 0);
    
    for(int i = -1; i < 2; i++) {cout << output[i] << endl;}
    return 0;}
